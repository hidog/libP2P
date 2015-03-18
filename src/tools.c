#include "tools.h"

#include <time.h>
#include <stdio.h>


/***********************************************************
	P2P_socket_free
************************************************************/
void	P2P_get_date( char date_str[9] )
{
	time_t	t		=	time(0);
	struct tm *now	=	localtime(&t);

	sprintf( date_str, "%04d%02d%02d", now->tm_year+1900, now->tm_mon+1, now->tm_mday );
}
