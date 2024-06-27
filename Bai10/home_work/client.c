#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
typedef struct 
{
    char name[25];
    int tuoi;
} data;

int main() 
{
    // Open shared memory
    int shm_fd = shm_open("chat_shm", O_RDWR, 0666);
    if (shm_fd == -1) 
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Map shared memory in address space
    data *shared_data = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_data == MAP_FAILED) 
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        // Get input from user
        printf("Enter name: ");
        fgets(shared_data->name, sizeof(shared_data->name), stdin);
        shared_data->name[strcspn(shared_data->name, "\n")] = '\0';  // Remove newline character

        printf("Enter age: ");
        scanf("%d", &shared_data->tuoi);
        clear_input_buffer(); // Clear the input buffer

        // Get server PID
        printf("Enter server PID: ");
        pid_t server_pid;
        scanf("%d", &server_pid);
        clear_input_buffer(); // Clear the input buffer

        // Send signal to server
        kill(server_pid, SIGUSR1);
    }
    
    // Cleanup
    munmap(shared_data, sizeof(data));
    close(shm_fd);

    return 0;
}
