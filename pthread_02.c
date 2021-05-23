#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *Thread1_Function(void *p)
{
   char *msg = ( char *)p;
  for(;;)
  {
     printf("Thread 1 msg: %s\r\n", msg);
     sleep(1);
  }
}

void *Thread2_Function(void *p)
{
   char *msg = ( char *)p;
  for(;;)
  {
     printf("Thread 2 msg: %s\r\n", msg);
     sleep(1);
  }
}

/* Passin the argument, to the thread function */
int main(void)
{
    pthread_t tid1;
    pthread_t tid2;

    char *message1 ="Hello world";
    char *message2 ="Hello Universe";

    /* Creating the threads */
    pthread_create(&tid1, NULL, Thread1_Function, message1);
    pthread_create(&tid2, NULL, Thread2_Function, message2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_exit(NULL);
}