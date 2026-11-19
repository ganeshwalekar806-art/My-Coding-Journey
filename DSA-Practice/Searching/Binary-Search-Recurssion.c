#include<stdio.h>

int binary_search(int a[],int st,int end,int num)
{
    int mid_ind,mid_ele;
    int static flag = 1;

    if(end >= st)
    {
        
        mid_ind = (st+end) / 2;
        mid_ele = a[mid_ind];

        if(num == mid_ele)
        {
            flag = 2;
        }
        else if(num < mid_ele)
        {
            binary_search(a,st,mid_ind-1,num);
        }
        else if(num > mid_ele)
        {
            binary_search(a,mid_ind+1,end,num);
        }

        return flag;

    }
    
}

int main()
{
    int a[100],num,size,st,end,i;
    int result;

    printf("ENTER ARRAY SIZE : ");
    scanf("%d",&size);

    printf("\nENTER ARRAY ELEMENT: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    // IN BINARY SEARCH YOU MUST HAVE ASCINDING ORDER SORTED ARRAY 

    int sel_ind,sel_ele;

    for(sel_ind = 0;sel_ind < size;sel_ind++)
    {
        sel_ele = a[sel_ind];

        for(i = sel_ind - 1; i>=0 && a[i] > sel_ele ;i--)
        {
            a[i+1] = a[i]; 
        }

        a[i+1] = sel_ele;

    }

    st = 0;
    end = size;

    printf("ENTER ELEMENT YOU CAN SEARCH: ");
    scanf("%d",&num);

    result = binary_search(a,st,end,num);

    if(result == 1)
    {
        printf("\nELEMENT IS NOT PRESENT\n");
    }
    else if(result == 2)
    {
        printf("\nELEMENT IS PRESENT\n ");
    }

    return 0;
}