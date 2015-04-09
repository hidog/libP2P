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