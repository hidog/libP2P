#ifndef LIBP2P_SOCKET_H
#define LIBP2P_SOCKET_H

#include "config.h"


int		P2P_socket_init();
int		P2P_socket_free();
void	P2P_get_mac_addr( unsigned char mac[12] , P2P_in_addr dest_ip );


#endif