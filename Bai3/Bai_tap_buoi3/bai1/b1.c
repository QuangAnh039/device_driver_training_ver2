#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc , char * argv[])
{
    char *buff;
    int fd;
    if(argc != 4)
    {
        perror("incorrect syntax\n");
        return -1;
    }

    buff = (char *)malloc(1);
    if(fd = open(argv[1], O_RDONLY))
    {
        lseek(fd, atoi(argv[2]), atoi(argv[3]));
        read(fd, buff, 1);
        puts(buff);
    }
    free(buff);
    return 0;
}
