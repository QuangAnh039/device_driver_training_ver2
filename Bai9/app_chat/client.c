#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#define BUFFER_SIZE 1024
int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char recv_buffer[BUFFER_SIZE] = {0};
    char sent_buffer[BUFFER_SIZE] = {0};

    memset(&server_addr, 0, sizeof(server_addr));

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    server_addr.sin_family = AF_UNIX;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(66);

    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        printf("Connection failed!\n");
        return -1;
    }
    while(1)
    {
        printf("Client: ");
        fgets(sent_buffer, BUFFER_SIZE, stdin);    
        send(sockfd, sent_buffer, strlen(sent_buffer), 0);
        memset(sent_buffer, 0, BUFFER_SIZE);
        read(sockfd, recv_buffer, BUFFER_SIZE);
        printf("Server: %s\n", recv_buffer);
        memset(recv_buffer, 0, 1024);
    }
    close(sockfd);
}