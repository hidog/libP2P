#include "test.h"

/*extern "C" {
#include "libP2P.h"
}*/
#include "libP2P.h"
#include "def/def.h"


/***********************************************************
	test_p2p
************************************************************/
int		test_p2p()
{
	P2P_init();
	//P2P_set_opt( P2P_OPT_ENABLE_SERVER );
	P2P_set_name( "P771" );
	P2P_set_passwd( "P771" );

	P2P_start();


	while(true)
	{
		//P2P_lan_search();

		//printf("wait...\n");
		Sleep(100);
	}

	return 0;
}
