#include "server.h"
#include "config.h"
#include "data.h"
#include "tools.h"
#include "log.h"
#include "data.h"

#include "server/server.h"



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global variable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const static int	_udp_server_port[SERVER_UDP_SKT_SIZE]	=	{ 1552,	6687, 13357, 28679, 39994 };



/***********************************************************
	P2P_open_udp_server_socket
************************************************************/
int		P2P_open_udp_server_socket()
{
	int		err,	i;
    P2P_sockaddr_in_t	server_addr_in; 
	GlobalData_s*		p_gdata		=	NULL;

	//
	p_gdata		=	P2P_get_global_data();
	if( p_gdata->p_udp_server_skt != NULL )
		p_gdata->p_udp_server_skt	=	(P2P_socket_t*)P2P_free( p_gdata->p_udp_server_skt );
	p_gdata->p_udp_server_skt	=	(P2P_socket_t*)P2P_malloc( sizeof(P2P_socket_t) * SERVER_UDP_SKT_SIZE );	

	//
	for( i = 0; i < SERVER_UDP_SKT_SIZE; i++ )
	{          
		// Create a socket
		p_gdata->p_udp_server_skt[i]	=	socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
		if( p_gdata->p_udp_server_skt[i] == INVALID_SOCKET)
		{
			ALARM_LOG( "Could not create socket: %d" , WSAGetLastError() );
			return	-1;
		}
     
		//Prepare the sockaddr_in structure
		server_addr_in.sin_family		=	AF_INET;
		server_addr_in.sin_addr.s_addr	=	INADDR_ANY;
		server_addr_in.sin_port			=	htons( _udp_server_port[i] );
     
		//Bind
		err		=	bind( p_gdata->p_udp_server_skt[i], (P2P_sockaddr_t*)&server_addr_in, sizeof(server_addr_in) ); 
		if( err == SOCKET_ERROR )
		{
			ALARM_LOG("Bind failed with error code: %d" , WSAGetLastError());
			return	-1;
		}
	}

#if 0
    //keep listening for data
    while(1)
    {
        printf("Waiting for data...");
        fflush(stdout);
         
        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);
         
        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
        {
            printf("recvfrom() failed with error code : %d" , WSAGetLastError());
            exit(EXIT_FAILURE);
        }
         
        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);
         
        //now reply the client with the same data
        if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
        {
            printf("sendto() failed with error code : %d" , WSAGetLastError());
            exit(EXIT_FAILURE);
        }
    }
 
    closesocket(s);
    WSACleanup();
#endif

}




/***********************************************************
	P2P_open_server_socket
************************************************************/
int		P2P_open_server_socket()
{
	int		err	=	0;

	err		=	P2P_open_udp_server_socket();
	if( err < 0 )
		ALARM_LOG("open udp server socket fail.")
     
    return 0;
}


/***********************************************************
	P2P_server_udp_skt_recv
	http://www.binarytides.com/udp-socket-programming-in-winsock/
	http://www.binarytides.com/winsock-socket-programming-tutorial/
	http://www.binarytides.com/code-tcp-socket-server-winsock/

	https://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx

	error code see https://msdn.microsoft.com/en-us/library/windows/desktop/ms740668%28v=vs.85%29.aspx

	https://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx   socket 
************************************************************/
DWORD WINAPI	P2P_server_udp_skt_recv( void* lp_param )
{
	GlobalData_s		*p_gdata	=	P2P_get_global_data();
	P2P_sockaddr_in_t	addr_in;

	int		index	=	*(int*)lp_param;
	char	buf[1500];
	int		buf_len	=	1500;
	int		err;
	int		recv_len;
	recv_len	=	sizeof(addr_in) ;

	LOG( "server udp skt recv thread index = %d", index )

    //keep listening for data
    while(1)
    {        
        //clear the buffer by filling null, it might have previously received data
        memset( buf, 0, buf_len);
         
        //try to receive some data, this is a blocking call
		err		=	recvfrom( p_gdata->p_udp_server_skt[index], buf, buf_len, 0, (P2P_sockaddr_t*)&addr_in, &recv_len );
        if( err == SOCKET_ERROR )
            ALARM_LOG( "recvfrom() failed with error code : %d" , WSAGetLastError() )
		else
			LOG( "recv = %s", buf );
         
        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(addr_in.sin_addr), ntohs(addr_in.sin_port));
        printf("Data: %s\n" , buf);
         
        //now reply the client with the same data
        /*if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
        {
            printf("sendto() failed with error code : %d" , WSAGetLastError());
            exit(EXIT_FAILURE);
        }*/
    }
	return	0;
}
