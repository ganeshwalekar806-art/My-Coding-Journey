#include<stdio.h>
#include<stdlib.h>

struct node  // CREATE THE STRUCTURE AND TWO INSTANCES 1 --> ele 2 --> SELF REFERENCING INSTANCE 
{
    int ele;
    struct node *next;
};

struct node *first;

void insert_node() // FUNCTION FOR INSERT NODE OPRATIONS ON SINGLY CIRCULAR LINKED LIST [ SCLL ]
{
    struct node *nn,*temp;
    int ch,sel;

    nn = (struct node *)malloc(sizeof(struct node)); // TO CREATE A DYNAMIC MEMORY USING MALLOC AND STORE ADDRESS IN nn POINTER 

    printf("enter element : ");
    scanf("%d",&nn->ele); // ACCEPECT VALUE ELEMENT OF STRUCTURE 

    nn->next = nn;

    if(first == NULL)
    {
        first = nn;
    }

    else
    {   
        // INSERT NEW NODE OPRATIONS ON SINGLY CIRCULAR LINKED LIST 

        printf("\n\n1 => INSERT NODE AT FIRST POSITION \n");
        printf("2 => INSERT NODE AT LAST POSITION\n");
        printf("3 => INSERT NODE AT SPECIFIC POSITION\n\n");
        printf("ENTER YOU WANT TO INSERT NODE AT POSITION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // INSERT NEW NODE AT FIRST POSITION

            temp = first;

            do
            {
                temp = temp->next;
                
            } while (temp->next != first); // AT THE END TEMP PONITS TO LAST NODE 
            
            nn->next = first;  // FIRST VALUE OR ADDRESS IS STORE IN NEW NODES NEXT PONITER 
            first = nn; // NEW NODE ADDRESS STORE IN FIRST POINTER 
            temp->next = first; // FIRST PINTER VALUE IS STORE IN LAST NODE'S NEXT POINTER 

            printf("\nNEW NODE INSERTED AT FIRST POSITION IN SCLL\n");

            break;

            case 2: // INSERT NEW NODE AT LAST POSITION

            temp = first;

            do
            {
                temp = temp->next;
                
            } while (temp->next != first); // AT THE END TEMP PONITS TO LAST NODE
            
            nn->next = temp->next; // LAST NODE NEXT POINTER ADDRESS IS STORE IN NEW NODE'S NEXT POINTER 
            temp->next = nn;

            printf("\nNEW NODE INSERTED AT LAST POSITION IN SCLL\n");

            break;

            case 3: // INSERT NEW NODE AT SPECIFIC POSITION

            printf("\nENTER ELEMENT NODE YOU WANT TO INSERT AFTER NEW NODE :  ");
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
    
            } while (temp != first); // AT THE END TEMP POINTES TO LAST NODE

            if( flag == 1)
            {
                printf("\nNO SUCH NODE IS FOUND\n");
            }
            else
            {
                nn->next = temp->next; // LAST NODE'S ADDRESS STORE IN NEW NODE'S NEXT POINTER 
                temp->next = nn; // NEW NODE'S ADDRESS IS STORE IN LAST NODE'S NEXT POINTER 
            }

            printf("\nNEW NODE INSERTED AT SPECIFIC NODE\n");

            break;

            /* WITHOUT FLAG LOGIC 
            
            do
            {
               temp = temp->next;

            }while(temp != first);
            
              nn->next = temp->next;
              temp->next = nn;

            */

        } // END OF SWITCH CASE

    } // END OF ELSE STATEMENT

} // END OF insert_node FUNCTION 

