#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
    char name[25];
    int tuoi;
} data;

data *shared_data;

void signal_handler(int sig) 
{
    printf("Name = %s, Age = %d\n", shared_data->name, shared_data->tuoi);
    FILE *log_file = fopen("quanganh.txt", "a");
    if (log_file == NULL) 
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "Name: %s, Age: %d\n", shared_data->name, shared_data->tuoi);
    fclose(log_file);
}

int main()
{
    int fd;

    // Set up signal handling
    signal(SIGUSR1, signal_handler);

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
    shared_data = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_data == MAP_FAILED) 
    {
        perror("mmap error!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started. Waiting for messages...\n");
    printf("PID server's is: %d\n", getpid());

    while (1) 
    {
        sleep(1);
    }   
    munmap(0, 4096);
    return 0; 
}
