#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,i;
    int *p;
    int temp;

    printf("enter number of elements in an array");
    scanf("%d",&num);

    p = (int *)calloc(num,sizeof(int));

    printf("enter elements of an array:\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&p[i]);
    }

    for(i=0;i<num;i=i+2)
    {
        temp=p[i];
        p[i]=p[i+1];
        p[i+1]=temp;

    }

    for(i=0;i<num;i++)
    {
        printf("after swaping an array elements are %d\n",p[i]);
    }

    return 0;

}