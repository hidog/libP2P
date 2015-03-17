#ifndef LIBP2P_CONFIG_H
#define LIBP2P_CONFIG_H


// common
#include <string.h>
#include <assert.h>
#include <stdio.h>


// socket
#ifdef _WIN32
#include <WinSock2.h>
#else
#	error need maintain.
#endif


#endif