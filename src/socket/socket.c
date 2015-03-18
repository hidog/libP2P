#include "socket.h"
#include "config.h"

#include "log.h"

#pragma comment ( lib, "Ws2_32.lib" )
#pragma comment (lib , "iphlpapi.lib")		// for iphlpapi



/***********************************************************
	P2P_socket_init
************************************************************/
int P2P_socket_init()
{
	int		i;
	unsigned char mac[12] = "";
	P2P_in_addr dest_ip;

#ifdef _WIN32
	// Initialize Winsock
	int ret = 0;
	WSADATA wsaData;
	ret = WSAStartup( MAKEWORD(2,2), &wsaData );
	if( ret != 0 ) 
	{
		ALARM_LOG( "WSAStartup failed. error = %d", ret );
		//printf("WSAStartup failed with error: %d\n", ret );
		return 1;
    }
#endif

	dest_ip.s_addr	=	inet_addr( "192.168.1.2" );

	P2P_get_mac_addr( mac, dest_ip );

	//printf("%s", mac );
	printf("Selected device has mac address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);


	return	0;
}



/***********************************************************
	P2P_socket_free
************************************************************/
int P2P_socket_free()
{
	return	0;
}


/***********************************************************
	P2P_socket_free
************************************************************/
void	P2P_get_mac_addr( unsigned char mac[12] , P2P_in_addr dest_ip )
{
#ifdef _WIN32
    DWORD	ret;
    IPAddr	src_ip;
    ULONG	mac_addr[2];
    ULONG	phy_addr_len	=	6; 
	BYTE	*b_mac_addr		=	NULL;
    int		i;
 
	//
    src_ip	=	0;
    ret		=	SendARP( (IPAddr)dest_ip.S_un.S_addr , src_ip , mac_addr , &phy_addr_len);
     
    //
    if( phy_addr_len )
    {
        b_mac_addr	=	(BYTE*)&mac_addr;
        for ( i = 0; i < (int)phy_addr_len; i++ )
            mac[i]	=	(char)b_mac_addr[i];
    }
#else
#error need maintain.
#endif
}