#ifndef LIBP2P_SERVER_H
#define LIBP2P_SERVER_H

#include "basic/config.h"

#define		SERVER_UDP_SKT_SIZE		5


#ifdef _WIN32
DWORD WINAPI	P2P_server_udp_skt_recv( void* param );
#else
void    P2P_server_udp_skt_recv( void* param );
#endif

int		P2P_open_server_socket();
int		P2P_open_udp_server_socket();

#endif