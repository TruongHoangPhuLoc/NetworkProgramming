///reverse string without using library functions
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char string[] = "Phu Loc";
    ///method used to reverse string is create temp string

    ///count the length of string
    int length = 0;
    while(string[length] != '\0')
    {
        length++;
    }
    ///use dynamic allocation for creating new string
    char* newstring = (char*) calloc(length + 1,sizeof(char));
    ///use temp for decreased iteration of string
    int temp = length - 1;
    for(int i = 0;i<length;i++)
    {
        newstring[i] = string[temp];
        temp--;
    }
    string[length + 1] = '\0';
    printf("New String is %s\n",newstring);
    //free space allocated
    free(newstring);
}