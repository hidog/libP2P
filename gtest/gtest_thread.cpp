#include "gtest_thread.h"


#include "gtest/gtest.h"

#define		GTEST_MAX_THREAD	10
#define		GTEST_ADD_TIMES		100

int		gtest_thread_count	=	0;
P2P_mutex_t		gtest_thread_mutex;


DWORD WINAPI	gtest_thread_func_1( void *lp_param )
{
	int		i;
	int		a;

	P2P_sleep(1000);

	for( i = 0; i < GTEST_ADD_TIMES; i++ )
	{
		//printf("gtest_thread_count = %d\n",gtest_thread_count);
		P2P_mutex_lock(&gtest_thread_mutex);
		a	=	gtest_thread_count;
		a++;
		gtest_thread_count	=	a;
		P2P_mutex_unlock(&gtest_thread_mutex);
	}

	return	0;
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST( thread, general )
{
//P2P_thread_t	P2P_create_thread( LPSECURITY_ATTRIBUTES lp_thread_attributes, SIZE_T dw_stack_size, LPTHREAD_START_ROUTINE lp_start_address, 
	int		i;
	P2P_thread_t	thread[GTEST_MAX_THREAD];

	P2P_mutex_init(&gtest_thread_mutex);

	for( i = 0; i < GTEST_MAX_THREAD; i++ )
		thread[i]	=	P2P_thread_create( NULL, 0, gtest_thread_func_1, NULL, 0, NULL );
		//P2P_create_thread( NULL, 0, P2P_task_main, NULL, 0, NULL );

	for( i = 0; i < GTEST_MAX_THREAD; i++ )
		P2P_thread_join( thread[i] );

	EXPECT_EQ( gtest_thread_count, GTEST_ADD_TIMES*GTEST_MAX_THREAD );

	P2P_mutex_close(&gtest_thread_mutex);
}