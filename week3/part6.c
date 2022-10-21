#include<stdio.h>
#include<string.h>
int isRedundantSpace(char* string)
{
    for(int i = 0; i<strlen(string);i++)
    {
        if(string[i] == ' ' && string[i+1] == ' ')
        {
            ///return redundant space being an i + 1
            return i+1;
        }
    }
    ///return -1 when not fiding any redundant space
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
    char string[] = "Phu       Loc";
    ///our expectation is "Phu Loc";
    int index = isRedundantSpace(string);
    while(index != -1)
    {
        removeSpace(string,index);
        index = isRedundantSpace(string);
    }
    printf("%s\n",string);
}