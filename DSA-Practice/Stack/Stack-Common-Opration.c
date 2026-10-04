#include<stdio.h>
#include<stdlib.h>
#define max 10
int main()
{
    int stack[max];
    int top = -1;
    int i, ch , ele;

    while(1)
    {
        printf("\n\n\n= = = = = select your opration: = = = = = =\n\n");
        printf("1 => PUSH opration\n");
        printf("2 => POP opration\n");
        printf("3 => is full\n");
        printf("4 => is empty\n");
        printf("5 => get top element\n");
        printf("6 => get total element\n");
        printf("7 => total capacity\n");
        printf("8 => display opration\n");
        printf("9 => exit\n");
        printf("\n\n = = = = = = provide your opration = = = = = = = = \n\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // performing PUSH opration 
            
            if( top == max-1)
            {
                printf("STACK OVERFLOW\n");
            }
            else
            {
                printf("enter elments for PUSH opration:");
                scanf("%d",&ele);

                stack[top+1]=ele;
                top++;

            }

            break;

            case 2: // performing POP opration

            if(top == -1)
            {
                printf("STACK UNDERFLOW\n");
            }

            else
            {
                printf("\n\nelement %d is poped down\n\n",stack[top]);
                top--;

            }
            break;

            case 3: //peroforming stack is full or not 

            if( top == max-1)
            {
                printf("stack is allready full\n");
            }
            else
            {
                printf("stack is not full\n");
            }

            break;

            case 4:// peroforming stack is empty or not opration

            if( top == -1)
            {
                printf("stack is allready empty\n");

            }
            else
            {
                printf("stack is not empty\n");

            }

            break;

            case 5: // performing top element in stack

            printf("top element =%d\n",stack[top]);

            break;

            case 6: // proforming total element in stack opration
             
            printf("total elements = %d\n",top+1);

            break;

            case 7: // peroforming total capacity opration

            printf("total capacity =%d\n",max);

            break;

            case 8: // peroforming display opration

            if(top == -1)
            {
                printf("stack is empty nothing in stack\n");

            }
            else
            {
                for(i=top;i>=0;i--)
                {
                    printf("%d\n",stack[i]);
                }
            }

            break;

            case 9: // proforming exit opration
            exit(0);

        }// end of switch case

    } // end of while loop

    return 0;
}