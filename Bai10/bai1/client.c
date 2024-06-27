#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int fd;
    char *ptr;

    // Mở shared memory object
    fd = shm_open("chat_shm", O_RDWR, 0666);
    if (fd == -1) 
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Map shared memory vào không gian địa chỉ của tiến trình
    ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) 
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    printf("Client started. Enter messages to send to server...\n");

    while (1) 
    {
        // Gửi tin nhắn tới server
        printf("Enter message: ");
        fgets(ptr, 4096, stdin);
        //ptr[strlen(ptr) - 1] = '\0';  // Xóa ký tự xuống dòng

        // Chờ phản hồi từ server
        // while (shm_addr[0] != '\0') 
        // {
        //     sleep(1);
        // }
    }

    // Hủy mapping và đóng shared memory object
    munmap(ptr, 4096);
    shm_unlink("chat_shm");

    return 0;
}