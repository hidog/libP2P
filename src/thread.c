#include "thread.h"
#include "basic/config.h"
#include "data.h"
#include "basic/tools.h"
#include "socket/socket.h"
#include "thread.h"
#include "server/server.h"
#include "def/def.h"


#define MAX_THREADS 10

/***********************************************************
	P2P_create_thread
	see https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516%28v=vs.85%29.aspx
************************************************************/
P2P_thread_t	P2P_create_thread( LPSECURITY_ATTRIBUTES lp_thread_attributes,
								   SIZE_T dw_stack_size,
								   LPTHREAD_START_ROUTINE lp_start_address,
								   LPVOID lp_parameter,
								   DWORD dw_creation_flags,
								   LPDWORD lp_thread_id )
{
#ifdef _WIN32
	P2P_thread_t	thread;

	thread	=	CreateThread( lp_thread_attributes,
							  dw_stack_size,
							  lp_start_address,
							  lp_parameter,
							  dw_creation_flags,
							  lp_thread_id );

	return	thread;

	//HANDLE  hThreadArray[MAX_THREADS]; 

	/*hThreadArray[i] = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            MyThreadFunction,       // thread function name
            pDataArray[i],          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier */
#else
#error	need maintain.
#endif
}


/***********************************************************
	P2P_sleep
************************************************************/
void	P2P_sleep( P2P_clock_t time )
{
#ifdef _WIN32
	Sleep(time);
#else
#error need maintain.
#endif
}



/***********************************************************
	P2P_create_server_socket_thread
	see https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516%28v=vs.85%29.aspx
************************************************************/
int		P2P_create_server_socket_thread()
{
	static const int	index[SERVER_UDP_SKT_SIZE]	=	{ 0, 1, 2, 3, 4 };

	GlobalData_s	*p_gdata		=	P2P_get_global_data();
	int		server_skt_thr_size		=	SERVER_UDP_SKT_SIZE;
	int		i;

	p_gdata->p_server_skt_thread	=	(P2P_thread_t*)P2P_malloc( sizeof(P2P_thread_t) * server_skt_thr_size );

	//
	for( i = 0; i < server_skt_thr_size; i++ )
		*(p_gdata->p_server_skt_thread)	=	P2P_create_thread( NULL, 0, P2P_server_udp_skt_recv,
															   (void*)&index[i], 0, NULL );

	return	P2P_OK;
}



/***********************************************************
	P2P_create_skt_recv_thread
************************************************************/
int		P2P_create_skt_recv_thread()
{
	GlobalData_s	*p_gdata		=	P2P_get_global_data();
	int		server_skt_thr_size		=	SERVER_UDP_SKT_SIZE;

	//p_gdata->p_server_skt_thread	=	(P2P_thread_t*)P2P_malloc( sizeof(P2P_thread_t) * server_skt_thr_size );

	//
	P2P_create_thread( NULL, 0, P2P_skt_recv, NULL, 0, NULL );

	return	P2P_OK;
}
