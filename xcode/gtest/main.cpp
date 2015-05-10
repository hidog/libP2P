// gtest.cpp : ©w∏q•D±±•x¿≥•Œµ{¶°™∫∂i§J¬I°C
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



int main( int argc, char **argv )
{
    testing::InitGoogleTest( &argc, argv );
    return	RUN_ALL_TESTS();
}