#ifndef LIBP2P_TASK_H
#define LIBP2P_TASK_H

#include "basic/config.h"





int		P2P_task_init();
int		P2P_task_start();
int		P2P_task_free();

int		P2P_task_add( int sid, TASK_TYPE task_type, int round, P2P_clock_t time_interval );


#endif