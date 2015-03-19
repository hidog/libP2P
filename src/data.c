#include "data.h"
#include "socket/socket.h"
#include "log.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global variable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static GlobalData_s		*_gp_data	=	NULL;




/***********************************************************
	P2P_data_init
************************************************************/
int		P2P_data_init()
{
	unsigned char	*tmp_mac	=	NULL;
	unsigned char	exp_str[UUID_LEN];
	char	uuid_str[UUID_STR_LEN];

	_gp_data	=	(GlobalData_s*)malloc( sizeof(GlobalData_s) );

	//
	P2P_get_my_lan_ip( &_gp_data->my_lan_ip );
	P2P_get_mac_addr( _gp_data->my_mac_addr, _gp_data->my_lan_ip );
	tmp_mac		=	&_gp_data->my_mac_addr[0];
	LOG( "ip = %s", inet_ntoa(_gp_data->my_lan_ip) )
	LOG( "mac addr = %.2X-%.2X-%.2X-%.2X-%.2X-%.2X", tmp_mac[0], tmp_mac[1], tmp_mac[2], tmp_mac[3], tmp_mac[4], tmp_mac[5] );

	//
	P2P_uuid_mac_expd( tmp_mac, exp_str );
	P2P_uuid_generate( &_gp_data->my_uuid, exp_str );
	P2P_uuid_to_str( _gp_data->my_uuid, uuid_str );
	LOG( "my uuid = %s", uuid_str );


	return	0;
}
