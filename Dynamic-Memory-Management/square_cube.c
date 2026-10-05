#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p1, *p2, *p3;

    p1=(int *)malloc(sizeof(int));
    p2=(int *)malloc(sizeof(int));
    p3=(int *)malloc(sizeof(int));

    printf("enter any number: ");
    scanf("%d",&*(p1));

    *p2=(*p1) * (*p1);
    *p3=(*p1) * (*p1) * (*p1);

    printf("square of %d = %d\n",(*p1),(*p2));
    printf("cube of %d = %d\n",(*p1),(*p3));

    return 0;
    

}