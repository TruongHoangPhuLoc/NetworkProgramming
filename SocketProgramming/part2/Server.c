#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#define MAXLINE 100
int main(int argc, char **argv)
{
    int listenfd, connfd,n;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE + 1];
    char buff[MAXLINE];
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    ///what is this?
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(11113);
    bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(listenfd,10);
    for(;;)
    {
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        n = read(listenfd,recvline,MAXLINE);
        printf("%d",n);
        recvline[n] = 0;
        close(listenfd);
    }
}