#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function
void signal_handler(int signal_num) {
    if (signal_num == SIGUSR1) {
        printf("Received SIGUSR1 signal. Waking up!\n");
        exit(0); // Exit the program after receiving the signal
    }
}

int main() {
    // Register the signal handler for SIGUSR1
    signal(SIGUSR1, signal_handler);

    printf("Going to sleep indefinitely. PID: %d\n", getpid());

    // Sleep indefinitely
    while (1) {
        sleep(1);
    }
    return 0;
}
