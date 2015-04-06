#include <stdio.h>
#include <stdlib.h>

#include "basic/linklist.h"


int main()
{
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

	system("PAUSE");
	return	0;
}