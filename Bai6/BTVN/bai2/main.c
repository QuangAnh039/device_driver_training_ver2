#include <fcntl.h>  // for open
#include <unistd.h> // for read, close
#include <stdio.h>  // for printf
#include <stdlib.h> // for exit
int main()
{
    int fd;
    fd = open("file.txt", O_RDWR);
    if(fd > 0)
    {
        return 0;
    }
    else
    {
        return EXIT_FAILURE;
    }
}