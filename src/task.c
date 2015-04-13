#include "task.h"

#include "def/def.h"
#include "thread.h"
#include "basic/linklist.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ static functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static DWORD WINAPI		P2P_task_main( void *lp_param );
//DWORD WINAPI	P2P_skt_recv( void* lp_param )



/***********************************************************
	P2P_init_task
************************************************************/
int		P2P_task_init()
{
	return	P2P_OK;
}


/***********************************************************
	P2P_init_task
************************************************************/
static DWORD WINAPI		P2P_task_main( void *lp_param )
{
	while(true)
	{
		printf("round.\n");
		P2P_sleep(100);
	}
}



/***********************************************************
	P2P_start_task
************************************************************/
int		P2P_task_start()
{
	P2P_create_thread( NULL, 0, P2P_task_main, NULL, 0, NULL );

	return	P2P_OK;
}




/***********************************************************
	P2P_free_task
************************************************************/
int		P2P_task_free()
{
	return	P2P_OK;
}




/***********************************************************
	P2P_free_task
************************************************************/
int		P2P_add_task( int sid, int round, P2P_clock_t time_interval )
{
	return	P2P_OK;
}
