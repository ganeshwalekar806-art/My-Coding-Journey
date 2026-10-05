#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i,len=0;

    printf(" enter the your string : ");
    fgets(str,100,stdin);

    i=0;
    while(str[i]!='\0')
    {
        len++;
        i++;

    }

    i=len-2;
    while(i>=0)
    {
        printf(" reverse string is : %c\n",str[i]);
        i--;
    }

    return 0;
    

}