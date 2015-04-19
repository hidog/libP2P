#ifndef LIBP2P_THREAD_H
#define LIBP2P_THREAD_H

#include "basic/config.h"





P2P_thread_t	P2P_thread_create( LPSECURITY_ATTRIBUTES lp_thread_attributes, SIZE_T dw_stack_size, LPTHREAD_START_ROUTINE lp_start_address, 
								   LPVOID lp_parameter, DWORD dw_creation_flags, LPDWORD lp_thread_id );

void			P2P_thread_join( P2P_thread_t thread );

//P2P_mutex_t		P2P_create_mutex( LPSECURITY_ATTRIBUTES lp_mutex_attributes, BOOL b_initial_owner, LPCTSTR lp_name );
void			P2P_mutex_init( P2P_mutex_t *p_mutex );
void			P2P_mutex_close( P2P_mutex_t *p_mutex );
void			P2P_mutex_lock( P2P_mutex_t *p_mutex );
void			P2P_mutex_unlock( P2P_mutex_t *p_mutex );

void			P2P_sleep( P2P_clock_t time );


int		P2P_create_server_socket_thread();
int		P2P_create_skt_recv_thread();


#endif