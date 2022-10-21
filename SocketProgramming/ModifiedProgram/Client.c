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
    servaddr.sin_port = htons(22222);
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
    {
        printf("inet_ption error for %s",argv[1]);
    }
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
    {
        printf("Connection error");
    }
    char *recvline = (char*)calloc(MAXLINE+1,sizeof(char));
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
    free(recvline);
}