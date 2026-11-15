#include<stdio.h>

int main()
{
    int a[100],num,i,gap,temp;

    printf("ENTER ARRAY SIZE: ");
    scanf("%d",&num);

    printf("\nENTER ARRAY ELEMENT : ");
    for(i=0;i<=num-1;i++)
    {
        scanf("%d",&a[i]);
    }

    // MAIN LOGIC OF SHELL SORT 

    gap = num / 2;
    while(gap >= 1)
    {
        for(i=0;i<=num-1-gap;i++)
        {
            if(a[i] > a[gap+i])
            {
                temp = a[i];
                a[i] = a[gap+i];
                a[gap+i] = temp;
            }
        }

        gap--;
    }

    printf("AFTER SORTED ARRAY : ");

    for(i=0;i<=num-1;i++)
    {
        printf("%d\t",a[i]);
    }

    return 0;

}