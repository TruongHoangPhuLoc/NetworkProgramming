#include<stdio.h>
#include"myheader.h"

int main()
{
   
    int a,b;
    printf("Enter a and b respectively: ");
    scanf("%d%d",&a,&b);
    printf("%d\n",greatestCommonDivisor(a,b));
    
}