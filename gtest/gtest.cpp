// gtest.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdlib.h>
#include "gtest/gtest.h"


// Test
TEST( TEST1, TEST2 ) 
{
	EXPECT_EQ( 1, 1 );
}



int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest( &argc, argv );
    RUN_ALL_TESTS();

	system("PAUSE");
	return	0;
}