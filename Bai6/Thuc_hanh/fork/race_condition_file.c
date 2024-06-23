#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h> // For pthread_mutex_t
#include <sys/file.h> // For flock

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int main()
{
	int fd , pid ; 	
	char *parent_chr = "i 'am parent\n";
	char *child_chr = "i 'am child\n";
	fd = open("sample.txt" , O_RDWR| O_CREAT);

	if( (pid = fork()) > 0) 
	{	
		write(fd , parent_chr , sizeof(parent_chr)); 
	}
	else if( pid == 0) 
	{   
		write(fd , child_chr , sizeof(child_chr));
	}s
	closes();
	return 0;
}