#include<stdio.h>
int main()
{
    char string[] = "Phu Loc";
    int i = 1;
    while(string[i] != '\0')
    {
        i++;
    }
    printf("%d\n",i);
}