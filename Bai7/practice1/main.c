#include <stdio.h>
#include <signal.h>

void my_handler(int signo)
{
    if(SIGINT == signo)
    {
        printf("Hello world\n");
    }
}
int main()
{
    signal(SIGINT, my_handler);
    while(1);
}
