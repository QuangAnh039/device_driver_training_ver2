#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define CHUNK_SIZE 4096  // Kích thước của mỗi khối đọc (4KB)
#define TOTAL_SIZE (100 * 1024 * 1024)  // Tổng số byte cần đọc (100MB)

int main() {
    const char *filepath = "100MB.txt";  // Đường dẫn tới tệp lớn
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char buffer[CHUNK_SIZE];
    ssize_t bytesRead;
    size_t totalBytesRead = 0;

    // Đọc dữ liệu từ tệp theo từng khối nhỏ cho đến khi đạt 100MB hoặc hết tệp
    while (totalBytesRead < TOTAL_SIZE && (bytesRead = read(fd, buffer, CHUNK_SIZE)) > 0) {
        // Xử lý dữ liệu trong buffer ở đây
        // Ví dụ: In dữ liệu ra màn hình
        totalBytesRead += bytesRead;
    }

    if (bytesRead == -1) {
        perror("Error reading file");
    }

    close(fd);
    printf("Total bytes read: %zu\n", totalBytesRead);
    printf("Hello Quang Anh\n");
    return EXIT_SUCCESS;
}