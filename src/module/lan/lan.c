#include "lan.h"
#include "data.h"

#include "def/def.h"
#include "basic/config.h"
#include "basic/log.h"
#include "basic/config.h"

/***********************************************************
	P2P_send_lan_search
	http://stackoverflow.com/questions/337422/how-to-udp-broadcast-with-c-in-linux
************************************************************/
int		P2P_send_lan_search()
{
	GlobalData_s		*p_gdata	=	P2P_get_global_data();
	P2P_sockaddr_in_t	addr_in;
	int		err;
	char	buf[100]	=	"hello?";


	if( p_gdata->bcast_skt < 0)
        return	P2P_ERROR;

    memset( &addr_in, 0, sizeof(P2P_sockaddr_in_t) );
    addr_in.sin_family		=	AF_INET;
    addr_in.sin_port		=	htons( 3330 );
    addr_in.sin_addr.s_addr	=	htonl(INADDR_BROADCAST);

    //cli_dbgmsg("broadcast %s to %d\n", mess, broadcastSock);
	err		=	sendto( p_gdata->bcast_skt, buf, strlen(buf), 0, (P2P_sockaddr_t*)&addr_in, sizeof(P2P_sockaddr_in_t) );
    if( err < 0 )
        WARNING_LOG("broadcast fail.")

	return	P2P_OK;
}
