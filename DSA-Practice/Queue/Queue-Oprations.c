#include<stdio.h>
#include<stdlib.h>
#define max 10

int main()
{
    int queue[max];
    int rare=-1;
    int front=0;
    int i,ch,ele;
    int count=0;

    while(1)
    {
        printf("1 => ENQUEUE OPARTION \n ");
        printf("2 => DEQUEUE OPRATION \n ");
        printf("3 => IS FULL OR NOT  \n ");
        printf("4 => IS EMPTY OR NOT \n");
        printf("5 => GET-FROMNT-ELEMENT\n");
        printf("6 => GET-RARE-ELEMENT\n");
        printf("7 => GET=TOTAL-ELEMENT\n");
        printf("8 => GET-ELEMENT-COUNT\n");
        printf("9 => DIASPLAY \n");
        printf("10 => EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // PERFORM  ENQUEUE OPRATION ON QUEUE

            if(rare == max-1)
            {
                printf("queue is overflow\n");
            }
            else
            {
                printf("enter element you an enqueue in queue: ");
                scanf("%d",&ele);

                queue[rare+1]=ele;
                rare++;

                printf("%d element is enqueue in queue",ele);

            }
            break;

            case 2: // PERFROM DEQUEUE OPRATION ON QUEUE

            if(front>rare || front == rare+1)
            {
                printf("queue is underflow\n");
            }
            else
            {
                printf("%d element is dequeue in queue",queue[front]);
                front++;

            }
            break;

            case 3: // PERFORM QUEUE IS FULL OR NOT OPRATION 

            if(rare == max-1)
            {
                printf("queue is full\n"); // means queue is overflow
            }
            else
            {
                printf("queue is not full \n");
            }
            break;

            case 4: //PERFORM QUEUE IS EMPTY OR NOT OPRATION 

            if(front > rare || front == rare + 1)
            {
                printf("queue is empty\n");
            }
            else
            {
                printf("queue is not empty\n");
            }
            break;

            case 5: // PERFORM GET FRONT ELEMENT OPRATION 

            printf("front element = %d",queue[front]);

            break;

            case 6: // PERFORM QUEUE GET RARE ELEMENT 

            printf(" rare element = %d",queue[rare]);

            break;

            case 7: // PERFROM TOTAL CAPACITY ON QUEUE 

            printf(" total capacity of queue = %d",max);

            break;

            case 8: // PERFORM ELEMENT COUNT ON QUEUE

            if(front > rare || front == rare + 1)
            {
                printf(" queue is allready empty do not perform element count opration\n ");
            }
            else
            {
                for(i=front;i<=rare;i++)
                {
                    count ++;
                }

                printf("total element in queue: %d",count);
            }

            break;

            case 9: // PERFROM DISPLAY OPRATION 

            if(front > rare || front == rare+1)
            {
                printf(" queue is allready empty do not perform display oparation\n");
            }
            else
            {
                for(i=rare;i>=front;i--)
                {
                    printf("%d\n",queue[i]);

                }
            }
            break;

            case 10: // PERFORM EXIT OPRATION

            exit(0);

            break;

        } // end of switch case 
    }// end of while loop

    return 0;

}// end of main program 