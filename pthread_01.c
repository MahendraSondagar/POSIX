#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *MyFunction(void *p)
{
    for(;;)
    {
        printf("Thread 1 is Running...\r\n");
        sleep(1);
    }
}

/* pThread API test */
int main(void)
{
    pthread_t th1;
    /* Creating the thread */
    pthread_create(&th1, NULL, MyFunction, NULL);
    /* pointer to thread id, attributes, Function pointer, arg. of thread */
    pthread_join(th1, NULL);
    pthread_exit(NULL);

}