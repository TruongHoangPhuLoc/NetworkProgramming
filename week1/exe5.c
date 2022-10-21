#include <stdio.h>
int main()
{
    int n;
    printf("enter n:\n");
    scanf("%d",&n);
    int sum = 0;
    if(n<50)
    {
        int i = 1;
        while(i<=n)
        {
            sum+=i;
            i++;
        }
    }
    else
    {
        sum = ((1+n)*n)/2;
    }
    printf("the total from 1 to %d is %d\n",n,sum);
    return 0;
}