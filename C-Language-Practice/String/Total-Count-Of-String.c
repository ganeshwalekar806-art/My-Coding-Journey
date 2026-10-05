#include<stdio.h>
#include<string.h>


int main()
{
    char str[100];
    int i,len=0;
    printf(" enter teh string : ");
    fgets(str,100,stdin);

    i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='a')
        {
            len++;
        }
        i++;

    }

    printf(" teh total charcter of 'a' is : %d",len);

    return 0;
}
