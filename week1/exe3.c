#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Enter number a,b,c repsectively:\n");
    scanf("%d %d %d",&a,&b,&c);
    int max = a;
    if (max < b)
    {
        max = b;
    }
    if (max < c)
    {
        max = c;
    }
    printf("the biggest one is %d\n",max);
    return 0;
}
