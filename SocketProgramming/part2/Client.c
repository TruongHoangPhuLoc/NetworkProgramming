#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAXLINE 100
int main(int argc, char **argv)
{   //setting up connection
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buff[MAXLINE+1];
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
    //proceed process
    //write to server
    /// Use dynamic allocation to delcare string because string data type does not exist in C.
        printf("Write something to server: ");
        char* str = (char*)calloc(MAXLINE,sizeof(char)); 
        fgets(str,100,stdin);
        write(sockfd,str,strlen(str));
    ///take the memory allocated back to OS
        free(str);
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