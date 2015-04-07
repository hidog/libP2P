#include <stdio.h>
#include <stdlib.h>

#include "basic/linklist.h"


#ifdef P2P_CRT_MEMORY_LEAK
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif




int main()
{
#if 0
	LLData_s	*linklist	=	P2P_LL_init(LL_TYPE_LLTest);

	LLTest_s	data;
	LLTest_s	*ptr;
	data.d1		=	1;
	data.d2		=	2;
	data.d3		=	3;

	P2P_LL_pushback_LLTest( linklist, &data );
	ptr		=	P2P_LL_get_node_LLTest(linklist);

	printf("ptr->d1 = %d, ptr->d2 = %d, ptr->d3 = %d\n", ptr->d1, ptr->d2, ptr->d3 );

	linklist	=	P2P_LL_free( linklist );
#endif


	LLData_s	*linklist	=	P2P_LL_init(LL_TYPE_LLTest);
	LLTest_s	data;
	LLTest_s	*ptr;
	int		i;

	for( i = 0; i < 100; i++ )
	{
		data.d1		=	i;
		data.d2		=	i + 100;
		data.d3		=	i + 10000;
		P2P_LL_pushback_LLTest( linklist, &data );
	}

	//EXPECT_EQ( P2P_LL_size(linklist), 100 );
	printf("linklist size = %d\n", P2P_LL_size(linklist) );

	for( i = 0; i < 100; i++ )
	{
		ptr		=	P2P_LL_get_node_LLTest( linklist );
		//EXPECT_EQ( ptr->d1, i );
		//EXPECT_EQ( ptr->d2, i + 100 );
		//EXPECT_EQ( ptr->d3, i + 10000 );
		printf("node = %d,%d,%d\n", ptr->d1, ptr->d2, ptr->d3 );
		P2P_LL_move_to_next( linklist );
	}

	linklist	=	P2P_LL_free( linklist );




#ifdef P2P_CRT_MEMORY_LEAK
	_CrtDumpMemoryLeaks();
#endif

	system("PAUSE");
	return	0;
}