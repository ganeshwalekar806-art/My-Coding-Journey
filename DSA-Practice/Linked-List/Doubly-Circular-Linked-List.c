#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *prev;
    int ele;
    struct node *next;
};

struct node *first;

void insert_node()
{
    struct node *nn,*temp,*temp2;
    int sel,ch;

    nn = (struct node *)malloc(sizeof(struct node));

    printf("ENTER ELEMENT: ");
    scanf("%d",&nn->ele);

    nn->next = nn;
    nn->prev = nn;

    if( first == NULL)
    {
        first = nn;
    }
    else
    {
        printf("\n\n1 => INSERT AT FIRST POSITION\n");
        printf("2 => INSERT AT LAST POSITION \n");
        printf("3 => INSERT AT SPECIFIC POSITION\n\n");
        printf("ENTER INSERT POSITION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // NEW NODE INSERT AT FIRST POSITION

               nn->prev = first->prev;
               first->prev = nn;
               nn->next = first;
               first->next = nn;
               first = nn;

               printf("\nNEW NODE AT INSERTED AT FIRST POSITION\n");

               break;

            case 2: // NEW NODE INSERT AT LAST POSITION 
            
                temp = first;

                do
                {
                    temp = temp->next;

                } while (temp->next!=first);

                nn->next = temp->next;
                nn->prev = temp;
                first->prev = nn;

                printf("\nNEW NODE INSERTED AT LAST POSITION\n");

                break;

            case 3: // NEW NODE INSERTED AT SPECIFIC NODE     

                printf("ENTER ELEMENT NODE TO INSERT NEW NODE : ");
                scanf("%d",&sel);

                temp = first;
                int flag = 1;
                
                do
                {
                    if(temp->ele == sel)
                    {
                        flag = 2;
                        break;
                    }

                    temp = temp->next;

                } while (temp->ele != sel && temp!=first);
                
               if(flag == 1)
               {
                 printf("\n NO SUCH NODE IS FOUND\n");
               }
               else
               {
                  temp2 = temp->next;
                  nn->next = temp->next;
                  temp->next = nn;
                  nn->prev = temp;
                  temp2->prev = nn;

                  printf("\nNEW NODE INSERTED AT SPECIFIC POSITION\n");

               }

               break;

        } // END OF SWITCH CASE 
    } // END OF ELSE STATEMENT 
} // END OF insert_node FUNCTION

void remove_node()
{
    struct node *temp,*nn,*temp2,*temp3;
    int sel,ch;

    if(first == NULL)
    {
        printf("\nLIST IS NOT CREATED\n");
    }
    else if(first == first->next)
    {
        temp = first;
        free(temp);
        first = NULL;

        printf("\nLIST CREATED ONLY ONE NODE AND IT IS REMOVED\n");
    }
    else
    {
        printf("\n\n1 => REMOVE FIRST NODE\n");
        printf("2 => REMOVE LAST NODE\n");
        printf("3 => REMOVE SPECIFIC NODE \n\n");
        printf("ENTER REMOVE NODE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // REMOVE FIRST NODE 

                  temp = first;
                  temp2 = first->next;
                  temp2->prev = first->prev;
                  temp3 = temp2->prev;;
                  temp3->next = temp2;
                  first = first->next;

                  printf("\nFIRST NODE IS REMOVED\n");

                  break;

            case 2: // REMOVE LAST NODE 
            
                 temp = first->prev ;
                 temp2 = temp->prev;
                 temp2->next = temp->next;
                 first->prev = temp2;
                 free(temp);

                 printf("\n LAST NODE IS REMOVED \n");

                 break;

            case 3: // REMOVE SPECIFIC NODE 
                
                printf("ENTER NODE ELEMENT TO REMOVE: ");
                scanf("%d",&sel);
            
                 temp = first;
                 int flag = 1;

                 do
                 {
                    if(temp->ele == sel)
                    {
                        flag = 2;
                        break;
                    }

                    temp = temp->next;
                    
                 } while (temp->next != first);

                 if(flag == 1)
                 {
                    printf("\nNO SUCH NODE IS FOUND\n");
                 }
                 else if(flag == 2 && temp == first )
                 {
                    // LOGIC OF REMOVE FIRST NODE 

                      temp = first;
                      temp2 = first->next;
                      temp2->prev = first->prev;
                      temp3 = temp2->prev;;
                      temp3->next = temp2;
                      first = first->next;

                      printf("\n SPECIFIED NODE IS REMOVED\n");

                 }
                 else if(flag == 2 && temp->next == first)
                 {
                    // LOGIC TO REMOVE LAST NODE 

                    temp = first->prev ;
                    temp2 = temp->prev;
                    temp2->next = temp->next;
                    first->prev = temp2;
                    free(temp);

                    printf("\nSPECIFIED NODE IS REMOVED\n");

                 }
                 else
                 {
                    temp2 = temp->prev;
                    temp3 = temp->next;

                    temp2->next = temp->next;
                    temp3->prev = temp->prev;

                    printf("\nSPECIFIED NODE IS REMOVED \n");

                 }

                 break;

        } // END OF SWITCH CASE 
    } // END OF ELSE STATEMENT 
} // END OF remove_node FUNCTION

// FUNCTION FOR DISPLAY LIST 
void display_list()
{
    struct node *temp,*temp2;
    int ch;

    if( first == NULL)
    {
        printf("\nLIST IS NOT CREATED \n");
    }
    else
    {
        printf("\n\n1 => DISPLAY IN FRONT FORM \n");
        printf("2 => DISPLAY IN REVERSE ORDER \n");
        printf("ENTER YOU WANT TO DISPLAY: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // DISPLAY IN  FRONT ORDER  

            temp = first;

            do
            {
                printf("%d\t",temp->ele);
                temp = temp->next;
            }while(temp!=first);

            printf("\n\n");

            break;

            case 2: // DISPLAY IN REVERSE ORDER 
                
                temp = first->prev;     

                  temp2 = temp->prev;

                  do
                  {

                    printf("%d\t",temp2->ele);
                    temp2 = temp2->prev;

                  }while(temp2->prev!=temp);

                  printf("\n\n");

                  break;


        }
        

    } 
} // END OF display_list FUNCTION 

int main()
{
    int ch;
    first = NULL;

    while(1)
    {
        printf("\n1 => INSERT NODE OPRATION \n");
        printf("2 => REMOVE NODE OPRATION\n");
        printf("3 => DISPLAY LIST OPRATION\n");
        printf("4 => EXIT OPRATION\n\n");
        printf("ENTER YOUR OPRATION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // INSERT NODE OPRATION 
             
                 insert_node();

                 break;

            case 2: // REMOVE NODE OPRATION
            
                 remove_node();

                 break;

            case 3: // DISPLAY NODE OPRATION 
            
                 display_list();

                 break;

            case 4: // EXIT OPRATION
            
                 exit(0);

                 break;

        } // END OF SWITCH CASE 

    } // END OF WHILE LOOP

    return 0;

} // END OF INT MAIN 