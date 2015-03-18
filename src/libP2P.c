#include "libP2P.h"

#include "socket/socket.h"
#include "log.h"
#include "tools.h"
#include "config.h"
#include "data.h"


/***********************************************************
	P2P_init
************************************************************/
int P2P_init()
{
	LOG( "P2P_init" )

	P2P_srand( (unsigned int)time(0) );

	// init log
	P2P_log_init();

	// init socket.
	P2P_socket_init();

	// init data
	P2P_data_init();

	return 0;
}



/***********************************************************
	P2P_free
************************************************************/
int P2P_free()
{
	return 0;
}