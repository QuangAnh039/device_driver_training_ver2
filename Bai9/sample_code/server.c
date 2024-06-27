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

void main()
{
    int connfd = -1;
    int listenfd = -1;
    struct sockaddr_in server_addr;
    time_t ticks;
    char send_buffer[1024];

    memset(send_buffer, 0, sizeof(send_buffer));
    memset(&server_addr, 0, sizeof(server_addr));

    listenfd = socket(AF_UNIX, SOCK_STREAM, 0);

    server_addr.sin_family = AF_UNIX;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(1000);

    bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(listenfd , 10); // hang doi 10 o
    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        ticks = time(NULL);
        sprintf(send_buffer, "Server reply %s", ctime(&ticks));
        send(connfd , send_buffer , strlen(send_buffer) , 0 );
        close(connfd);
    }
    close(listenfd);
    return 0;
}