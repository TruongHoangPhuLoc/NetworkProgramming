#include<stdio.h>
#include<unistd.h>
int main(){
    printf("hello\n");
    ///wait for 5s
    sleep(5);
    printf("world");
}