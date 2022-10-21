#include <stdio.h>
int main()
{
    int n;
    printf("enter n:\n");
    scanf("%d",&n);
    int max = n % 10;
    while(n > 0)
    {
        int digit = n % 10;
        if(max < digit)
        {
            max = digit;
        }
        n = n / 10;
    }
    printf("the biggest number of digits is %d\n",max);
    return 0;
}