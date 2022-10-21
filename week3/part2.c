#include <stdio.h>
int main()
{
    int count = 0;
    char foundchar;
    printf("Enter the character to find: ");
    scanf("%c",&foundchar);
    char string[] = "ccc";
    int i = 0;
    while(string[i] != '\0')
    {
        if(string[i] == foundchar)
        {
            count++;
        }
        i++;
    }
    printf("The number of foundchar %c is %d\n",foundchar,count);
}