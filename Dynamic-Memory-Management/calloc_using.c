#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;

    p=(int *)calloc(3,sizeof(int));

    printf("enter the elements of an array: ");
    for(int i=0;i<=2;i++)
    {
        scanf("%d",&p[i]);

    }

    printf("the elements of an array are: ");
    for(int i=0;i<=2;i++)
    {
        printf("%d",p[i]);
    }

    free(p);

    return 0;



}