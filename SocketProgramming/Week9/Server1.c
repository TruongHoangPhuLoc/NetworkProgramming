#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
#define MAXLINE 100
struct account {
    char username[100];
    char password[100];
};
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
    struct account def;
    strcpy(def.username,"PhuLoc\0");
    strcpy(def.password,"123");
    for(;;)
    {
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        char *recvline = (char*)calloc(MAXLINE+1,sizeof(char));
        int n;
        int count = 0;
        //get message from client
        if((n = read(connfd,recvline,MAXLINE))>0)
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
            ///convert recv to account
            int sw = 0; ///use to switch to other attribute
            struct account myaccount;
            int j = 0;
            for(int i = 0; i <= strlen(recv); i++)
            {
                if(recvline[i] == ' ')
                {
                    sw = 1;
                    j  = 0;
                    myaccount.username[j] == '\0';
                    continue;
                }
                if(sw == 0)
                {
                    myaccount.username[j] = recvline[i];
                    j++;
                }
                if(sw == 1)
                {
                    myaccount.password[j] = recvline[i];
                    j++;
                }
            }
            printf("\nusername is:%s\nPassword is: %s\n",myaccount.username,myaccount.password);
            ///if authentication is true
            if(strcmp(def.username,myaccount.username)==0 && strcasecmp(def.password,myaccount.password)==0)
            {
                write(connfd,100,"Sign in successfully");
                close(connfd);
            }
            else
            {
                if(count <= 3)
                {
                    write(connfd,100,"Wrong username or password, try again!\n");
                }
                else
                {
                    write(connfd,100,"You've entered wrong 3 times!!!\n");
                    close(connfd);
                }

            }
        }
        //give message back to client
    }
}