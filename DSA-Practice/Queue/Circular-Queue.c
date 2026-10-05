#include<stdio.h>
#include<stdlib.h>
#define max 5

int main()
{
    int queue[max];
    int front = 0;
    int rare = -1;
    int i,ch,ele;

    while(1)
    {
        printf("\n\n1 => ENQUEUE OPRATION \n"); // performing enqueue opration 
        printf("2 => DEQUEUE OPRATION \n"); // perform dequeue opration 
        printf("3 => DISPLAY OPRATION \n"); // perform display opration 
        printf("4 => EXIT OPRATION \n\n"); //perform exit opration 
        printf("enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // PERFORMING ENQUEUE OPRATION 
             
            if(front == (rare + 1) % max && rare >= 0) // front == (rare+1)% max && rare >= 0 
            {
                printf("\nqueue is overflow nothing to perform enqueue opration \n");
            }
            else
            {
                printf("enter the element : ");
                scanf("%d",&ele);

                rare = (rare+1) % max; // rare = rare+1 % max
                queue[rare] = ele;

            }

            break;

            case 2: // PERFORMING DEQUEUE OPRATION 

            if( front == 0 && rare == -1 ) // front == (rare+1) % max && front > rare 
            {
                printf("\nqueue is underflow nothing to perform dequeue opration \n");

            }
            else
            {
                printf("%d element is DEQUEUE ",queue[front]);

                front = (front + 1) % max; 

                if(front == (rare+1) % max) // if the font is == rare + 1% max the initialize front = 0 and rare = -1 ;
                {
                    front =0;
                    rare = -1;
                }
            }

            break;

            case 3: // DISPLAY OPRATION 

            if(front == (rare+1)%max && front > rare) // front == (rarre+1) % max && front > rare
            {
                printf("\nqueue is empty nothing to perform display opration\n");
            }
            else
            {
                int i = front;

                printf("circular queue element \n");

                while(1)
                {
                    printf("circular queue: %d\t",queue[i]);

                    if(i == rare) // if the front's value is equal to the rare value then break the while loop 
                    {
                        break;
                    }         

                    i = (i+1) % max ;

                }
                printf("\n");
            }

            break;

            case 4: //EXIT OPRATION 

            exit(0);

        } // end of switch case 

    } // end of while loop

    return 0;

} // end of main program 


