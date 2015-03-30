#include "thread.h"
#include "config.h"


#define MAX_THREADS 10

/***********************************************************
	P2P_create_thread
	see https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516%28v=vs.85%29.aspx
************************************************************/
int		P2P_create_thread()
{
	HANDLE  hThreadArray[MAX_THREADS]; 

	/*hThreadArray[i] = CreateThread( 
            NULL,                   // default security attributes
            0,                      // use default stack size  
            MyThreadFunction,       // thread function name
            pDataArray[i],          // argument to thread function 
            0,                      // use default creation flags 
            &dwThreadIdArray[i]);   // returns the thread identifier */

}
