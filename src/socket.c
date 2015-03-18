#include "socket.h"
#include "config.h"
#include "log.h"

#pragma comment ( lib, "Ws2_32.lib" )




/***********************************************************
	P2P_socket_init
************************************************************/
int P2P_socket_init()
{
#ifdef _WIN32
	// Initialize Winsock
	int ret = 0;
	WSADATA wsaData;
	ret = WSAStartup( MAKEWORD(2,2), &wsaData );
	if( ret != 0 ) 
	{
		ALARM_LOG("WSAStartup failed");
		//printf("WSAStartup failed with error: %d\n", ret );
		return 1;
    }
#endif

	return	0;
}



/***********************************************************
	P2P_socket_free
************************************************************/
int P2P_socket_free()
{
	return	0;
}