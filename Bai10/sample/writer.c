#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
int main() 
{
    int fd;
    void* ptr; 
    const char* message_0 = "Hello_World!"; 
    /* create the shared memory object */
    fd = shm_open("quanganh039", O_CREAT | O_RDWR, 0666);

    /* configure the size of the shared memory object */
    ftruncate(fd, 4096); 

    /* memory map the shared memory object */
    ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, fd, 0);

    
    /* write to the shared memory object */
    sprintf(ptr, "%s", message_0); 

    munmap(0, 4096);
    return 0; 
}