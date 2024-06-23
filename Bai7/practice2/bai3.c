// Viết 1 chương trình C block SIGINT, sau đó check trong số signal pending có SIGINT không, nếu có thì thoát chương trình
#include <stdio.h>
#include <signal.h>


int main()
{
    sigset_t my_set, set_pend;
    sigemptyset(&my_set);
    sigaddset(&my_set, SIGINT);
    sigprocmask(SIG_BLOCK, &my_set, NULL);
    while(1)
	{
		if (sigpending(&set_pend) < 0)
        {
            perror("sigpending error");
        }
		if (sigismember(&set_pend, SIGINT))
		{
			printf("\nSIGINT pending\n");
			//break;
		}
        //printf("%d",sigismember(&set_pend, SIGINT));
	}
}
