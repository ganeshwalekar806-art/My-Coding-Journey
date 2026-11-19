#include<stdio.h>

int main()
{
    int a[10];
    int mid_ind,mid_ele,flag=1,num,size,i,j,index;

    printf("ENTER ARRAY SIZE:");
    scanf("%d",&size);

    printf("ENTER ARRAY ELEMENT: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }

    // FIRST STEP IS SORT ARRAY IN ASCINDING ORDER

    for(i=0;i<size;i++)
    {
        int sel_ele = a[i];
        for(j = i - 1;j >= 0 && sel_ele < a[j];j--)
        {
            a[j+1] = a[j];
        }

        a[j+1] = sel_ele;
    }

    printf("ENTER NUMBER YOU ARE FIND: ");
    scanf("%d",&num);

    // THEN APPLY MAIN BINARY SEACH LOGIC 

    mid_ind = size / 2;
    mid_ele = a[mid_ind];
    
    if(num == mid_ele)
    {
        flag = 2;
    }
    else if(num < mid_ele)
    {
        for(i=0;i<mid_ind-1;i++)
        {
            if(num == a[i])
            {
                flag = 2;
                index = i;
                break;
            }
        }

    }
    else if(num > mid_ele)
    {
        for(i = mid_ind+1;i<size;i++)
        {
            if(num == a[i])
            {
                flag = 2;
                index = i;
                break;
            }
        }
    }

    if(flag == 1)
    {
        printf("\nELEMENT IS NOT PREASENT\n ");
    }

    else if(flag == 2)
    {
        printf("\nELEMENT IS PRESENT AT INDEX NUMBER %d\n",i);
    }

    return  0;

}