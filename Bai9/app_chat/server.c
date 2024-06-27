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
    int connfd = -1;
    int listenfd = -1;
    struct sockaddr_in server_addr;
    char recv_buffer[BUFFER_SIZE] = {0};
    char sent_buffer[BUFFER_SIZE] = {0};

    memset(&server_addr, 0, sizeof(server_addr));

    listenfd = socket(AF_UNIX, SOCK_STREAM, 0);

    server_addr.sin_family = AF_UNIX;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(66);

    bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    listen(listenfd , 10); // hang doi 10 o
    
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
    while(1)
    {
        
        int valread = read(connfd, recv_buffer, BUFFER_SIZE);
        if (valread == 0) 
        {
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s\n", recv_buffer);
        if(strcmp(recv_buffer, "1\n") == 0)
        {
            send(connfd, "hello\n", strlen("hello"), 0);
        }
        else if (strcmp(recv_buffer, "2\n") == 0) 
        {
            send(connfd, "bye\n", strlen("bye"), 0);
        }
        else if (strcmp(recv_buffer, "exit\n") == 0) 
        {
            close(connfd);
        }
        else
        {
            send(connfd, "invalid", strlen("invalid"), 0);
        }
        memset(recv_buffer, 0, 1024);
        // printf("Server: ");
        // fgets(sent_buffer, BUFFER_SIZE, stdin);
        // send(connfd, sent_buffer, strlen(sent_buffer), 0);
    }
    close(listenfd);
    return 0;
}