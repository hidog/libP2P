#include "libP2P.h"

#include "socket/socket.h"
#include "log.h"
#include "tools.h"
#include "config.h"
#include "data.h"
#include "def.h"
#include "thread.h"


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
int P2P_release()
{
	return 0;
}



/***********************************************************
	P2P_set_opt
************************************************************/
void	P2P_set_opt( uint32_t option )
{
	if( option & P2P_OPT_ENABLE_SERVER != 0 )
		P2P_data_set_is_server(true);

}



/***********************************************************
	P2P_set_opt
************************************************************/
int		P2P_start()
{
	if( P2P_data_is_server() == true )
	{
		P2P_open_server_socket();
		P2P_create_server_socket_thread();
	}


	return	0;
}
