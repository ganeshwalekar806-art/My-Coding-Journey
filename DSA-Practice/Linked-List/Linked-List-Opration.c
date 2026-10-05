#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int ele;
    struct node *next;
};

int main()
{
    struct node *nn,*first,*temp;
    int ch;
    first = NULL;

    while(1)
    {
        // LINKED LIST OPRATIONS 

        printf("1 => ADD NEW ELEMENT\n");
        printf("2 => DISPLAY ALL ELEMENTS\n");
        printf("3 => SUM OF ALL ELEMENTS\n");
        printf("4 => VALUE OF FIRST NODE ELEMENT\n");
        printf("5 => VALUE OF LAST NODE ELEMENT\n");
        printf("6 => EXIT\n\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // ADD NEW ELEMENT AND ADD NEW NODE IN LINKED LIST 

               // ALOCATE MEMOEY FOR NEW NODE 

                nn = (struct node *)malloc(sizeof(struct node)); 

                printf("enter element: ");
                scanf("%d",&nn->ele);

                nn->next = NULL;

                // CHECK LINKED LIST IS EMPTY 
                if(first == NULL)
                {
                    first = nn;
                }
                else
                {
                    temp = first;

                    // TRAVERSE LINKED LIST 
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    }

                    temp->next = nn; // ATTACH NEW NODE AT LAST 
                }
                
                printf("NEW ELEMENT IS SUCCESSFULLY ADDED\n\n");

                break;

                case 2: // DISPLAY ALL ELEMENTS

                temp = first;

                while(temp!=NULL)
                {
                    printf("%d\t",temp->ele); // PRINT LINKED LIST ELEMENT 

                    temp = temp->next;
                }

                printf("\n");

                break;

                case 3: // SUM OF ALL ELEMENTS

                temp = first;
                int sum = 0;

                // SUM OF ALL ELEMENTS 
                while(temp!=NULL)
                {
                    sum = sum + temp->ele;
                    temp = temp->next; // INCREMENT 
                }
                printf("SUM OF ALL NOES ELEMENTS IS %d \n",sum);
                
                break;

                case 4: // VALUE OF FIRST NODE ELEMENTS 

                temp = first;

                printf("VALUE OF FIRST NODE ELEMENTS IS %d \n\n",temp->ele);  // PRINT VALUE OF FIRST NODE 

                break;

                case 5: // VALUE OF LAST NODE ELEMENTS 

                temp = first;

                // TRAVERSE LINKED LIST 
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                } // AT THE END TEMP POINTS TO LAST NODE 

                printf("VALUE OF LAST NODE ELEMENTS ID %d\n\n",temp->ele); // PRINT LAST NODE SS

                break;

                case 6: // exit opration

                exit(1);

                break;

        }// end of outer switch case

    }// end of while loop

    return 0;

}// end of main program end of int main programm