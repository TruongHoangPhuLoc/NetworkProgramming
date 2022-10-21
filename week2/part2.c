#include<stdio.h>
#include"myheader.h"

int main()
{
    ///our array also has 5 elements again
     int array[5];
     inputArray(array,5);
     outputArray(array,5);
     printf("total of Array is %d\n",totalOfArray(array,5));
}