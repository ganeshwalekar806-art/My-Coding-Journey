#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int lar,sec;
    int i;

    p=(int *)calloc(6,sizeof(int));

    printf("enter elements of an array \n");
    for(i=0;i<=5;i++)
    {
        scanf("%d",&p[i]);
        lar = p[0];
    }

    for(i=0;i<=5;i++)
    {
        if(p[i]>lar)
        {
            sec=lar;
            lar=p[i];
        }
    }

    printf("second largest element in an array is %d",sec);

    return 0;

    
}