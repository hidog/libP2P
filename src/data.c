#include "data.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global variable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static GlobalData_s		*_gp_data	=	NULL;




/***********************************************************
	P2P_data_init
************************************************************/
int		P2P_data_init()
{
	_gp_data	=	(GlobalData_s*)malloc( sizeof(GlobalData_s) );

	P2P_uuid_generate( &_gp_data->my_uuid );

	return	0;
}
