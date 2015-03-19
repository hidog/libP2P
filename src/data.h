#ifndef LIBP2P_DATA_H
#define LIBP2P_DATA_H

#include "uuid.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct	GlobalData
{

	//UUID_s			my_uuid;
	uint8_t			my_uuid[UUID_LEN];
	P2P_in_addr_t	my_lan_ip;
	unsigned char	my_mac_addr[12];

} GlobalData_s ;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int		P2P_data_init();




#endif