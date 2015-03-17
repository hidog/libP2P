#ifndef LIBP2P_LOG_H
#define LIBP2P_LOG_H

#include "config.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ macros & defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define ALARM_LOG(MSG) \
	{ \
		printf("%s\n",MSG); \
		assert(0); \
	}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int P2P_log_init();
int P2P_log_free();


#endif