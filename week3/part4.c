///count a number of words in string
#include<string.h>
#include<stdio.h>
int main()
{
    ///assume the separation of words are spaces, commas,dots.
    ///in this example, I just use simple characters to indicate the isolation of words. In reality, there are more characters used to separate words in string.
    char string[] = "Hello World, My name is Phu Loc";
    ///total words of this string is 7
    int count = 0;
    for(int i =0;i<strlen(string);i++)
    {
        if(string[i] == '.' || string[i] ==',' || string[i]==' ')
        {
            count++;
        }
    }
    printf("Numbers of words in our string are %d\n",count);
}