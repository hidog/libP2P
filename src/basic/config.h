#ifndef LIBP2P_CONFIG_H
#define LIBP2P_CONFIG_H


// common
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef _WIN32
#include <time.h>
#else
#include <sys/time.h>
#include <unistd.h>
#endif

// boolean
#ifndef __cplusplus
typedef int		bool;
#define false	0
#define true	1
#endif


// see http://stackoverflow.com/questions/10053788/implicit-declaration-of-function-usleep
// the warning implicit declaration of function usleep in C99

// socket
#ifdef _WIN32
#i  nclude <WinSock2.h>
#   include <iphlpapi.h>   //For SendARP
#   include <ws2tcpip.h>
//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
#   define P2P_INVALID_SKT  INVALID_SOCKET
#   define P2P_SKT_GET_ERR  WSAGetLastError()
#else
#   include <sys/types.h>
#   include <sys/socket.h>
#   include <netinet/in.h>
#   include <netinet/ip.h>
#   include <arpa/inet.h>
#   include <errno.h>
#   include <netdb.h>
#   define P2P_INVALID_SKT  -1
#   define P2P_SKT_GET_ERR  errno
#endif


// thread
#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <WinBase.h>
#else
#include <pthread.h>
#endif




// win32 platform only
#ifdef _WIN32
#	ifdef LIBP2P_EXPORTS
#		define LIBP2P_API	__declspec(dllexport)
#	else
#		define LIBP2P_API
#	endif
#else
#   define LIBP2P_API
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
#ifdef _WIN32
typedef	SOCKET              P2P_socket_t;
typedef HANDLE              P2P_thread_t;
typedef CRITICAL_SECTION	P2P_mutex_t;
#else
typedef int                 P2P_socket_t;
typedef pthread_t           P2P_thread_t;
typedef pthread_mutex_t     P2P_mutex_t;
#endif
//typedef HANDLE	P2P_mutex_t;

typedef unsigned long long	P2P_clock_t;

#endif