#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p1;
    float *p2;
    char *p3;
    double *p4;
    long *p5;

    p1=(int *)malloc(sizeof(int));
    p2=(float *)malloc(sizeof(float));
    p3=(char *)malloc(sizeof(char));
    p4=(double *)malloc(sizeof(double));
    p5=(long *)malloc(sizeof(long));

    printf("enter the integer value: ");
    scanf("%d",&(*p1));

    printf("enter the value of float: ");
    scanf("%f",&(*p2));

    printf("enter the value of char: ");
    scanf(" %c",&(*p3));

    printf("enter the value of duble: ");
    scanf("%lf",&(*p4));

    printf("enter the value of long: ");
    scanf("%ld",&(*p5));

    printf("the integer value is: %d\n",*p1);
    printf("the float value is: %f\n",*p2);
    printf("the char value is: %c\n",*p3);
    printf("the double value is: %lf\n",*p4);
    printf("the long value is: %ld\n",*p5);

    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);


    return 0;
    
}