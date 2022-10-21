///Write a function to remove spaces in string
#include<stdio.h>
#include<string.h>
int isAnySpace(char* string)
{
    for(int i =0;i<strlen(string);i++)
    {
        if(string[i] == ' ')
        {
            ///return index of space when finding out space
            return i;
        }
    }
    ///return -1 when not finding any space
    return -1;
}
void removeSpace(char* string,int indexofSpace)
{
    for(int i=indexofSpace;i<=strlen(string);i++)
    {
        string[i] = string[i+1];
    }
}
int main()
{
    char string[] = "My name is Phu Loc";
    ///expectation is MynameisPhuLoc
    ///test
    int index = isAnySpace(string);
    while(index != -1)
    {
        removeSpace(string,index);
        ///update index of space one more time.
        index = isAnySpace(string);
    }
    printf("%s\n",string);
}