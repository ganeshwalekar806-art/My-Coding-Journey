#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int lar;

    p = (int *)calloc(5, sizeof(int));

    printf("enter 5 elements in an array\n");
    for(int i =0 ;i<=4;i++)
    {
        scanf("%d",&p[i]);
        lar = p[0];
    }

    for(int i=0;i<=4;i++)
    {
        if(p[i]>lar)
        {
            lar = p[i];
        }
    }

    printf("largest element in an array is %d",lar);

    return 0;
}