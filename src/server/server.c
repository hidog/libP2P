#include "server.h"
#include "config.h"
#include "data.h"
#include "tools.h"
#include "log.h"

#include "server/server.h"




/***********************************************************
	P2P_server_udp_skt_recv
************************************************************/
DWORD WINAPI	P2P_server_udp_skt_recv( void* lp_param )
{
	int		index	=	*(int*)lp_param;

	LOG( "server udp skt recv thread index = %d", index )



	return	0;
}
