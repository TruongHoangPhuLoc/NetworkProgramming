#include <stdio.h>
int main()
{
    int n;
    printf("enter n:\n");
    scanf("%d",&n);
    int sum = 0;
    if(n<50)
    {
        for(int i = 0; i <= n; i++)
        {
            sum += i;
        }
    }
    else
    {
        sum = ((1+n)*n)/2;
    }
    printf("the total from 1 to %d is %d\n",n,sum);
    return 0;
}