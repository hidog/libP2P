#ifndef LIBP2P_DATA_H
#define LIBP2P_DATA_H

#include "uuid.h"
#include "config.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct	GlobalData
{
	// options
	bool	is_server;

	//
	uint8_t			my_uuid[UUID_LEN];
	P2P_in_addr_t	my_lan_ip;
	unsigned char	my_mac_addr[12];

} GlobalData_s ;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int		P2P_data_init();

void	P2P_data_set_is_server( bool is );
bool	P2P_data_is_server();


#endif