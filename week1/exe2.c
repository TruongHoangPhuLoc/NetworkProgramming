#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter number a: ");
	scanf("%d",&a);
	printf("Enter number b: ");
	scanf("%d",&b);
	if(a<b)
	{
		printf("A is smaller than B");
	}
	else if(b<a)
	{
		printf("B is smaller than A");
	}
	else
	{
		printf("A is equal B");
	}
	printf("\n");
	return 0;
}
