#include<stdio.h>

int main()
{
    int a[100],num,i,j,temp;

    printf("ENTER ARRAY SIZE : \n");
    scanf("%d",&num);

    printf("ENTER ARRAY ELEMENT : \n");
    for(i=0;i<=num-1;i++)
    {
        scanf("%d",&a[i]);
    }

    // ARRAY SORTED MAIN LOGIC 

    for(i=0;i<=num-2;i++)
    {
        for(j=0;j<=num-2-i;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // ARRAY WAS SORTED 

    printf("SORTED ARRAY WAS : ");

    for(i=0;i<=num-1;i++)
    {
        printf("%d\t",a[i]);
    }

    return 0;
}