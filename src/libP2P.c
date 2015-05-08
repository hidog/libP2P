#include "libP2P.h"
#include "data.h"
#include "thread.h"

#include "socket/socket.h"

#include "server/server.h"

#include "module/lan/lan.h"

#include "def/def.h"
#include "basic/log.h"
#include "basic/tools.h"
#include "basic/config.h"
#include "task.h"


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

	// init task
	P2P_task_init();

	return 0;
}



/***********************************************************
	P2P_release
************************************************************/
int P2P_release()
{
	P2P_task_free();

	return 0;
}




/***********************************************************
	P2P_lan_search
************************************************************/
int		P2P_lan_search()
{
	P2P_send_lan_search();

	return	P2P_OK;
}



/***********************************************************
	P2P_set_name
************************************************************/
int		P2P_set_name( const char *name )
{
	GlobalData_s	*p_gdata	=	P2P_get_global_data();
	unsigned int	len;
	//bool	is	=	false;

	if( p_gdata->p_name != NULL )
	{
		WARNING_LOG( "already set name." )
		return	P2P_ERROR;
	}

	// check name format.
	len		=	strlen(name);
	if( len >= NAME_SIZE )
	{
		ALARM_LOG( "name size too large." )
		return	P2P_ERROR;
	}

	// set name
	p_gdata->p_name	=	(char*)P2P_malloc(NAME_SIZE);
	memset( p_gdata->p_name, 0, NAME_SIZE );
	memcpy( p_gdata->p_name, name, len );

	return	P2P_OK;
}



/***********************************************************
	P2P_set_passwd
************************************************************/
int		P2P_set_passwd( const char *passwd )
{
	GlobalData_s	*p_gdata	=	P2P_get_global_data();
	unsigned int	len;
	//bool	is	=	false;

	if( p_gdata->p_passwd != NULL )
	{
		WARNING_LOG( "already set passwd." )
		return	P2P_ERROR;
	}

	// check name format.
	len		=	strlen(passwd);
	if( len >= PASSWD_SIZE )
	{
		ALARM_LOG( "passwd size too large." )
		return	P2P_ERROR;
	}

	// set passwd
	p_gdata->p_passwd	=	(char*)P2P_malloc(NAME_SIZE);
	memset( p_gdata->p_passwd, 0, NAME_SIZE );
	memcpy( p_gdata->p_passwd, passwd, len );

	return	P2P_OK;
}



/***********************************************************
	P2P_set_opt
************************************************************/
void	P2P_set_opt( uint32_t option )
{
	if( MASK_MACRO( option, P2P_OPT_ENABLE_SERVER ) != 0 )
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

	P2P_init_broadcast_socket();
	P2P_create_skt_recv_thread();
	P2P_task_start();
	
	return	0;
}
