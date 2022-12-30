#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
#define MAXLINE 100
int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    /// declare port opened in Server
    servaddr.sin_port = htons(22222);
    bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(listenfd,10);
    int numberofclients;
    for(;;)
    {
       connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
       numberofclients++;
       if(fork()==0)
       {
            close(listenfd);
            snprintf(buff,sizeof(buff),"your client number is %d\n",numberofclients);
            write(connfd,buff,MAXLINE);
            close(connfd);
            exit(0);
       }
       close(connfd);
    }
}
