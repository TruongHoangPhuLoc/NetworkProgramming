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
    for(;;)
    {
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        printf("Write something to talk to clients: ");
        /// Use dynamic allocation to delcare string because string data type does not exist in C.
        char* str = (char*)calloc(MAXLINE,sizeof(char)); 
        fgets(str,100,stdin);
        snprintf(buff,sizeof(buff),"%s\n",str);
        write(connfd,buff,strlen(buff));
        ///take the memory allocated back to OS
        free(str);
        close(connfd);
    }
}