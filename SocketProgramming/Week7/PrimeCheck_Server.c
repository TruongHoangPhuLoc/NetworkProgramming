#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
#define MAXLINE 100
int isPrimeNum(int number)
{
    if(number < 2)
    {
        return 0;
    }
    for(int i = 2;i<number;i++)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
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
        char *recvline = (char*)calloc(MAXLINE+1,sizeof(char));
        int n;
        //get message from client
        while((n = read(connfd,recvline,MAXLINE))>0)
        {
            recvline[n-1] = 0;
            if(fputs(recvline,stdout)==EOF)
            {
                printf("fputs error");
            }
            if(n<0)
            {
                printf("read error");
            }
            ///convert string to int
            int number = atoi(recvline);
            if(isPrimeNum(number) == 1)
            {
                snprintf(buff,sizeof(buff),"This is actually Prime Number\n");
            }
            else
            {
                snprintf(buff,sizeof(buff),"This is not Prime Number\n");
            }
            write(connfd,buff,strlen(buff));
            free(recvline);
            close(connfd);
        }
        //give message back to client
    }
}