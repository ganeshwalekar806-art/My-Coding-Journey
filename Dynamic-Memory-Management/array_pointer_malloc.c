#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p[10];
    int *q;
    char ch;
    int i;
    int ind = 0;

    do
    {
        q = (int *)malloc(sizeof(int));

        printf("enter any number : ");
        scanf("%d",&(*q));

        p[ind] = q;

        ind ++;

        printf("do you want enter another number: ");
        scanf(" %c",&ch);

    } while(ch == 'y');

    for(int i = 0;i<=ind;i++)
    {
        printf("%d\n",(*p[i]));
    }
    
    return 0;
}