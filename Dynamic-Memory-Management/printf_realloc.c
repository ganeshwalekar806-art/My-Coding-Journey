#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p1;
    float *p2;
    char *p3;
    int i;
    int num;

    printf("enter number of an elements :\n");
    scanf("%d",&num);

    p1=(int *)calloc(2,sizeof(int));
    p2=(float *)calloc(4,sizeof(float));
    p3=(char *)malloc(sizeof(char));

    p1=(int *)realloc(p1,num*sizeof(int));
    p2=(float *)realloc(p2,num*sizeof(float));
   
    printf("enter elements of an p1 array :\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&p1[i]);
    }

    printf("enter elements of an p2 array: \n");
    for(i=0;i<num;i++)
    {
        scanf("%f",&p2[i]);
    }

    printf("enter elements of an p3: \n ");
    scanf(" %c",p3);

    printf("entered elements of an p1 array:\n");
    for(i=0;i<num;i++)
    {
        printf("%d\n",p1[i]);
    }

    printf("entered elements of an p2 array:\n");
    for(i=0;i<num;i++)
    {
        printf("entered elements of an array p2:%f\n",p2[i]);
    }

    printf("entered elements of an p3:%c",*p3);

    free(p1);
    free(p2);
    free(p3);

    return 0;
}