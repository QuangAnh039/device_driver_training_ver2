#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc , char *argv[])
{
	int pid , status;
	int var1 = 1;
	if( (pid = fork()) <0)
	{
		perror("fork");
		return -2;
	}
	else if ( pid == 0 ) 
	{
		printf("child pid: %d\n", getpid());
		if (execl("./ch" , "./ch" , NULL))
			perror("execl");
	}
	else {
		printf("parrent pid: %d\n", getpid());
		printf("%d\n", ++var1);
		wait(&status);
		printf("status : %s\n" , (status == 0) ? "ok" : "fail");

	}

	return 0;
}