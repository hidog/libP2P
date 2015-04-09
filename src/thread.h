#ifndef P2P_THREAD_H
#define P2P_THREAD_H

#include "basic/config.h"
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

//#define MAX_THREADS 3
//#define BUF_SIZE 255



P2P_thread_t	P2P_create_thread( LPSECURITY_ATTRIBUTES lp_thread_attributes, SIZE_T dw_stack_size, LPTHREAD_START_ROUTINE lp_start_address, 
								   LPVOID lp_parameter, DWORD dw_creation_flags, LPDWORD lp_thread_id );

int		P2P_create_server_socket_thread();
int		P2P_create_skt_recv_thread();


#endif