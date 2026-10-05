#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1, *p2, *p3; 

    p1 = (int *)malloc(sizeof(int));
    p2 = (int *)malloc(sizeof(int));
    p3 = (int *)malloc(sizeof(int));

    printf("enter any first numbers:");
    scanf("%d",&*(p1));

    printf("enter any second number:");
    scanf("%d",&(*p2));

    *p3 = *p1 + *p2; 

    printf("addition of %d + %d =  %d",(*p1),(*p2),(*p3));


    return 0;
}