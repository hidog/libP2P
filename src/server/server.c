#include "server.h"
#include "config.h"
#include "data.h"
#include "tools.h"
#include "log.h"
#include "data.h"

#include "server/server.h"




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
