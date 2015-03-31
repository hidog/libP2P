#ifndef LIBP2P_DATA_H
#define LIBP2P_DATA_H

#include "uuid.h"
#include "config.h"


#define		NAME_SIZE		50
#define		PASSWD_SIZE		50


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct	GlobalData
{
	// options
	bool	is_server;

	// system use
	char			*p_name;
	char			*p_passwd;
	uint8_t			my_uuid[UUID_LEN];
	P2P_in_addr_t	my_lan_ip;
	unsigned char	my_mac_addr[12];
	HANDLE			*p_server_skt_thread;

	// use for server
	P2P_socket_t	*p_udp_server_skt;

	// use for LAN
	P2P_socket_t	bcast_skt;

} GlobalData_s ;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int				P2P_data_init();
GlobalData_s*	P2P_get_global_data();

void	P2P_data_set_is_server( bool is );
bool	P2P_data_is_server();


#endif