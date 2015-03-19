#ifndef LIBP2P_UUID_H
#define LIBP2P_UUID_H

#include "config.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ define ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define		UUID_LEN		16
#define		UUID_STR_LEN	37

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*typedef struct	UUID
{
	uint8_t		uuid[UUID_LEN];
} UUID_s;*/





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void	P2P_uuid_generate( uint8_t *p_uuid, uint8_t *exp_str ); 
void	P2P_uuid_mac_expd( uint8_t *mac, uint8_t *exp_str );
void	P2P_uuid_to_str( uint8_t *p_uuid, char *p_uuid_str );


#endif