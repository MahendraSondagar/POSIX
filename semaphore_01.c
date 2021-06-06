#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/* Global semaphoer handler */
sem_t Mysem;



void *boss_thread(void *p)
{
    for(;;)
    {
        sem_post(&Mysem);
        sleep(1);
    }
}

void *employee_thread(void *p)
{
    for(;;)
    {
        sem_wait(&Mysem);
        printf("Got the signal from the Boss!\r\n");
        sleep(1);
    }
}

int main(void)
{
  pthread_t boss_tid, employee_tid;

  sem_init(&Mysem, 0, 0);
  /* Creating the two thread */
  pthread_create(&boss_tid, NULL, boss_thread, NULL);
  pthread_create(&employee_tid, NULL, employee_thread, NULL);
 /* joining the thread */
  pthread_join(boss_tid, NULL);
  pthread_join(employee_tid, NULL);
  sem_destory(&Mysem);
  return 0;
}