void remove_node()
{
    struct node *nn,*temp,*temp1,*temp2;
    int sel,ch;

    if( first == NULL)
    {
        printf("\nLIST IS NOT CREATED\n");
    }
    else if( first->next == first)
    {
        temp = first;
        free(first);
        first = NULL;

        printf("\nLIST IS CREATED ONLY ONE NODE AT IT IS REMOVED\n");
    }
    else
    {
        // REMOVE NODE OPRATION ON SINGLY CIRCULAR LINKED LIST

        printf("\n\n1 => REMOVE FIRST NODE\n");
        printf("2 => REMOVE LAST NODE\n");
        printf("3 => REMOVE SPECIFIC NODE\n\n");
        printf("ENTER YOU WANT TO REMOVE POSITION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // REMOVE FIRST NODE


                temp1 = first;
                temp = first;

                do
                {
                    temp = temp->next;
                    
                } while (temp->next != first); // AT THE END TEMP POINTS TO LAST NODE
                
                first = first->next; // FIRST'S NODE'S NEXT POINTER VALUE IS STORE IN FIRST POINTER
                temp->next = first; // FIRST POINTER VALUE IS STORE IN LAST NODE'S NEXT POINTER
                free(temp1); // AFTER REMOVING FIRST NODE TO FREE FIRST NODE FOR PREVENT MEMOEY LEAKS 

                printf("\nFIRST NODE IS REMOVED\n");

                break;
                
            case 2: // REMOVE LAST NODE
            
              temp = first;

              do
              {
                temp = temp->next;  // INCREMENT 
                
              } while (temp->next != first); // AT THE END TEMP POINTS TO LAST NODE 
    

              temp2 = first;

              do
              {
                temp2 = temp2->next;
                
              } while (temp2->next != temp); // AT THE TEMP2 PONITS TO SECOND LAST NODE 
              
              temp2->next = first;  // FIRST POINTER VALUE IS STORE IN SECOND LAST NODE'S NEXT POINTER 
              free(temp);  // AFTER REMOVING LAST NODE FREE THE LAST NODE BECAUSE MEMORY LEAKS 

              printf("\nLAST NODE IS REMOVED\n");

              break;

            case 3: // REMOVE SPECIFIC NODE
            
                temp =first;
                int flag = 1;

                printf("\nENTER ELEMENT OF NODE YOU WANT TO REMOVE : ");
                scanf("%d",&sel);

                do
                {
                    if( temp->ele == sel) // TO CHECK SPECIFIC NODE IS FOUND OR IF FOUND FLAG 2 AND OTHER WISE FLAG DEFAULT IS 1 
                    {
                        flag = 2; // IF ELEMENT IS FOUND FLAG VALUE IS 2 
                        break;
                    }

                    temp = temp->next;
                    
                } while (temp != first); // AT THE END TEMP POINTS TO LAST NODE 
                
                if( flag == 1 )
                {
                    printf("\nNO SUCH NODE IS FOUND\n");
                }
                else if( flag == 2 && temp == first) // THIS CONDITION POINT FIRST NODE 
                {
                    // logic of remove first node

                    temp = first;
                    temp1 = first;

                    do
                    {
                        temp = temp->next;
                        
                    } while (temp->next != first);  // AT THE END TEMP PONITS TO LAST NODE
                    
                    first = first->next; // FIRST NODE'S NEXT POINTER VALUE IS STORE IN FIRST POINTER VALUE 
                    temp->next = first; // FIRST POINTERS VALUE IS STORE IN LAST NODE'S NEXT POINTER 
                    free(temp1);   // AFTER REMOVING FIRST NODE TO FREE FIRST NODE FOR PREVENT MEMOEY LEAKS 

                    printf("\nFIRST NODE IS REMOVED\n");
                }
                else 
                {
                    temp2 = first;

                    do
                    {
                        temp2 = temp2->next; 
                        
                    } while (temp2->next != temp); // AT THE END TEMP2 POINTS TO SELECTED NODE'S PRIVIOUS NODE 
                    
                    temp2->next = temp->next; // temp2->next = temp->next;
                    free(temp);  // AFTER REMOVING SPECIFIC NODE TO FREE SPECIFIC NODE FOR PREVENT MEMOEY LEAKS 

                    printf("\nSPECIFIC NOE IS REMOVED\n");

                }

                break;

        }// END OF SWITCH CASE

    } // END OF ELSE STATEMENT

}// END OF remove_node FUNCTION

void display_list() 
{
    struct node *temp;

    if( first == NULL)
    {
        printf("\nLIST IS NOT CREATED\n");
    }
    else
    {
        temp = first;
        
        // TRAVERSE SINGLY CIRCULAR LINKED LIST 

        do
        {
            printf("%d\t",temp->ele);

            temp = temp->next;

        } while (temp != first);

        printf("\n\n");
        
    } // END OF ELSE STATEMENT
    
} // END OF display_list FUNCTION


int main()
{
    struct node *nn,*temp;
    int ch;
    first = NULL;

    while(1)
    {
        printf("\n1 => INSERT NODE OPRATION\n");
        printf("2 => REMOVE NODE OPRATION\n");
        printf("3 => DISPLAY LIST OPRATION\n");
        printf("4 => EXIT OPRATION\n\n");
        printf("ENTER YOU WANT INSERT NODE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // INSERT NODE AT FIRST POSITION

                    insert_node();

                    break;

            case 2: // REMOVE NODE OPRATION
            
                    remove_node();

                    break;

            case 3: // DISPLAT LIST OPRATION
            
                    display_list();

                    break;

            case 4: // EXIT OPRATION
            
                    exit(0);


        } // END OF SWITCH CASE

    } // END OF WHILE LOOP 

    return 0;
}