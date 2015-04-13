#ifndef LIBP2P_SERVER_H
#define LIBP2P_SERVER_H

#include "basic/config.h"

#define		SERVER_UDP_SKT_SIZE		5


DWORD WINAPI	P2P_server_udp_skt_recv( void* lp_param );


int		P2P_open_server_socket();
int		P2P_open_udp_server_socket();

#endif