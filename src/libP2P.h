#ifndef LIBP2P_H
#define LIBP2P_H


#ifdef __cplusplus
extern "C" {
#endif


#include "config.h"



LIBP2P_API	int		P2P_init();
LIBP2P_API	int		P2P_release();
LIBP2P_API	void	P2P_set_opt( uint32_t option );
LIBP2P_API	int		P2P_start();


#ifdef __cplusplus
} // end extern "C"
#endif


#endif