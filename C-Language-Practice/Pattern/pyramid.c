#include<stdio.h>

int main()
{
    int i,j,k,l;
    
    for(i=0;i<=5;i++)
    {
        for(j=5;j>=i;j--)
        {
            printf(" ");
        }

        for(k=0;k<=i;k++)
        {
            printf("%d",i);
        }

        for(l=0;l<=i;l++)
        {
            printf("%d",i);
        }
        printf("\n");

    }
    return 0;
}