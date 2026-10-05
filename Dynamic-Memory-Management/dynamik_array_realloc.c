#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int capacity = 2;
    int size = 0;
    int num;

    p = (int *)calloc(capacity, sizeof(int));

    while(1)
    {
        printf("enter number (-1 to stop): ");
        scanf("%d",&num);

        if(num == -1)
        {
            break;
        }

        if(size == capacity)
        {
            capacity = capacity * 2;
            p = (int *)realloc(p, capacity * sizeof(int));
        }

        p[size] = num;
        size++;

    }

    printf("the elements of an array are: ");

    for(int i=0;i<size;i++)
    {
        printf("%d",p[i]);
    }

    free(p);

    return 0;

}