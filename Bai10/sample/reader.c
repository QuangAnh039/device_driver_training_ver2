#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>

int main() 
{
    int fd; 
    void *ptr;
    fd = shm_open("quanganh039", O_RDONLY, 0666); 
    ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, fd, 0x1); 

    printf("%s", (char*)ptr); 
    munmap(0, 4096);
    shm_unlink("quanganh39");
    return 0;
}