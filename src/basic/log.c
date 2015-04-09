#include "log.h"

#include "tools.h"
#include <stdio.h>
#include <stdarg.h>



/***********************************************************
	P2P_log_init
************************************************************/
int P2P_log_init()
{
	LOG( "log test. %d %s %f", 4, "123", 3.441 );
	return	0;
}


/***********************************************************
	P2P_log_free
************************************************************/
int P2P_log_free()
{
	return	0;
}



/***********************************************************
	P2P_log_file
************************************************************/
int		P2P_log_file( const char *format, ... )
{
	char	date[9];
	char	file_name[30];
	FILE	*p;
	va_list args;

	return 0; // if you want log to file, mark this line.

	// get date.
	P2P_get_date(date);

	// set file name
	sprintf( file_name, "log_%s.txt", date );

	// open file
	p	=	fopen( file_name, "a+" );

	// write data.
	va_start ( args, format );
	vfprintf ( p, format, args );
	//perror (format);
	va_end ( args );
	fprintf( p, "\n" );

	// close file
	fclose(p);

	return	0;
}
