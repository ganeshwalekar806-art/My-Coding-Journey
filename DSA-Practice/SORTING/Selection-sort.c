#include<stdio.h>

int main()
{
    int a[100],temp,i,j,num;

    printf("ENTER ARRAY SIZE : ");
    scanf("%d",&num);

    printf("\nENTER ARRAY ELEMENT: \n");
    for(i=0;i<=num-1;i++)
    {
        scanf("%d",&a[i]);
    }

    // MAIN SELECTION SORT LOGIC

    for(i=0;i<=num-1;i++)
    {
        for(j=i+1;j<=num-1;j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("AFTER SORTED ARRAY: ");
    for(i=0;i<=num-1;i++)
    {
        printf("%d\t",a[i]);
    }

    return 0;
}