#include "task.h"

#include "basic/log.h"
#include "def/def.h"
#include "thread.h"
#include "basic/linklist.h"
#include "basic/config.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ static functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static DWORD WINAPI		P2P_task_main( void *lp_param );
static P2P_clock_t		P2P_task_loop();
static bool				P2P_task_run( LLTask_s *p_task );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global variable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static bool		_is_task_main_loop;			// control the task main loop.

static P2P_thread_t		_g_main_thread;
static LinkList_s		*_gp_linklist;		// if modify to non-static variable, be careful thah the name will be conflict.
static P2P_mutex_t		_g_mutex;



/***********************************************************
	P2P_init_task
************************************************************/
int		P2P_task_init()
{
	_gp_linklist	=	P2P_LL_init( LL_TYPE_LLTask );
	//_g_mutex		=	P2P_create_mutex( NULL, false, "P2P_task");
	P2P_mutex_init( &_g_mutex );
	_is_task_main_loop	=	false;
	_g_main_thread	=	THREAD_INIT_VALUE;

	return	P2P_OK;
}


/***********************************************************
	P2P_task_run
************************************************************/
static bool		P2P_task_run( LLTask_s *p_task )
{
	printf("p_task = %d\n", p_task->sid );

	if( p_task == NULL )
	{
		ALARM_LOG("p_task is NULL")
		return	false;
	}

	switch(p_task->task_type)
	{
		case TASK_LAN_SEARCH:
			break;
		default:
			ALARM_LOG(" ")
	}

	return	true;
}


/***********************************************************
	P2P_task_loop
************************************************************/
static P2P_clock_t		P2P_task_loop()
{
	P2P_clock_t		start_clock,	stop_clock;
	LLTask_s		*p_tail;
	LLTask_s		*p_node;
	bool			is_success;

	start_clock		=	P2P_clock();

	P2P_mutex_lock(&_g_mutex);
	P2P_LL_set_node_to_tail(_gp_linklist);
	p_tail	=	P2P_LL_get_node_LLTask(_gp_linklist);
	P2P_mutex_unlock(&_g_mutex);

	P2P_LL_set_node_to_head(_gp_linklist);
	p_node	=	P2P_LL_get_node_LLTask(_gp_linklist);

	while(true)
	{
		if( p_node == NULL )
			break;

		// remove
		if( p_node->round == 0 )
		{
			if( P2P_LL_is_tail_LLTask(_gp_linklist,p_node) == true )
			{
				P2P_mutex_lock(&_g_mutex);
				P2P_LL_remove_node(_gp_linklist);
				P2P_mutex_unlock(&_g_mutex);
			}
			else
				P2P_LL_remove_node(_gp_linklist);
		}
		else
		{
			is_success	=	P2P_task_run( p_node );
			if( is_success )
				p_node->round--;
		}

		if( p_node == p_tail )
			break;
	}

	stop_clock		=	P2P_clock();

	return	stop_clock - start_clock;
}



/***********************************************************
	P2P_init_task
************************************************************/
static DWORD WINAPI		P2P_task_main( void *lp_param )
{
	P2P_clock_t		clock;

	while( _is_task_main_loop )
	{
		clock	=	P2P_task_loop();
		printf("round clock = %u.\n", clock );
		if( clock < 10 )
			P2P_sleep( 10-clock );
	}

	return	1;
}



/***********************************************************
	P2P_start_task
************************************************************/
int		P2P_task_start()
{
	_is_task_main_loop	=	true;
	_g_main_thread	=	P2P_thread_create( NULL, 0, P2P_task_main, NULL, 0, NULL );

	return	P2P_OK;
}




/***********************************************************
	P2P_free_task
************************************************************/
int		P2P_task_free()
{
	_is_task_main_loop	=	false;
	P2P_thread_join( _g_main_thread );

	_gp_linklist	=	P2P_LL_free(_gp_linklist);
	P2P_mutex_close(&_g_mutex);

	return	P2P_OK;
}




/***********************************************************
	P2P_free_task
************************************************************/
int		P2P_task_add( int sid, TASK_TYPE task_type, int round, P2P_clock_t time_interval )
{
	LLTask_s	task_data;

	task_data.sid	=	sid;
	task_data.round	=	round;
	task_data.task_type		=	task_type;
	task_data.time_interval		=	time_interval;

	P2P_mutex_lock( &_g_mutex );
	P2P_LL_pushback_LLTask( _gp_linklist, &task_data );
	P2P_mutex_unlock( &_g_mutex );

	return	P2P_OK;
}
