#include "thread.h"
#include "basic/config.h"
#include "data.h"
#include "basic/tools.h"
#include "socket/socket.h"
#include "thread.h"
#include "server/server.h"
#include "def/def.h"
#include "basic/log.h"





/***********************************************************
	P2P_create_thread
	see https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516%28v=vs.85%29.aspx
    linux : http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html
            http://systw.net/note/af/sblog/more.php?id=251
************************************************************/
#ifdef _WIN32
P2P_thread_t	P2P_thread_create( LPSECURITY_ATTRIBUTES lp_thread_attributes,
								   SIZE_T dw_stack_size,
								   LPTHREAD_START_ROUTINE lp_start_address,
								   LPVOID lp_parameter,
								   DWORD dw_creation_flags,
								   LPDWORD lp_thread_id )
#else
P2P_thread_t    P2P_thread_create( pthread_t *thr, const pthread_attr_t *attr, void *(*func)( void* ), void *arg )
#endif
{
	P2P_thread_t	thread;
#ifdef _WIN32
	thread	=	CreateThread( lp_thread_attributes,
							  dw_stack_size,
							  lp_start_address,
							  lp_parameter,
							  dw_creation_flags,
							  lp_thread_id );

	if( thread == NULL )
		ALARM_LOG("create thread fail.")

	//HANDLE  hThreadArray[MAX_THREADS]; 

	/*hThreadArray[i] = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            MyThreadFunction,       // thread function name
            pDataArray[i],          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier */
#else
    pthread_create( &thread, NULL, func, arg );
#endif
    
    return  thread;
}



/***********************************************************
	P2P_init_mutex
	windows use critical section to get better performance.
	windows also have mutex. see MSDN. CreateMutex.
    https://computing.llnl.gov/tutorials/pthreads/#Mutexes
************************************************************/
void	P2P_mutex_init( P2P_mutex_t *p_mutex )
{
#ifdef _WIN32
	InitializeCriticalSection(p_mutex);
#else
    pthread_mutex_init( p_mutex, NULL );
#endif
}



/***********************************************************
	P2P_create_thread
	An mutex example.
************************************************************/
/*P2P_mutex_t		P2P_create_mutex( LPSECURITY_ATTRIBUTES lp_mutex_attributes, BOOL b_initial_owner, LPCTSTR lp_name )
{
#ifdef _WIN32
	P2P_mutex_t		mutex;

	mutex	=	CreateMutex( lp_mutex_attributes, b_initial_owner, lp_name );

	if( mutex == NULL )
		ALARM_LOG("mutex create fail.")

	return	mutex;

	//return	CreateMutex( lp_mutex_attributes, b_initial_owner, lp_name );
#else
#error need maintain.
#endif
}*/



/***********************************************************
	P2P_mutex_lock
	see https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516%28v=vs.85%29.aspx
************************************************************/
void	P2P_mutex_lock( P2P_mutex_t *p_mutex )
{
#ifdef _WIN32

	/*DWORD	dw_wait_result;
	dw_wait_result	=	WaitForSingleObject( mutex, INFINITE );
	if( dw_wait_result == WAIT_ABANDONED )
	{
		WARNING_LOG("mutex wait abandoned")
		return	P2P_ERROR;
	}
	return	P2P_OK;*/

	EnterCriticalSection( p_mutex );

#else
    pthread_mutex_lock( p_mutex );
#endif
}




/***********************************************************
	P2P_thread_join
************************************************************/
void	P2P_thread_join( P2P_thread_t thread )
{
#ifdef _WIN32
	WaitForSingleObject( thread, INFINITE );
#else
    pthread_join( thread, NULL );
#endif
}



/***********************************************************
	P2P_mutex_unlock
************************************************************/
void	P2P_mutex_unlock( P2P_mutex_t *p_mutex )
{
#ifdef _WIN32
	/*BOOL	is;
	is	=	ReleaseMutex(mutex);
	if( is == 0 )
		WARNING_LOG("mutex unlock fail.")*/
	LeaveCriticalSection( p_mutex );
#else
    pthread_mutex_unlock( p_mutex );
#endif
}




/***********************************************************
	P2P_close_mutex
************************************************************/
void	P2P_mutex_close( P2P_mutex_t *p_mutex )
{
#ifdef _WIN32
	/*BOOL	is;
	is	=	CloseHandle(mutex);
	if( is == 0 )
		ALARM_LOG("close mutex fail.")*/
	DeleteCriticalSection(p_mutex);
#else
    phtread_mutex_destroy(p_mutex);
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
    usleep( time*1000 );
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
#ifdef _WIN32
		*(p_gdata->p_server_skt_thread)	=	P2P_thread_create( NULL, 0, P2P_server_udp_skt_recv,
															   (void*)&index[i], 0, NULL );
#else
        *(p_gdata->p_server_skt_thread)	=	P2P_thread_create( NULL, NULL, P2P_server_udp_skt_recv, NULL);
#endif

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
#ifdef _WIN32
	P2P_thread_create( NULL, 0, P2P_skt_recv, NULL, 0, NULL );
#else
    P2P_thread_create( NULL, NULL, P2P_skt_recv, NULL );
#endif
	return	P2P_OK;
}
