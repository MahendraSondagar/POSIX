#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

/* AIM: To access the global resource or peripherl bus via task sync. */
/* Global mutex handler */
pthread_mutex_t lock;
/* Global resource to access */
uint32_t global_token=0;
void *thread_1(void *p)
{
    for(;;)
    {
        pthread_mutex_lock(&lock);
        printf("Thread1 getting global token: %d\r\n", global_token++);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void *thread_2(void *p)
{
    for(;;)
    {
        pthread_mutex_lock(&lock);
        printf("Thread2 getting global token: %d\r\n", global_token++);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

int main(void)
{
    pthread_t tid1, tid2;
    /* Creating the mutex */
    if(pthread_mutex_init(&lock, NULL)!=0)
    {
        perror("Failed to create mutex\r\n");
    }
    if(pthread_create(&tid1, NULL, thread_1, NULL)!=0)
    {
        perror("Failed to create thread1\r\n");
    }
    if(pthread_create(&tid2, NULL, thread_2, NULL)!=0)
    {
        perror("Failed to create thread2\r\n");
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}