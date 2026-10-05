#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int i;

    p = (int *)calloc(5, sizeof(int));

    printf("enter 5 elements of an array: ");
    for(i = 0; i <= 4; i++)
    {
        scanf("%d", &p[i]); // किंवा (p + i)
    }

    printf("the elements of the array are:\n");
    for(i = 0; i <= 4; i++)
    {
        printf("%d ", p[i]); // इथे दुरुस्ती केली आहे
    }

    return 0;
}