#include "gtest_linklist.h"

extern "C"{
#include "basic/linklist.h"
}

#include "gtest/gtest.h"



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST( linklist, pushback_1 )
{
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

	EXPECT_EQ( P2P_LL_size(linklist), 100 );

	for( i = 0; i < 100; i++ )
	{
		ptr		=	P2P_LL_get_node_LLTest( linklist );
		EXPECT_EQ( ptr->d1, i );
		EXPECT_EQ( ptr->d2, i + 100 );
		EXPECT_EQ( ptr->d3, i + 10000 );
		P2P_LL_move_to_next( linklist );
	}

	linklist	=	P2P_LL_free( linklist );
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST( linklist, remove_1 )
{
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

	EXPECT_EQ( P2P_LL_size(linklist), 100 );

	for( i = 0; i < 100; i++ )
	{
		ptr		=	P2P_LL_get_node_LLTest( linklist );
		EXPECT_EQ( ptr->d1, i );
		EXPECT_EQ( ptr->d2, i + 100 );
		EXPECT_EQ( ptr->d3, i + 10000 );
		P2P_LL_remove_node( linklist );
	}

	linklist	=	P2P_LL_free( linklist );
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST( linklist, general_1 )
{
	LLData_s	*linklist	=	P2P_LL_init(LL_TYPE_LLTest);
	LLTest_s	data;
	LLTest_s	*ptr;
	int		i;

	data.d1		=	1;
	data.d2		=	2;
	data.d3		=	3;
	P2P_LL_pushback_LLTest( linklist, &data );
	EXPECT_EQ( P2P_LL_size(linklist), 1 );

	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ( ptr->d1, 1 );
	EXPECT_EQ( ptr->d2, 2 );
	EXPECT_EQ( ptr->d3, 3 );
	
	linklist	=	P2P_LL_free( linklist );
}
