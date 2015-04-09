#ifndef LIBP2P_TOOLS_H
#define LIBP2P_TOOLS_H

#include "config.h"



void		P2P_get_date( char date_str[9] );
void		P2P_srand( unsigned int seed );
uint8_t		P2P_uint8_rand();

#ifndef P2P_CRT_MEMORY_LEAK
void*		P2P_malloc( int size );
#endif
void*		P2P_free( void *ptr );


#endif