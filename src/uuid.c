#include "uuid.h"

#include "tools.h"





/***********************************************************
	P2P_uuid_generate
************************************************************/
void	P2P_uuid_generate( UUID_s *p_uuid )
{
	int		i;

	assert( p_uuid != NULL );

	for( i = 0; i < 16; i++ )
		p_uuid->uuid[i]		=	P2P_uint8_rand();

}
