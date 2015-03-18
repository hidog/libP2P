// testP2P.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "../src/test.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.


using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{

	boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::cout << uuid << std::endl;


	test_p2p();



	system("PAUSE");
	return 0;
}

