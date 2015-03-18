#ifndef LIBP2P_LOG_H
#define LIBP2P_LOG_H

#include "config.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ macros & defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define ALARM_LOG(...) \
	{ \
		printf("[%s] [%s] [%d] msg: ", __FILE__, __FUNCTION__, __LINE__ ); \
		printf(__VA_ARGS__); \
		printf("\n"); \
		assert(0); \
	}

#define LOG(...) \
	{ \
		printf("[%s] [%s] [%d] ", __FILE__, __FUNCTION__, __LINE__ ); \
		printf(__VA_ARGS__); \
		printf("\n"); \
		P2P_log_file(__VA_ARGS__); \
	}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int		P2P_log_init();
int		P2P_log_free();
int		P2P_log_file( const char *format, ... );


#endif