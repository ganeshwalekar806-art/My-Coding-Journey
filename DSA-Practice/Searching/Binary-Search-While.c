#include<stdio.h>

int main()
{
    int a[10],i,j,st,end,flag = 1,mid_ind,mid_ele;
    int num,size;

    printf("ENTER ARRAY SIZE : ");
    scanf("%d",&size);

    printf("ENTER ARRAY ELEMENT: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    // FIRST YOU CAN APPLY ANY OF SHORTING ALGORITHM 

    int sel_ind,sel_ele;

    for(sel_ind = 0;sel_ind<size;sel_ind++)
    {
        sel_ele = a[sel_ind];

        for(i = sel_ind - 1;i>=0 && a[i] > sel_ele;i--)
        {
             a[i+1] = a[i];
        }

        a[i+1] = sel_ele;

    }

    printf("ENTER ELEMENT YOU ARE SEARCH : ");
    scanf("%d",&num);

    st = 0;
    end = size;

    while(end >= st)
    {
        mid_ind = (st + end ) / 2;
        mid_ele = a[mid_ind];

        if(num == mid_ele)
        {
            flag = 2;
            break;
        }
        else if(num < mid_ele)
        {
            st = st;
            end = mid_ind - 1;
            continue;
        }
        else if(num > mid_ele)
        {
            st = mid_ind + 1;
            end = end;
            continue;
        }

    } // END WHILE LOOP

    if(flag == 1)
    {
        printf("\nELEMENT IS NOT PRESENT \n");
    }
    else if(flag == 2)
    {
        printf("ELEMENT IS PRESENT AT INDEX %d \n",mid_ind);
    }

    return 0;

}