#include<stdio.h>
#include<stdlib.h>
#define max 5

int main()
{
    int queue[max];
    int front=0,rare=-1;
    int i,ch,ele;

    while(1)//starting point while loop
    {
        printf("\n\n\n1 => ENQUEUE OPRATION\n");
        printf("2 => DEQUEUE OPRATION\n");
        printf("3 => DISPLAY OPRATION\n");
        printf("4 => EXIT OPRATION\n\n\n");
        printf("enter your choice: ");
        scanf("%d",&ch);

        switch(ch)//starting point of switch case 
        {
            case 1: // performing ENQUEUE OPRATION 

            if(front == (rare+1)%max && rare >= 0)
            {
                printf("\nQUEUE IS OVERFLOW\n");
            }
            else
            {
                printf("enter the element: ");
                scanf("%d",&ele);

                rare = (rare+1) % max;
                queue[rare] = ele;

                printf("\n%d element is enqued in queue ",ele);

            }
            break;

            case 2: // performing dequeue opration 

            if(front == 0 && rare == -1)
            {
                printf("\nQUEUE IS UNDERFLOW\n");
            }
            else
            {
                printf("%d element is dequeued on queue",queue[front]);

                front = (front +1) % max;

                if(front == (rare+1) %max)
                {
                    front = 0;
                    rare = -1;
                }

            }
            break;

            case 3: // performing display opration 

            if(front == 0 && rare == -1)
            {
                printf("\nqueue is empty nothing to perform display opration \n");
            }
            else
            {
                i = front;

                while(i != (rare+1) % max )  
                {
                    printf("%d\t",queue[i]);

                    i = (i+1) % max;
                }
            }
            break;

            case 4: // performing exit opration 

            exit(1);

        }// end of switch case

    } // end of while loop

    return 0;

}//end of int main means emd of main programm exeution 

/* i = front;

do
{
    printf("%d\t",queue[i]);

    i = (i+1) % max;

}while(i != (rare+1) % max); */ 



/* i = front 

while(i < = rare)
{
   printf("%d\t",queue[i]);

   i = (i+1) % max;

   if(i == (rare+1) % max)
   { 
       break;
   }
       
}*/
