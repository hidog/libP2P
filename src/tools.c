#include "tools.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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
