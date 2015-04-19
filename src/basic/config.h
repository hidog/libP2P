#ifndef LIBP2P_CONFIG_H
#define LIBP2P_CONFIG_H


// common
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

// boolean
#ifndef __cplusplus
typedef int		bool;
#define false	0
#define true	1
#endif


// socket
#ifdef _WIN32
#include <WinSock2.h>
#include <iphlpapi.h>   //For SendARP
#include <ws2tcpip.h>
//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
#else
#error need maintain.
#endif


// thread
#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <WinBase.h>
#else
#error need maintain.
#endif




// win32 platform only
#ifdef _WIN32
#	ifdef LIBP2P_EXPORTS
#		define LIBP2P_API	__declspec(dllexport)
#	else
#		define LIBP2P_API
#	endif
#endif


// memory leak.
//#define		P2P_CRT_MEMORY_LEAK			// un-mark, than use CRT memory leak detector.

#if defined(_WIN32) & defined(P2P_CRT_MEMORY_LEAK)
#	ifdef _DEBUG
#		define _CRTDBG_MAP_ALLOC
#		include <crtdbg.h>
#		define	P2P_malloc	malloc
#	endif
#endif




// typedef 
typedef struct in_addr		P2P_in_addr_t;
typedef struct hostent		P2P_hostent_t;
typedef struct sockaddr_in	P2P_sockaddr_in_t;
typedef struct sockaddr		P2P_sockaddr_t;
typedef	SOCKET	P2P_socket_t;
typedef HANDLE	P2P_thread_t;

//typedef HANDLE	P2P_mutex_t;
typedef CRITICAL_SECTION	P2P_mutex_t;

typedef unsigned int	P2P_clock_t;

#endif