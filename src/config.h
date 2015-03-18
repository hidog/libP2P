#ifndef LIBP2P_CONFIG_H
#define LIBP2P_CONFIG_H


// common
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>


// socket
#ifdef _WIN32
#include <WinSock2.h>
#include <iphlpapi.h>   //For SendARP
#else
#error need maintain.
#endif


// win32 platform only
#ifdef _WIN32
#	ifdef LIBP2P_EXPORTS
#		define LIBP2P_API	__declspec(dllexport)
#	else
#		define LIBP2P_API	__declspec(dllimport)
#	endif
#endif


// typedef 
typedef struct in_addr	P2P_in_addr;


#endif