#include<stdio.h>

int main()
{
    ///our array has 5 elements
    int array[5];
    for(int i = 0;i<5;i++)
    {
        printf("Enter the value of array[%d]\n",i);
        scanf("%d",&array[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Arr[%d] is %d\n",i,array[i]);
    }
    
}