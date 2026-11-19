#include<stdio.h>

int main()
{
    int a[10],i,j,num,size;
    int flag = 1,index; 

    printf("\nENTER ARRAY SIZE: ");
    scanf("%d",&size);

    printf("\nENTER SEARCH ELEMENT: ");
    scanf("%d",&num);

    printf("\nENTER ARRAY ELEMENT:\n ");

    for(j=0;j<size;j++)
    {
        scanf("%d",&a[j]);
    }

    for(i=0;i<size;i++)
    {
        if(num == a[i])
        {
            flag = 2;
            index = i;
            break;
        }
    }

    if(flag == 1)
    {
        printf("\nELEMENT IS NOT PRESENT\n ");
    }
    else if(flag == 2)
    {
        printf("\nELEMENT IS PESENT\n ");
        printf("\nELEMENT INDEX NUMBER %d",index);
    }

    return 0;
    
}