//Viết 1 chương trình C để block Ctrl + C signal từ user
#include <stdio.h>
#include <signal.h>


int main()
{
    sigset_t my_set;
    sigemptyset(&my_set);
    sigaddset(&my_set, SIGINT);
    sigprocmask(SIG_BLOCK, &my_set, NULL);
    while(1);
}
