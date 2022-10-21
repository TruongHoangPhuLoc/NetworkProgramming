#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void inputArray(int* array,int elements)
{
    for(int i = 0;i<elements;i++)
    {
        printf("Enter the value of array[%d]\n",i);
        scanf("%d",&array[i]);
    }
}
void outputArray(int* array, int elements)
{
    for (int i = 0; i < elements; i++)
    {
        printf("Arr[%d] is %d\n",i,array[i]);
    }
}
int totalOfArray(int* array, int elements)
{
    int sum =0;
    for(int i = 0;i<elements;i++)
    {
        sum += array[i];
    }
    return sum;
}
int* findBiggestValue(int* array, int elements)
{
    int max = array[0];
    int index = 0;
    for(int i = 1;i<elements;i++)
    {
        if(max > array[i])
        {
            max = array[i];
            index = i;
        }
    }
    ///Return an array with array[0] is the biggest value and array[1] is an index of the biggest value
    int* result = (int*)calloc(2,sizeof(int));
    result[0] = max;
    result[1] = index;
    return result;
}
int* findSmallestValue(int* array, int elements)
{
    int min = array[0];
    int index = 0;
    for(int i = 1;i<elements;i++)
    {
        if(min < array[i])
        {
            min = array[i];
            index = i;
        }
    }
    ///Return an array with array[0] is the smallest value and array[1] is an index of the smallest value
    int* result = (int*)calloc(2,sizeof(int));
    result[0] = min;
    result[1] = index;
    return result;
}
void findAndSwapPositions(int* array, int elements)
{
    int* theBiggestValue = findBiggestValue(array,elements);
    int* theSmallestValue = findSmallestValue(array,elements);
    ///Swapping
    int temporaryValue = theBiggestValue[0];
    ///Assign smallest value to index of biggest value
    array[theBiggestValue[1]] = theSmallestValue[0];
    ///Assign biggest value to index of smallest value
    array[theSmallestValue[1]] = temporaryValue;
}
int isAscendingArray(int* array, int elements)
{
    for(int i = 0;i<elements-1;i++)
    {
        if(array[i]>array[i+1])
        {
            return 0;
        }
        return 1;
    }
}

int isPrimeNum(int n)
{
    if(n<2)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void outputPrimeNumInOddPos(int *array, int elements)
{
    for(int i = 1; i<elements;i+=2)
    {
        if(isPrimeNum(array[i]) == 1)
        {
            printf("The %d is prime number at index %d\n",array[i],i);
        }
    }
    printf("\n");
}
void printOddNumbersAndBiggestOddNumber(int* array, int elements)
{
    int max = array[0];
    for(int i = 0;i<elements;i++)
    {
        if(array[i]%2 != 0)
        {
            printf("%d is odd number\n",array[i]);
        }
        if(array[i]>max)
        {
            max = array[i];
        }
    }
    printf("The biggest odd number is %d\n",max);
}
void outputSquareNumber(int a, int b, int n)
{
    int count = 0;
    for(int i = a;i<=b && count < n;i++)
    {
        double square = sqrt(i);
        if(i == 1 )
        {
            continue;
        }
        if(square == (int)square)
        {
            count ++;
            printf("%.0lf is square of %d\n",square,i);
        }
    }
    printf("\n");
}
int greatestCommonDivisor(int a, int b)
{
    int max = (a>b)?a:b;
    int result = 0;
    for(int i = 1; i <= max;i++)
    {
        if(a % i == 0 && b % i == 0 && result < i)
        {
            result = i;
        }
    }
    return result;
}