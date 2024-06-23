#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
	// FILE *fp;
	// if ( argc != 2 ) 
	// {
	// 	puts("incorrect pass argument");
	// 	return -1;
	// }
	// fp = fopen(argv[1] , "w");

	// fputs("hello world", fp);
	
	// fclose(fp);
	while(1)
	{
		printf("child pid: %d\n", getpid());
		sleep(2);
		//do nothing
	}

	return 0;
}