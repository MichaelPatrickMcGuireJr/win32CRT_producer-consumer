/*
 *   Author:  Michael McGuire
 *  Purpose:  producer-consumer threads have 2 thread groups.  One thread group will organize several incoming tasks and task details into a queue.  Then there will be a different thread group that will process and complete the tasks being held within the queue.
 * Language:  c++
 */

// headers
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <queue>
#include <time.h>

using namespace std;

// this queue holds the work requests
queue <int> gq;

// this thread places tasks on to the work queue
void produce( void* pParams )
{
    // every second a number is placed next in line on the queue
    srand (time(NULL));
    // loop will run 7 times, creating 7 tasks
    for( int i=0;i<7;i++ )
    {
        // generate pseudo random number based on system clock
        int v1 = rand() % 100 + 1;
        // push number onto the queue
        gq.push( v1 );
        printf("added %d to queue \n",v1);
        // wait 1 second before restarting the loop
        Sleep(1000);
    }
}

// this thread removes task from work queue and processes it
void consume( void* pParams )
{
    // infinite loop
    while( true )
    {
        // determines if any tasks exist on the worker queue
        if(gq.size()>0)
        {
            // pull task from queue in the order of FIFO
            int v1 = gq.front();
            // remove that value from the queue
            gq.pop();
            // process the task by printing the int value on the console
            printf("removed %d from queue \n",v1);
            // wait 3 seconds before next loop iteration
            Sleep(3000);
        }
    }
}


int main( void )
{
    printf("Starting producer thread and starting consumer thread \n");

    // starting the produce and consume threads
    _beginthread( produce, 0, NULL );
    _beginthread( consume, 0, NULL );

    // infinite loop keeping threads alive
    while( TRUE )
    {
        int x=1;
        x=x+0;
    }

    // exit main
    return 0;
}


