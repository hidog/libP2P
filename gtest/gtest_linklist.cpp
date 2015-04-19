#include "gtest_linklist.h"

/*extern "C"{
#include "basic/linklist.h"
}*/

#include "gtest/gtest.h"



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST( linklist, pushback_1 )
{
	LinkList_s	*linklist	=	P2P_LL_init(LL_TYPE_LLTest);
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
	LinkList_s	*linklist	=	P2P_LL_init(LL_TYPE_LLTest);
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
	LinkList_s	*linklist	=	P2P_LL_init(LL_TYPE_LLTest);
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

	P2P_LL_remove_node(linklist);
	EXPECT_EQ( P2P_LL_is_empty(linklist), true );
	
	for( i = 0; i < 10; i++ )
	{
		data.d1		=	i;
		data.d2		=	i + 100;
		data.d3		=	i + 10000;
		P2P_LL_pushback_LLTest( linklist, &data );
	}

	P2P_LL_set_node_to_head(linklist);
	P2P_LL_remove_node(linklist);
	P2P_LL_move_to( linklist, 6 );
	P2P_LL_remove_node(linklist);
	P2P_LL_set_node_to_tail(linklist);
	P2P_LL_remove_node(linklist);

	/*P2P_LL_set_node_to_head(linklist);
	for( i = 0; i < 10; i++ )
	{
		ptr		=	P2P_LL_get_node_LLTest(linklist);
		printf("ptr = %d, %d, %d\n", ptr->d1, ptr->d2, ptr->d3 );
		P2P_LL_move_to_next(linklist);
	}*/

	P2P_LL_set_node_to_head(linklist);
	ptr		=	P2P_LL_get_node_LLTest( linklist );
	EXPECT_EQ( ptr->d1, 1 );
	EXPECT_EQ( ptr->d2, 101 );
	EXPECT_EQ( ptr->d3, 10001 );
	
	P2P_LL_move_to( linklist, 4 );
	ptr		=	P2P_LL_get_node_LLTest( linklist );
	EXPECT_EQ( ptr->d1, 5 );
	EXPECT_EQ( ptr->d2, 105 );
	EXPECT_EQ( ptr->d3, 10005 );

	P2P_LL_set_node_to_tail( linklist );
	ptr		=	P2P_LL_get_node_LLTest( linklist );
	EXPECT_EQ( ptr->d1, 8 );
	EXPECT_EQ( ptr->d2, 108 );
	EXPECT_EQ( ptr->d3, 10008 );

	data.d1		=	99;
	data.d2		=	99;
	data.d3		=	99;
	P2P_LL_pushfront_LLTest(linklist, &data);
	P2P_LL_set_node_to_head(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 99);
	EXPECT_EQ(ptr->d2, 99);
	EXPECT_EQ(ptr->d3, 99);

	P2P_LL_clear(linklist);

	for( i = 0; i < 10; i++ )
	{
		data.d1		=	0;
		data.d2		=	i;
		data.d3		=	2*i;
		P2P_LL_pushback_LLTest(linklist, &data);
	}
	EXPECT_EQ(P2P_LL_size(linklist), 10);

	P2P_LL_move_to(linklist, 6);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 0);
	EXPECT_EQ(ptr->d2, 6);
	EXPECT_EQ(ptr->d3, 12);

	P2P_LL_move_to_prev(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 0);
	EXPECT_EQ(ptr->d2, 5);
	EXPECT_EQ(ptr->d3, 10);

	for( i = 5; i >= 0; i-- )
		P2P_LL_move_to_prev(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 0);
	EXPECT_EQ(ptr->d2, 0);
	EXPECT_EQ(ptr->d3, 0);

	for( i = 0; i < 10; i++ )
		P2P_LL_move_to_next(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 0);
	EXPECT_EQ(ptr->d2, 9);
	EXPECT_EQ(ptr->d3, 18);

	P2P_LL_clear(linklist);
	for( i = 0; i < 10; i++ )
	{
		data.d1		=	1;
		data.d2		=	3*i;
		data.d3		=	-i;
		P2P_LL_pushfront_LLTest(linklist, &data);
	}
	EXPECT_EQ(P2P_LL_size(linklist), 10);

	/*P2P_LL_set_node_to_head(linklist);
	for( i = 0; i < 10; i++ )
	{
		ptr		=	P2P_LL_get_node_LLTest(linklist);
		printf("ptr = %d, %d, %d\n", ptr->d1, ptr->d2, ptr->d3 );
		P2P_LL_move_to_next(linklist);
	}*/

	P2P_LL_move_to(linklist, 6);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 1);
	EXPECT_EQ(ptr->d2, 9);
	EXPECT_EQ(ptr->d3, -3);

	P2P_LL_move_to_prev(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 1);
	EXPECT_EQ(ptr->d2, 12);
	EXPECT_EQ(ptr->d3, -4);

	for( i = 5; i >= 0; i-- )
		P2P_LL_move_to_prev(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 1);
	EXPECT_EQ(ptr->d2, 27);
	EXPECT_EQ(ptr->d3, -9);

	for( i = 0; i < 10; i++ )
		P2P_LL_move_to_next(linklist);
	ptr		=	P2P_LL_get_node_LLTest(linklist);
	EXPECT_EQ(ptr->d1, 1);
	EXPECT_EQ(ptr->d2, 0);
	EXPECT_EQ(ptr->d3, 0);

	linklist	=	P2P_LL_free( linklist );
}
