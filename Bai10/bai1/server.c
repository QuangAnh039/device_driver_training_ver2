#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>

void log_message(const char *message) 
{
    FILE *log_file = fopen("./quanganh.txt", "a+");
    if (log_file == NULL) 
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "Client: %s\n", message);
    fclose(log_file);
}

int main()
{
    int fd;
    char* ptr; 

    /* create the shared memory object */
    fd = shm_open("chat_shm", O_CREAT | O_RDWR, 0666);
    if (fd == -1) 
    {
        perror("shm_open error!\n");
        exit(EXIT_FAILURE);
    }

    /* configure the size of the shared memory object */
    if (ftruncate(fd, 4096) == -1) 
    {
        perror("ftruncate error!\n");
        exit(EXIT_FAILURE);
    }

    /* memory map the shared memory object */
    ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) 
    {
        perror("mmap error!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started. Waiting for messages...\n");

    while (1) 
    {
        //Chờ cho đến khi có tin nhắn mới
        if (ptr[0] != '\0') 
        {
            printf("Client: %s", ptr);
            log_message(ptr);
            ptr[0] = '\0';  // Đánh dấu tin nhắn đã đọc 
        }
        //sleep(1);
    }
    munmap(0, 4096);
    return 0; 
}