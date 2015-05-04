#include "tools.h"
#include "log.h"
#include "config.h"



/***********************************************************
	P2P_socket_free
************************************************************/
void	P2P_get_date( char date_str[9] )
{
	time_t	t		=	time(0);
	struct tm *now	=	localtime(&t);

	sprintf( date_str, "%04d%02d%02d", now->tm_year+1900, now->tm_mon+1, now->tm_mday );
}


/***********************************************************
	P2P_srand
************************************************************/
void	P2P_srand( unsigned int seed )
{
	srand(seed);
}


/***********************************************************
	P2P_uint8_rand
************************************************************/
uint8_t		P2P_uint8_rand()
{
	return	rand() % 256; // 0 ~ 255
}


/***********************************************************
	P2P_free
************************************************************/
void*	P2P_free( void *ptr )
{
	free(ptr);
	return	NULL;
}



/***********************************************************
	P2P_malloc
************************************************************/
#ifndef P2P_CRT_MEMORY_LEAK
void*		P2P_malloc( int size )
{
	void	*ptr	=	NULL;

	ptr	=	malloc(size);
	if( ptr == NULL )
	{
		ALARM_LOG("malloc error.")
		return	NULL;
	}

	return	ptr;
}
#endif



/***********************************************************
	P2P_clock
	linux : http://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
	windows: http://zengzn.blogspot.tw/2008/01/vc-getsystemtime.html
	sec :   1000
	min :   60*1000 = 60000
	hour :  60 * 60000 = 3600000
	day :   24 * 3600000 = 86400000
	month : 
	year :  
************************************************************/
P2P_clock_t	P2P_clock()
{
#ifdef _WIN32
	// note: 用GetSystemTime可以做到跟gettimeofday相同的效果,但是要計算閏年等等
	/*SYSTEMTIME		time;
	P2P_clock_t		clock;
	int		year;
	GetSystemTime( &time );
	year	=	time.wYear * 365 + time.wYear
	//printf("dat = %d\n",time.wDay);
	clock	=	(time.wYear - 1970)*year + 
				time.wSecond*1000 + time.wMilliseconds;
	return	clock;*/
	return	GetTickCount();
#else
    struct timeval  tp;
    P2P_clock_t     clock;
    gettimeofday( &tp, NULL );
    
    clock   =   tp.tv_sec*1000 + tp.tv_usec/1000; //get current timestamp in milliseconds

    return  clock;
#endif
}



