// gtest.cpp : 定義主控台應用程式的進入點。
//

#ifdef _WIN32
#include "stdafx.h"
#endif

#include <stdlib.h>
#include "gtest/gtest.h"

#include "gtest_linklist.h"	

// Test
TEST( TEST1, TEST2 ) 
{
	EXPECT_EQ( 1, 1 );
}


#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main( int argc, char **argv )
#endif
{
	testing::InitGoogleTest( &argc, argv );
    RUN_ALL_TESTS();

#ifdef _WIN32
	system("PAUSE");
#endif
	return	0;
}