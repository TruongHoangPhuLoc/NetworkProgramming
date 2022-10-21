#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAXLINE 100
int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    if(argc!=2)
    {
        printf("usage:a.out < IPaddress");
    }
    if((sockfd=socket(AF_INET,SOCK_STREAM,0)) < 0 )
    {
        printf("socket error");
    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(11113);
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
    {
        printf("inet_ption error for %s",argv[1]);
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
    {
        printf("Connection error");
    }
    while((n = read(sockfd,recvline,MAXLINE))>0)
    {
        recvline[n] = 0;
        if(fputs(recvline,stdout)==EOF)
        {
            printf("fputs error");
        }
        if(n<0)
        {
            printf("read error");
        }
    }
    exit(0);

}