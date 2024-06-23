#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int pid;
    pid = fork();
    if(0 != pid)
    {
        while(1)
        {
            printf("I am parrent %d, my pid = %d\n", pid, getpid());
            sleep(100);
        }
        
    }
    else
    {
        while(1)
        {
            printf("I am child %d, my pid = %d\n", pid, getpid());
            sleep(100);
        }
    }
}