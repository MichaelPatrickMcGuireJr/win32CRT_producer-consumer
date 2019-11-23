//https://www.codeproject.com/Articles/438/Introduction-to-Multi-threaded-Code
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <queue>
#include <time.h>

using namespace std;

queue <int> gq;

void process( void* pParams )
{
    srand (time(NULL));
    for( int i=0;i<7;i++ )
    {
        int v1 = rand() % 100 + 1;
        gq.push( v1 );
        printf("added %d to queue \n",v1);
        Sleep(1000);
    }
}

void consume( void* pParams )
{
    while( true )
    {
        if(gq.size()>0)
        {
            int v1 = gq.front();
            gq.pop();
            printf("removed %d from queue \n",v1);
            Sleep(3000);
        }
    }
}

int main( void )
{
    printf("Starting producer thread and starting consumer thread \n");

    _beginthread( process, 0, NULL );
    _beginthread( consume, 0, NULL );

    while( TRUE )
    {
        int x=1;
        x=x+0;
    }
    return 0;
}


