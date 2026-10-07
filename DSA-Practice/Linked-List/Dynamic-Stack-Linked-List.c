#include<stdio.h>
#include<stdlib.h>

struct node
{
    int ele;
    struct node *next;

};

int main()
{
    struct node *first,*nn,*temp,*temp2;
    int ch;
    first = NULL;

    while(1)
    {
        printf("\n\n1 => PUSH OPRATION\n");
        printf("2 => POP OPRATION\n");
        printf("3 => DISPLAY OPRATION\n");
        printf("4 => EXIT OPRATION\n\n");
        printf("ENTER YOUR OPRATION : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // PUSH OPRATION 

            // ALLOCATE MEMORY FOR NEW NODE 
                 nn = (struct node *)malloc(sizeof(struct node));

                 printf("ENTER ELEMENT: ");
                 scanf("%d",&nn->ele);

                 nn->next = NULL;

                 // CHECK FIRST IS EMPTY OR NOT 
                 if( first == NULL)
                 {
                    first = nn;
                 }

                 else
                 {
                    // THIS LOGIC IS INSERT NEW NODE AT LAST POSITION IN SINGLY LINEAR LINKED LIST (SLLL)

                    temp = first;
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    } // AT THE END TEMP TO LAST NODE 

                    temp->next=nn;

                 }

                 printf("\nPUSH OPRATION PERFORMED\n");

                 break;

                 /* ANOTHER LOGIC IS INSERT NEW NODE AT FIRST POSITION IN SINGLY LINEAR LINKED LIST (SLLL) 
                 
                 else
                 {

                    nn->next = first;
                    first = nn;

                 }
                 
                  printf("PUSH OPRATION PERFORMED\n")

                  break;
                 
                 */

            case 2: // POP OPRATION
            
                 if( first == NULL)
                 {
                    printf("\nSTACK IS EMPTY UNDERFLOW\n");
                 }
                 else
                 {
                    // THIS LOGIC IS REMOVE LAST NODE IN SLLL

                    temp = first;

                    // TRAVERSE AT LAST NODE 
                    while(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }

                    temp2 = first;

                    // TRAVERSE AT SECOND LAST NODE 
                    while(temp2->next!=temp)
                    {
                        temp2 = temp2->next;
                    }

                    temp2->next = NULL;
                    free(temp);

                    printf("\nPOP OPRATIONIS PERFORMED\n");

                 }

                 break;

                 /* ANOTHER LOGIC IS REMOVE FIRST NODE IN SLLL
                 
                 else
                 {
                     temp = first;
                     first = first->next;
                     free(temp);

                 }
                     break;
                     
                 */

            case 3: // DISPLAY OPRATION

                 // THIS IS COMMON DISPLAY OPRATION

                 temp = first;

                 while(temp!=NULL)
                 {
                    printf("%d\n",temp->ele);
                    temp = temp->next;
                 }


                 break;

            case 4: // EXIT OPRATION
            
                 exit(0);

                 break;

        } // END OF SWITCH CASE

    } // END OF WHILE LOOP

    return 0;

} // END OF INT MAIN