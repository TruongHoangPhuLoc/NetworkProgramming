#include <stdio.h>

int main()
{
    printf ("I'm parent process\n");
    //fork, at this time will have 2 process
    fork();
    printf("Check if we have 2 processes\n");
    fork();
    printf("check if we have 4 processes\n");
    sleep(30);
    return 0;
}