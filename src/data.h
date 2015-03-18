#ifndef LIBP2P_DATA_H
#define LIBP2P_DATA_H

#include "uuid.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct	GlobalData
{

	UUID_s	my_uuid;

} GlobalData_s ;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int		P2P_data_init();




#endif