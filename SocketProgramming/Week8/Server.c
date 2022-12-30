#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
#define MAXLINE 100
struct ArrayOfString{
    char string[100];
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
    for(;;)
    {
        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
        char *recvline = (char*)calloc(MAXLINE+1,sizeof(char));
        int n;
        //get message from client
        while((n = read(connfd,recvline,MAXLINE))>0)
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
            /// 120 + 1 = 121
            /// solution is assigning each character to str1 until reaching out the operator
            /// After reaching the operator, assiging each character to str2
            /// convert str1 and str2 to int.
            struct ArrayOfString mystrct[2];
            int iofstring = 0;
            int iofstrct = 0;
            char operator = 0;
            for(int i = 0; i < strlen(recvline); i++)
            {
                if(recvline[i] != '+' && recvline[i] != '-' && recvline[i] != '*' && recvline[i] != '/')
                {
                    mystrct[iofstrct].string[iofstring] = recvline[i];
                    iofstring++;
                }
                else
                {
                    mystrct[iofstrct].string[iofstring] = '\0';
                    iofstrct++;
                    iofstring = 0;
                    operator = recvline[i];
                }
            }
            //proceed calculating process
            int n1 = atoi(mystrct[0].string);
            int n2 = atoi(mystrct[1].string);
            float result;
            switch (operator)
            {
            case '+':
                result = (float) n1 + n2;
                break;
            case '-':
                result = (float) n1 - n2;
                break;
            case '*':
                result = (float) n1 * n2;
            case '/':
                result = (float) n1 / n2;
            default:
                break;
            }
            snprintf(buff,sizeof(buff),"%d %c %d = %.2f\n",n1,operator,n2,result);
            write(connfd,buff,strlen(buff));
            free(recvline);
            close(connfd);
        }
        //give message back to client
    }
}