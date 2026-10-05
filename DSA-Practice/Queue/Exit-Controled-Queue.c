#include<stdio.h>
#include<stdlib.h>
#define max 10

int main()
{
    int queue[max];
    int front = 0;
    int rare = -1;
    int ch,ele;
    int count = 0;

    while(1)
    {
        printf("\n\n1 -> ENQUEUE OPRATION \n");
        printf("2 -> DEQUEUE OPRATION\n");
        printf("3 -> DISPLAY OPRATION \n");
        printf("4 -> EXIT OPRATION \n\n");
        printf("enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // PERFORMING ENQUEUE OPRATION ON BOTH SIDE

                 while(1)
                 {
                    printf("\n\n1 -> ENQUEUE OPRATION ON FRONT SIDE\n");
                    printf("2 -> ENQUEUE OPRATION ON RARE SIDE\n\n");
                    printf("enter your choice: ");
                    scanf("%d",&ch);

                    switch(ch)
                    {
                        case 1: // PERFORMING ENQUEUE OPRATION ON FRONT SIDE

                        if(front == max -1 || rare == max -1)
                        {
                            printf("QUEUE IS OVERFLOW\n");
                        }
                        else
                        {   
                            if(rare > 0) //for if the enqueue opration is perform on the first on their original side not perform enqueue opration on front side 
                            {
                                printf("do not perform enqueue opration bracuase of allready enqueud on rare side\n");
                            }
                            else
                            {
                                front = 9; // for to perform enqueue opration first on front side that was front is initialize to 9 
                        
                            printf("enter element you are enqueue: ");
                            scanf("%d",&ele);

                            queue[front] = ele;
                            front--;

                            printf("ELEMENT IS SUCCESSFULLY ENQUEUED FROM FRONT\n");
                            count = 1; // enqueue opration is perform on first on front side 
                            
                             }
                            
                        }

                        break;

                        case 2: // PERFORMING ENQUEUE OPRATION FRON RARE OR ORIGINAL SIDE

                        if(front == max -1 || rare == max-1)
                        {
                            printf("QUEUE IS OVERFLOW\n");
                        }
                        else
                        {
                            if(front < 9 )// for if enqueue opration is perform  first front side that was do not perform enqueue opration on this original side 
                            {
                                printf("do not perform enqueue because of allready enqueued from front side\n ");
                            }
                            else
                            {
                                front = -1;
                                printf("enter ele: ");
                                scanf("%d",&ele);

                                queue[rare+1]=ele;

                                printf("element is successfully inqueued from rare ");

                                count = 2 ; // for enqueue popration is perform first on rare side 

                            }

                        }

                        break;

                    }// end of inner switch case

                    break;

                 }// end of inner while loop

            case 2: // PERFORMING DEQUEUE OPRATION 

            if(front > rare || front == rare + 1 && front == 9 )
            {
                printf("QUEUE IS UNDERFLOW\n");
            }
            else
            {
                printf("%d element is successsfully dequeue \n",queue[front+1]);
                front++;

                printf("element is successfully  dequeue \n");
            }

            break;

            case 3: // PERFORMING DISPLAY OPRATION

            if(count == 1) // for if the enqueue opration is perform first on front side
            {
                for(int i =front ; i <=9 ; i++)
                {
                    printf("%d\t",queue[i]);
                }

            }

            else// for if the enqueue opration is perform first on rare side 
            {
                for(int i = front ; i <= rare ;i++)
                {
                    printf("%d\t",queue[i]);
                }
            }

            break;

            case 4: // PERFORMING EXIT OPRATION 

            exit(1);

            break;

        }// end of outer switch case 

    }// end of outer while loop

    return 0;

} // end of main program exucution  