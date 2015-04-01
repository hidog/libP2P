#include "uuid.h"

#include "tools.h"
#include "log.h"




/***********************************************************
	P2P_uuid_generate
************************************************************/
void	P2P_uuid_generate( uint8_t *p_uuid, uint8_t *exp_str )
{
	static unsigned char	chaos	=	1;

	int		i;

	P2P_srand( (unsigned int)time(0) );

	assert( p_uuid != NULL );

	for( i = 0; i < 16; i++ )
		p_uuid[i]		=	P2P_uint8_rand() ^ exp_str[i] ^ chaos;

	chaos	+=	p_uuid[0] + p_uuid[2] + p_uuid[3] + p_uuid[13];
}



/***********************************************************
	P2P_uuid_mac_expd
************************************************************/
void	P2P_uuid_mac_expd( uint8_t *mac, uint8_t *exp_str )
{
	const int	mac_len		=	12;
	const int	exp_len		=	16;

	memcpy( exp_str, mac, 12 );

	exp_str[12]		=	(mac[2] << 3) | (mac[7] >> 5);
	exp_str[13]		=	(mac[6] << 1) | (mac[1] >> 7);
	exp_str[14]		=	(mac[3] << 4) | (mac[4] >> 4);
	exp_str[15]		=	mac[0] ^ mac[1] ^ mac[2] ^ mac[3] ^ mac[4];
}


/***********************************************************
	P2P_print_uuid
	format: 550e8400-e29b-41d4-a716-446655440000
************************************************************/
void	P2P_uuid_to_str( uint8_t *p_uuid, char *p_uuid_str )
{
	//sprintf( uuid_str, "%.2X%.2X-%.2X-%.2X-%.2X-%.2X", tmp_mac[0], tmp_mac[1], tmp_mac[2], tmp_mac[3], tmp_mac[4], tmp_mac[5] );

	const uint8_t	uuid_mask	=	0x0F;
	//uint8_t		*p_uuid		=	&uuid.uuid[0];
	int			i;

	//uuid_str[0]		=	uuid[0] & uuid_mask;
	//uuid_str[1]		=	(uuid[0] >> 4) & uuid_mask;

	//
	for( i = 0; i < 8; i++ )
		p_uuid_str[i]	=	i%2 == 0 ? p_uuid[i/2]&uuid_mask : p_uuid[i/2] >> 4;
	p_uuid_str[i++]	=	'-';
	//
	for( ; i < 13; i++ )
		p_uuid_str[i]	=	i%2 == 1 ? p_uuid[(i-1)/2]&uuid_mask : p_uuid[(i-1)/2] >> 4;
	p_uuid_str[i++]	=	'-';
	//
	for( ; i < 18; i++ )
		p_uuid_str[i]	=	i%2 == 0 ? p_uuid[(i-2)/2]&uuid_mask : p_uuid[(i-2)/2] >> 4;
	p_uuid_str[i++]	=	'-';
	//
	for( ; i < 23; i++ )
		p_uuid_str[i]	=	i%2 == 1 ? p_uuid[(i-3)/2]&uuid_mask : p_uuid[(i-3)/2] >> 4;
	p_uuid_str[i++]	=	'-';
	//
	for( ; i < 36; i++ )
		p_uuid_str[i]	=	i%2 == 0 ? p_uuid[(i-4)/2]&uuid_mask : p_uuid[(i-4)/2] >> 4;
	p_uuid_str[36]	=	'\0';

	// turn to charactor
	for( i = 0; i < UUID_STR_LEN - 1; i++ )
	{
		if( p_uuid_str[i] >= 0 && p_uuid_str[i] <= 9 )
			p_uuid_str[i]		+=	'0';
		else if( p_uuid_str[i] >= 10 && p_uuid_str[i] <= 15 )
			p_uuid_str[i]		+=	'a' - 10;
	}
}
