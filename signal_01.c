#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void MyHandler()
{
    write(STDOUT_FILENO, "Hey! interrupted :P\r\n", 22);
}

int main(void)
{
    /* Creating the signal & attaching the handler*/
    /* Handler will call, when user press ctl+c */
    signal(SIGINT, MyHandler);
    while(1)
    {
        printf("Running process: %d\r\n", getpid());
        sleep(1);
    }
}