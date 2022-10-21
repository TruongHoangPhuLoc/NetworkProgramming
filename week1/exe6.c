#include<stdio.h>
#include<stdlib.h>
int main()
{
    ///ax+b=0
    int a,b;
    printf("enter number a and b respectively:\n");
    scanf("%d %d",&a,&b);
    if(a == 0)
    {
        if(b==0)
        {
            printf("The equation has infinite solutions\n");
            return 0;
        }
        if(b!=0)
        {
            printf("The equation has no solution\n");
            return 0;
        }
    }
    float result = (-b) / (float) a;
    printf("The result of equation %dx %c %d = 0 is %.2f\n",a,(b>0)?'+':'-',abs(b),result);
    return 0;
}