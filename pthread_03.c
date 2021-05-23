#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>


pthread_t tid1;
pthread_t tid2;

void *Thread1_Function(void *p)
{
    uint16_t count=0;
    for(;;)
    {
      printf("Thread_1 is Running: %d\r\n", count++);
      sleep(1);
      if(count ==30)
      {
          printf("Terminating Thread_2\r\n");
          pthread_cancel(tid2);
      }
    }
}

void *Thread2_Function(void *p)
{
    for(;;)
    {
        printf("Thread_2 is Running...\r\n");
        sleep(1);
    }
}

/* Deleting the thread from one thread */
int main(void)
{
    /*Crating the thread  */
  pthread_create(&tid1, NULL, Thread1_Function, NULL);
  pthread_create(&tid2, NULL, Thread2_Function, NULL);

  /*Joining the thread */
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  pthread_exit(NULL);
  return 0;
}