#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i,len=0;

    printf(" enter the string : ");
    fgets(str,100,stdin);

    i=0;
    while(str[i]!='\0')
    {
        len++;
        i++;

    }

    printf(" first character is : %c\n",str[0]);
    printf(" last character is : %c\n",str[len-2]);

    return 0;

    
}