#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   printf("Parent process ID %d\n",getpid());
   pid_t child_pid;
   child_pid = fork();
   while(1)
   {
    ///if we are in parent process
    if(child_pid > 0)
    {
        ///create another child process
        child_pid = fork();
    }
    else
    {
        printf("PID %d\n",getpid());
        printf("\n---------------------------\n");
        exit(0);
    }
    sleep(10);
   }
   return 0;
}