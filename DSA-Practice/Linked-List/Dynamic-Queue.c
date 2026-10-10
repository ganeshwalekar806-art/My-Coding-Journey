#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int ele ;
    struct node *next;
};

int main()
{
    struct node *first,*nn,*temp,*temp2;
    first = NULL;
    int ch;

    while(1)
    {
        printf("\n\n1 => ENQUEUE OPRATION\n");
        printf("2 => DEQUEUE OPRATION\n");
        printf("3 => DISPLAY OPRATION\n");
        printf("4 => EXIT OPRATION\n\n");
        printf("ENTER YOUR OPRATION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // ENQUEUE OPRATION

                 nn = (struct node *)malloc(sizeof(struct node));

                 printf("ENTER ELEMENT: ");
                 scanf("%d",&nn->ele);

                 nn->next = NULL;

                 if(first == NULL)
                 {
                     first = nn;
                 }
                 else
                 {
                    temp = first;

                    while(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }

                    temp->next = nn;
                 }

                 printf("\nENQUEUE OPRATION IS PERFORMED \n");

                 break;

                 /* ANOTHER LOGIC IS INSERT NEW NODE AT FIRST POSITION IN SLLL 
                 
                 nn->next = first;
                 first = nn;
                 
                 */

            case 2: // DEQUEUE OPRATION

              if(first == NULL)
              {
                printf("\nQUEUE IS EMPTY UNDERFLOW\n");
              }
              else
              {
                 temp = first;
                 first = first->next;
                 free(temp);

                 printf("\nDEQUEUE OPRATION IS PERFORMED \n");

              }
                 break;

                 /* ANOTHER LOGIC IS TO REMOVE LAST NODE IN SLLL
                 
                 temp = first;
                 while(temp->next!=NULL)
                 {
                    temp = temp->next;
                 }
                    temp2 = first;
                   
                  while(temp2->next != temp)
                  {
                     temp2 = temp->next;
                  }   
                     
                  temp2->next = NULL;
                  free(temp);
                  
                  */

            case 3: // DISPLAY OPRATION 
            
               if(first == NULL)
               {
                printf("\nQUEUE IS EMPTY DO NOT PERFORM DISPLAY OPRATION\n");
               }
               else
               {
                  temp = first;

                  while(temp!=NULL)
                  {
                      printf("%d\t",temp->ele);
                      temp = temp->next;
                  }

               }

                break;

            case 4: // EXIT OPRATION
            
                exit(0);

                break;

        } // END OF SWITHC CASE 

    } // END OF WHILE LOOP

    return 0;
}