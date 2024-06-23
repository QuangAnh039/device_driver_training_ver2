#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the first argument to PID
    pid_t pid = (pid_t)atoi(argv[1]);

    // Send SIGUSR1 signal to the specified PID
    if (kill(pid, SIGINT) == -1) 
    {
        perror("Error sending signal");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Sent SIGUSR1 signal to process %d\n", pid);
    }
    return 0;
}
