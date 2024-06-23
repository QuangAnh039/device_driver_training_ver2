//Viết 1 chương trình C để in ra các signal mask của process hiện tại

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
    sigset_t my_set;
    sigemptyset(&my_set);
    sigaddset(&my_set, SIGINT);
    sigprocmask(SIG_BLOCK, &my_set, NULL);
    for (int i = 1; i < NSIG; i++) 
    {
        if (sigismember(&my_set, i)) 
        {
            printf("Signal %d (%s) is blocked\n", i, strsignal(i));
        }
    }
    while(1);
}
