#ifndef LIBP2P_TASK_H
#define LIBP2P_TASK_H


int		P2P_task_init();
int		P2P_task_start();
int		P2P_task_free();

int		P2P_add_task( int sid, int round, P2P_clock_t time_interval );


#endif