#include<stdio.h>
#include<stdlib.h>
int main()
{
    char string1[] = "Hello";
    char string2[] = "World";
    ///calculate the length of 2 strings
    int n1 = 0;
    while(string1[n1] != '\0')
    {
        n1++;
    }
    int n2 = 0;
    while(string2[n2] != '\0')
    {
        n2++;
    }
    int n = n1 + n2;
    ///Dynamic allocation for new string
    char* string3 = (char*) calloc(n+1,sizeof(char)); 
    ///copy

    ///string1 into string3;
    ///current index for string3
    int currentindex=0;
    for(int i = 0;i<n1;i++)
    {
        string3[currentindex] = string1[i];
        currentindex++;
    }
    ///string2 into string3
    for(int i = 0;i<n2;i++)
    {
        string3[currentindex] =  string2[i];
        currentindex++;
    }
    string3[currentindex] = '\0';
    printf("length of 2 strings is %d\n",n);
    printf("current index is %d\n",currentindex);
    printf("%s\n",string3);

    ///taking the memory allocated back to OS
    free(string3);

}