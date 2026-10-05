#include<stdio.h>
#include<stdlib.h>
#define max 10

int main()
{
    int queue[max];
    int front = 0;
    int rare = -1;
    int ch,ele;

    while(1)
    {
        printf("\n\n\n1 -> ENQUEUE OPRATION\n");
        printf("2 -> DEQUEUE OPRATION\n");
        printf("3 -> DISPLAY OPRATION\n");
        printf("4 -> EXIT OPRATION\n\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // PERFORMING ENQUEUE OPRATION 

            if( rare == max -1)
            {
                printf("QUEUE IS OVERFLOW \n"); // QUEUE IS ALLREADY FULL
            }
            else
            {
                printf("enter any element: ");
                scanf("%d",&ele);

                queue[rare+1] = ele;
                rare++;

                printf("ELEMENT IS SUCCESFULLY ENQUEUED IN QUEUE\n");

            }

            break;

            case 2: // PERFORMING DEQUEUE OPRATION ON BOTH RARE AND FRONT SIDE 

            while(1)
            {
                printf("\n\n1 -> DEQUEUE FROM FRONT\n");
                printf("2 -> DEQUEUE FROM RARE\n");
                printf("ENTER YOUR CHOICE: ");
                scanf("%d",&ch);

                switch(ch)
                {
                    case 1: // PERFORMING DEQUEU FROM FRONT

                    if(front > rare || front == rare + 1)
                    {
                        printf("QUEUE IS ONDERFLOW\n");
                    }
                    else
                    {
                        printf("%d ELEMENT IS SUCCESSFULLY DEQUEUED FROM QUEUE\n",queue[front]);
                        front++;

                    }

                    break;

                    case 2: // PERFORMING DEQUE OPRATION FROM RARE

                    if( rare == -1)
                    {
                        printf("QUEUE IS UNDERFLOW\n");
                    }
                    else
                    {
                        printf("%d ELEMENT IS SUCCESSFULLY FROM QUEUE\n",queue[rare]);
                        rare--;
                    }
                    break;

                } // end of inner switch case 
                break;
            }// end of inner while loop

            break;

            case 3: // PERFORMING DISPLAY OPRATION 

            if(front == rare + 1 || rare == -1)
            {
                printf("QUEUE IS EMPTY DO NOT PERFOEM DISPLAY OPRATION \n");
            }
            else
            {
                for( int i = front;i <= rare;i++)
                {
                    printf("%d\t",queue[i]);
                }

            }
            
            break;

            case 4: // PERFORMING EXIT OPRATION 

            exit(1);

            break;

        }// end of outer switch case 

    } // end of outer while loop

    return 0;
    
}