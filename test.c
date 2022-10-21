#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *str = (char*)calloc(100,sizeof(char));
    printf("Enter the string: ");
    fgets(str,100,stdin);
    printf("%s",str);
}