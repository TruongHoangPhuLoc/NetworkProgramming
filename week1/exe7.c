#include<stdio.h>
int main()
{
    int length, width;
    printf("Choose the measurement unit\n1.cm\n2.dm\n3.m\n");
    int choice;
    scanf("%d",&choice);
    printf("enter the length and width respectively:\n");
    scanf("%d %d",&length,&width);
    float perimeter = (length+width)*2;
    float area = length*width;
    switch (choice)
    {
    case 1: 
        // convert cm2 to m2
        perimeter = perimeter / 100;
        area = area / 10000;
        break;
    case 2:
        //convert dm2 to m2
        perimeter = perimeter / 10;
        area = area / 100;
        break;
    default:
        break;
    }
    printf("The perimeter is %.2fm\nThe area is %.2fm2\n",perimeter,area);
    return 0;
}