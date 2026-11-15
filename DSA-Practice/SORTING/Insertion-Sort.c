#include<stdio.h>

int main()
{
    int a[100],num,i,sel_ind,sel_ele;

    printf("ENTER ARRAY SIZE: ");
    scanf("%d",&num);

    printf("\nENTER ARRAY ELEMENT: \n");
    for(i=0;i<=num-1;i++)
    {
        scanf("%d",&a[i]);
    }

    // MAIN LOGIC OF INSERTION SERT 

    for(sel_ind = 0; sel_ind <= num-1 ; sel_ind++)
    {
        sel_ele = a[sel_ind];

        for(i = sel_ind -1 ; i >=0 && a[i] > sel_ele ; i--)
        {
            a[i+1] = a[i];
        }

        a[i+1] = sel_ele;

    }

    printf("AFTER SORTED ARRAY WAS : ");
    for(i=0;i<=num-1;i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;

}