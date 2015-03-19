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
	LOG("socket init.")

	//int		i;
	//unsigned char	mac[12] = "";
	//P2P_in_addr_t	my_lan_ip;

#ifdef _WIN32
	P2P_winsock_init();
#endif

	/*P2P_get_my_lan_ip( &my_lan_ip );
	my_lan_ip.s_addr	=	inet_addr( inet_ntoa(my_lan_ip) ); //inet_addr( "192.168.1.2" );

	P2P_get_mac_addr( mac, my_lan_ip );

	//printf("%s", mac );
	printf("Selected device has mac address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);*/


	return	0;
}




/***********************************************************
	P2P_winsock_init
************************************************************/
#ifdef _WIN32
int		P2P_winsock_init()
{
	// Initialize Winsock
	int		ret	=	0;
	WSADATA	wsaData;

	ret	=	WSAStartup( MAKEWORD(2,2), &wsaData );
	if( ret != 0 ) 
	{
		ALARM_LOG( "WSAStartup failed. error = %d", ret );
		//printf("WSAStartup failed with error: %d\n", ret );
		return	-1;
    }

	return	0;
}
#endif




/***********************************************************
	P2P_socket_free
************************************************************/
int P2P_socket_free()
{
	return	0;
}


/***********************************************************
	P2P_get_mac_addr
************************************************************/
void	P2P_get_mac_addr( unsigned char mac[12] , P2P_in_addr_t dest_ip )
{
#ifdef _WIN32
	const int	mac_len	=	12;

    int		i;
    DWORD	ret;
    IPAddr	src_ip;
    ULONG	mac_addr[2];
    ULONG	phy_addr_len	=	6; 
	BYTE	*b_mac_addr		=	NULL;

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
	else
		memset( mac, 0, mac_len );
#else
#error need maintain.
#endif
}




/***********************************************************
	P2P_get_my_lan_ip
************************************************************/
int		P2P_get_my_lan_ip( P2P_in_addr_t *p_my_lan_ip )
{
    char	str[80];
	int		ret;
	int		i;
	P2P_hostent_t	*phe	=	NULL; 
    P2P_in_addr_t	addr;

	ret	=	gethostname( str, sizeof(str) );
	assert( ret != SOCKET_ERROR );

    phe	=	gethostbyname(str);
	assert( phe != NULL );

	// can get multi ip, but only get the first.
    //for ( i = 0; phe->h_addr_list[i] != 0; i++ ) 
       // memcpy( p_my_lan_ip, phe->h_addr_list[i], sizeof(P2P_in_addr_t) );
    memcpy( p_my_lan_ip, phe->h_addr_list[0], sizeof(P2P_in_addr_t) );

    return 0;
}




