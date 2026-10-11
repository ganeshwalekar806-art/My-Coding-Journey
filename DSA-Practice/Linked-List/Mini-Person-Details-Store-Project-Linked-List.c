#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct personal_info
{
    char name[50];
    int mob;
    char email[50];
};

struct vehicle_info
{
    char model[50];
    char color[50];
    char reg_no[50];
};

struct acc_info
{
    long ac_no;
    char ac_type[50];
    double ac_balance;
};

struct node 
{
    int adhar_no;
    struct personal_info *pinfo;
    struct vehicle_info *vinfo;
    struct acc_info *acinfo;
    struct node *next;
};

struct node *first;
int flag;
int adharno;


void add_details()
{
    struct node *nn,*temp;
    int ch;
    double balance;
 
    nn = (struct node *)malloc(sizeof(struct node));
    nn->pinfo = (struct personal_info *)malloc(sizeof(struct personal_info));
    nn->vinfo = (struct vehicle_info *)malloc(sizeof(struct vehicle_info));
    nn->acinfo = (struct acc_info *)malloc(sizeof(struct acc_info));

    printf("\n\n1 => ADD PERSONAL DETAILS OF PERSON\n");
    printf("2 => ADD VEHICLE DETALIS\n");
    printf("3 => ADD ACCOUNT DETAILS\n");
    printf("1 => ADD ALL DETAILS\n\n");
    printf("ENTER YOUR DETAILS: ");
    scanf("%d",&ch);

    printf("ENTER ADHAR NUMBER: ");
    scanf("%d",&nn->adhar_no);

    switch(ch)
    {
         case 1: // ADD PERSONAL DETAILS 

            printf("ENTER PERSON NAME : ");
            scanf("%49s",nn->pinfo->name);

            printf("ENTER MOBILE NUMBER: ");
            scanf("%d",&nn->pinfo->mob);

            printf("ENTER EMAIL : ");
            scanf("%49s",nn->pinfo->email);

            break;

        case 2: // ADD VEHICLE DETALIS 
        
            printf("ENTER VEHICLE MODEL : ");
            scanf("%49s",nn->vinfo->model);

            printf("ENTER VEHCLE COLOR : ");
            scanf("%49s",nn->vinfo->color);

            printf("ENTER VEHICLE REGISTRATION NUMBER : ");
            scanf("%49s",nn->vinfo->reg_no);

            break;

        case 3: // ADD ACCOUNT DETAILS OF PERSON 
        
            printf("ENTER ACCOUNT NUMBER : ");
            scanf("%ld",&nn->acinfo->ac_no);

            printf("ENTER ACCOUNT TYPE : ");
            scanf("%49s",nn->acinfo->ac_type);

            printf("ENTER ACCOUNT BALANCE : ");
            scanf("%lf",&balance);

            nn->acinfo->ac_balance = balance ; 

            break; 

        case 4: // ADD ALL DETAILS 
     
            printf("ENTER ADHAR NUMBER: ");
            scanf("%d",&nn->adhar_no);
            
            printf("ENTER PERSON NAME : ");
            scanf("%49s",nn->pinfo->name);

            printf("ENTER MOBILE NUMBER: ");
            scanf("%d",&nn->pinfo->mob);

            printf("ENTER EMAIL : ");
            scanf("%49s",nn->pinfo->email);

            printf("ENTER VEHICLE MODEL : ");
            scanf("%49s",nn->vinfo->model);

            printf("ENTER VEHCLE COLOR : ");
            scanf("%49s",nn->vinfo->color);

            printf("ENTER VEHICLE REGISTRATION NUMBER : ");
            scanf("%49s",nn->vinfo->reg_no);

            printf("ENTER ACCOUNT NUMBER : ");
            scanf("%ld",&nn->acinfo->ac_no);

            printf("ENTER ACCOUNT TYPE : ");
            scanf("%49s",nn->acinfo->ac_type);

            printf("ENTER ACCOUNT BALANCE : ");
            scanf("%lf",&balance);

            nn->acinfo->ac_balance = balance ; 

            break;

    } // END OF SWITCH CASE 

    nn->next = NULL;

    if(first == NULL)
    {
        first = nn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = nn;

    }

} // END OF add_details PERSON FUNCTION

void remove_details()
{ 
    struct node *temp,*temp1;
    struct personal_info *temp2;
    struct vehicle_info *temp3;
    struct acc_info *temp4;
    int ch,flag = 1;
    int adharno;

    if(first == NULL)
    {
        printf("\nDATA IS EMPTY\n");
    }
    else 
    {

         printf("\n\n1 => REMOVE PERSONAL INFORMATION\n");
         printf("2 => REMOVE VEHICLE INFORMATION\n");
         printf("3 => REMOVE ACCOUNT INFORMATION\n");
         printf("4 => REMOVE ALL INFORMATIN\n\n");
         printf("ENTER DO YOU WANT TO REMOVE : ");
         scanf("%d",&ch);
         printf("ENTER ADHAR NUMBER: ");
         scanf("%d",&adharno);

         switch(ch)
        {
           case 1: // REMOVE PERSONAL INFORMATION 

           temp = first;
           flag = 1;

           while(temp != NULL)
           {
                if(temp->adhar_no == adharno) // if(temp-->adhar_no == adharno)
                {
                    flag = 2;
                    break;
                }

                temp = temp->next;
           }

           if(flag == 1)
           {
              printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
           }
           else
           {   
                temp2 = temp->pinfo;
               free(temp2);
               temp->pinfo = NULL;


                printf("\nNAME OF THIS PERSON PERSONAL DETAILS IS REMOVED \n");

           }

           break;

           case 2: // REMOVE VEHICLE INFORMATION 

              temp = first;
              flag = 1; 

              while(temp != NULL)
              {
                 if(temp->adhar_no == adharno)
                 {
                    flag = 2;
                    break;
                 }
              }
              

              if(flag == 1)
              {
                 printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
              }
              else
              {
                 temp3 = temp->vinfo;
                 free(temp3);
                 temp->vinfo = NULL;

                 printf("VEHICLE INFORMATION WAS DELETED OF THIS PERSON \n");

              }

              break;

            case 3: // REMOVE ACCOUNT INFORMATION 
            
                temp = first;
                flag = 1;

                while(temp != NULL)
                {
                     if(temp->adhar_no == adharno)
                     {
                        flag = 2;
                        break;
                     }

                     temp = temp->next;
                }

                if(flag == 1)
                {
                    printf("\nADHAR IS INVALD PLEASE TRY AGAIN\n");
                }
                else
                {
                    temp4 = temp->acinfo ;
                    free(temp4);
                    temp->acinfo = NULL;

                    printf("ACCOUNT INFORMATION WAS REMOVED OF THIS PERSON \n");

                }

                break;

            case 4: // 
            
            temp = first;
            flag = 1;

            while(temp->next != NULL)
            {
                if(temp->adhar_no == adharno)
                {
                    flag = 2;
                    break;
                }

                temp = temp->next;
            }

            if(flag == 1)
            {
                printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
            }
            else if(flag == 2 && temp == first)
            {
                temp = first;
                first = NULL;
                free(temp);
            }
            else
            {
                temp1 = first;
                while(temp1->next != temp)
                {
                    temp1 = temp1->next;
                }

                temp1->next = temp->next;
                free(temp);
            }


        } // END OF SWITCH CASE 

    } // END OF ELSE STATEMENT 

} // END OF remove_details FUNCTION

void search_details()
{
    struct node *temp,*temp2;
    int ch;


    if(first == NULL)
    {
        printf("\nDATA IS EMPTY\n");
    }
    else
    {

    printf("\n\n1 => SEARCH PERSON ALL DETAILS\n");
    printf("2 => SEARCH PERSON PERSONAL DETAILS\n");
    printf("3 => SEARCH PERSON VEHICLE DETAILS\n");
    printf("4 => SEARCH PERSON ACCOUNT DETAILS\n");
    printf("ENTER SEARCH DETAILS : ");
    scanf("%d",&ch);
    printf("ENTER ADHAR NUMBER: ");
    scanf("%d",&adharno);

    
    switch(ch)
    {
        case 1: //  SEARCH PERSON ALL DETAILS 

            temp = first;
            flag = 1;

            while(temp != NULL)
            {
                if(temp->adhar_no == adharno)
                {
                    flag = 2;
                    break;
                }

                temp = temp->next;

            }

            if(flag == 1)
            {
                printf("\nAHAR IS INVALID PLEASE TRY AGAIN\n");
            }
            else
            {
                printf("\nADHAR NUMBER = %d\n",temp->adhar_no);
                printf("\n\n = = = PERSONAL INFORMATION = = = \n\n");
                printf("NAME : %s\n",temp->pinfo->name);
                printf("MOBILE : %d\n",temp->pinfo->mob);
                printf("EMAIL : %s\n",temp->pinfo->email);
                printf("\n\n = = = VEHICLE INFORMATION = = = \n\n");
                printf("MODEL NAME : %s\n",temp->vinfo->model);
                printf("CAR COLOR : %s\n",temp->vinfo->color);
                printf("REGISTRATION NUMBER : %s\n",temp->vinfo->reg_no);
                printf(" \n\n= = = ACCOUNT INFORMATION  = = = \n\n");
                printf("ACCOUNT NUMBER : %ld\n",temp->acinfo->ac_no);
                printf("ACCOUNT TYPE : %s\n",temp->acinfo->ac_type);
                printf("ACCOUNT BALANCE : %lf\n",temp->acinfo->ac_balance);

            }

            break;

        case 2: // SEARCH PERSONAL DETAILS   
              
              temp = first;
              flag = 1;

              while(temp != NULL)
              {
                  if(temp->adhar_no == adharno)
                  {
                      flag = 2;
                      break;
                  }

                  temp = temp->next;

              }

              if(flag == 1)
              {
                printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
              }
              else
              {
                 printf("\n\n = = = PERSONAL INFORMATION = = = \n\n");
                 printf("NAME : %s\n",temp->pinfo->name);
                 printf("MOBILE : %d\n",temp->pinfo->mob);
                printf("EMAIL : %s\n",temp->pinfo->email);
              }

              break;

        case 3: // SEARCH  VEHICLE DETAILS 
        
               temp = first ;
               flag = 1;

               while(temp != NULL)
               {
                   if(temp->adhar_no == adharno)
                   {
                      flag = 2;
                      break;
                   }

                   temp = temp->next ;

               }

               if(flag == 1)
               {
                printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
               }
               else
               {
                
                printf("\n\n = = = VEHICLE INFORMATION = = = \n\n");
                printf("MODEL NAME : %s\n",temp->vinfo->model);
                printf("CAR COLOR : %s\n",temp->vinfo->color);
                printf("REGISTRATION NUMBER : %s\n",temp->vinfo->reg_no);

               }

               break;

        case 4: // SEARCH ACCOUNT DETAILS 
        
               temp = first;
               flag = 1;

               while(temp != NULL)
               {
                  if(temp->adhar_no == adharno)
                  {
                     flag = 2;
                     break;
                  }

                  temp = temp->next;

               }

               if(flag == 1)
               {
                  printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
               }
               else
               {

                printf(" \n\n= = = ACCOUNT INFORMATION  = = = \n\n");
                printf("ACCOUNT NUMBER : %ld\n",temp->acinfo->ac_no);
                printf("ACCOUNT TYPE : %s\n",temp->acinfo->ac_type);
                printf("ACCOUNT BALANCE : %lf\n",temp->acinfo->ac_balance);

               }

               break;

    }  // END OF SWITCH CASE 

   }
     
} // END OF search_details FUNCTION 

void modify_details()
{
    struct node *temp;
    int ch;
    

    if(first == NULL)
    {
        printf("\nDATA IS EMPTY\n");
    }
    else
    {
    printf("\n\n1 =>MODIFY ADHAR NUMBER\n");
    printf("2 => MODIFY PERSONAL DETAILS \n");
    printf("3 => MODIFY VEHICLE DETAILS \n");
    printf("4 => MODIFY ACCOUNT DETAILS\n");
    printf("5 => MODIFY PERSON ALL DETAILS\n\n");
    printf("WHICH DO YOU WANT MODIFY : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: // MODIFY ADHAR NUMBER 
            printf("ENTER ADHAR NUMBER : ");
            scanf("%d",&adharno);

            temp = first;
            flag = 1;

            while(temp != NULL)
            {
                if (temp->adhar_no == adharno)
                {
                    flag = 2;
                    break;
                }

                temp = temp->next;
            }

            if( flag == 1 )
            {
                printf("\nADHAR IS INVALID PLEASE TRY AGAIN\n");
            }
            else
            {
                printf("ENTER YOUR MODIFYED ADHAR NUMBER : ");
                scanf("%d",&temp->adhar_no);
            }

             
        case 2: // MODIFY PERSONAL DETAILS 

            printf("\n1 => MODIFY PERSON NAME \n");
            printf("2 => MODIFY PERSON MOBILE NUMBER \n");
            printf("3 => MODIFY PERSON EMAIL\n\n");
            printf("ENTER WHAT DO YOU MODIFY: ");
            scanf("%d",&ch);
            printf("\nENTER ADHAR NUMBER : ");
            scanf("%d",&adharno);

            switch(ch)
            {
                case 1: // MODIFY PERSON NAME 

                  temp = first;
                  flag = 1;

                     while(temp != NULL)
                        {
                            if(temp->adhar_no == adharno)
                            {
                               flag = 2;
                                break;
                            } 

                              temp = temp->next;

                       }       
                       
                       if(flag == 1)
                       {
                          printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                       }
                       else
                       {
                           printf("ENTER MODIFIED NAME OF PERSON : ");
                           scanf("%49s",temp->pinfo->name);
                       }

                       break;

                case 2: // MODIFY MOBILE NUMBER 

                    temp = first;
                    flag = 1;

                     while(temp != NULL)
                        {
                            if(temp->adhar_no == adharno)
                            {
                               flag = 2;
                                break;
                            } 

                              temp = temp->next;

                       }
                       
                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }   
                    else
                    {
                        printf("ENTER MODIIF MOBILE NUMBER : ");
                        scanf("%d",&temp->pinfo->mob);

                    }

                    break;

                case 3: // MODIFY EMAIL 
                
                    temp = first ;
                    flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFIED EMAIL : ");
                        scanf("%49s",temp->pinfo->email);
                    }

                    break;
    
            } // END OF CASE 1 MODIFY PERSONA DETIALS SWITCH CASE 

            break;

        case 3: // MODIFY VEHICLE DETAILS     

            printf("\n1 => MODIFY MODEL NAME\n");
            printf("2 => MODIFY CAR COLOR\n");
            printf("3 => MODIFY REGISTRATION NUMBER \n");
            printf("WHAT YOU WANT MODIFY: ");
            scanf("%d",&ch);
            printf("\nENTER ADHAR NUMBER : ");
            scanf("%d",&adharno);

            switch(ch)
            {
                case 1: // MODIFY MODEL NAME 

                     temp = first ;
                     flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFYED VEHICLE MODEL : ");
                        scanf("%49s",temp->vinfo->model);
                    }

                    break;

                case 2: // MODIFY CAR COLOR 
                
                      temp = first ;
                      flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFIED CAR COLOR : ");
                        scanf("%49s",temp->vinfo->color);
                    }

                    break;

                case 3: // MODIFY REGISTRATION NUMBER 
                
                      temp = first ;
                      flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFIED CAR COLOR : ");
                        scanf("%49s",temp->vinfo->color);
                    }

                    break;

            } // END OF CASE 2 MODIFY VEHICLE DETAILS 

            break;

        case 4: // MODIFY ACCOUNT DETAILS 

              printf("1 => MODIFY ACCOUNT NUMBER\n");
              printf("2 => MODIFY ACCOUNT TYPE\n");
              printf("3 => MODIFY ACCOUNT BALANCE\n\n");
              printf("ENTER WHAT YOU MODIFY: ");
              scanf("%d",&ch);
              printf("\nENTER ADHAR NUMBER :  \n");
              scanf("%d",&adharno);

              switch(ch)
              {
                case 1: // MODFY ACCOUNT NUMBER 

                     temp = first ;
                     flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFIED ACCOUNT NUMBER : ");
                        scanf("%ld",&temp->acinfo->ac_no);
                    }

                    break;

                case 2: // MODIFY ACCOUNT TYPE 
                
                     temp = first ;
                     flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFIED ACCOUNT TYPE : ");
                        scanf("%49s",temp->acinfo->ac_type);
                    }

                    break;
                 
                case 3: // MODIFY ACCOUNT BALANCE 
                
                     temp = first ;
                     flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        double balance;
                        printf("ENTER MODIFIED ACCOUNT BALANCE : ");
                        scanf("%lf",&balance);

                        temp->acinfo->ac_balance = balance ; 
                    }

                    break;
              } // END OF CASE 3 MODIFY ACCOUNT DETAILS 

              break;

        case 5: // MODIFY ALL DETAILS 
        
                    printf("ENTER ADHAR NUMBER : ");
                    scanf("%d",&adharno);
                    temp = first ;
                    int flag = 1;
                    
                    while(temp != NULL)
                    {
                         if(temp->adhar_no == adharno)
                         {
                             flag = 2 ;
                             break;
                         }

                         temp = temp->next;

                    }

                    if(flag == 1)
                    {
                        printf("\nADHAR IS INVALID PLEASE TRY AGAIN \n");
                    }
                    else
                    {
                        printf("ENTER MODIFIED ADHAR NUMBER : ");
                        scanf("%d",&temp->adhar_no);

                        printf("ENTER MODIFIED NAME OF PERSON : ");
                        scanf("%49s",temp->pinfo->name);

                        printf("ENTER MODIIF MOBILE NUMBER : ");
                        scanf("%d",&temp->pinfo->mob);

                        printf("ENTER MODIFIED EMAIL : ");
                        scanf("%49s",temp->pinfo->email);

                        printf("ENTER MODIFYED VEHICLE MODEL : ");
                        scanf("%49s",temp->vinfo->model);

                        printf("ENTER MODIFIED CAR COLOR : ");
                        scanf("%49s",temp->vinfo->color);

                        printf("ENTER MODIFIED CAR COLOR : ");
                        scanf("%49s",temp->vinfo->color);

                        printf("ENTER MODIFIED ACCOUNT NUMBER : ");
                        scanf("%ld",&temp->acinfo->ac_no);

                        printf("ENTER MODIFIED ACCOUNT TYPE : ");
                        scanf("%49s",temp->acinfo->ac_type);

                        double balance;
                        printf("ENTER MODIFIED ACCOUNT BALANCE : ");
                        scanf("%lf",&balance);

                        temp->acinfo->ac_balance = balance ; 

                    }

                    break;
    } // END OF SWITCH CASE 

    

    } // END OF ELSE STATEMENT

} // END OF modify FUNCTION STATEMENT 

void display_personal()
{
    struct node *temp;

    temp= first;

    while(temp != NULL)
    {
        printf("\n\n = = = PERSONAL INFORMATION = = = \n\n");
        printf("NAME : %s\n",temp->pinfo->name);
        printf("MOBILE : %d\n",temp->pinfo->mob);
        printf("EMAIL : %s",temp->pinfo->email);

        temp = temp->next;
    }

}

void display_vehicle()
{
    struct node *temp;

    temp= first;

    while(temp != NULL)
    {
        printf("\n\n = = = VEHICLE INFORMATION = = = \n\n");
        printf("MODEL NAME : %s\n",temp->vinfo->model);
        printf("CAR COLOR : %s\n",temp->vinfo->color);
        printf("REGISTRATION NUMBER : %s\n",temp->vinfo->reg_no);

        temp = temp->next;
    }
    
}

void display_account()
{
    struct node *temp;

    temp= first;

    while(temp != NULL)
    {
         printf(" \n\n= = = ACCOUNT INFORMATION  = = = \n\n");
         printf("ACCOUNT NUMBER : %ld\n",temp->acinfo->ac_no);
         printf("ACCOUNT TYPE : %s\n",temp->acinfo->ac_type);
         printf("ACCOUNT BALANCE : %lf\n",temp->acinfo->ac_balance);

        temp = temp->next;
    }
    
}

void display_all()
{
    struct node *temp;

    temp= first;

    while(temp != NULL)
    {
            printf("\nADHAR NUMBER = %d\n",temp->adhar_no);
            printf("\n = = = PERSONAL INFORMATION = = = \n\n");
            printf("NAME : %s\n",temp->pinfo->name);
            printf("MOBILE : %d\n",temp->pinfo->mob);
            printf("EMAIL : %s\n",temp->pinfo->email);
            printf("\n\n = = = VEHICLE INFORMATION = = = \n\n");
            printf("MODEL NAME : %s\n",temp->vinfo->model);
            printf("CAR COLOR : %s\n",temp->vinfo->color);
            printf("REGISTRATION NUMBER : %s\n",temp->vinfo->reg_no);
            printf(" \n\n= = = ACCOUNT INFORMATION  = = = \n\n");
            printf("ACCOUNT NUMBER : %ld\n",temp->acinfo->ac_no);
            printf("ACCOUNT TYPE : %s\n",temp->acinfo->ac_type);
            printf("ACCOUNT BALANCE : %lf\n",temp->acinfo->ac_balance);

        temp = temp->next;
    }
    
}

void display_details()
{
    struct node *temp;
    int ch;

    printf("\n\n1 => DISPLAY PERSONAL INFORMATION \n");
    printf("2 => DISPLAY VECHILE INFORMATION\n");
    printf("3 => DISPLAY ACCOUNT INFORMATION\n");
    printf("4 => DISPLAY ALL INFORMATION\n");
    printf("ENTER YOU WANT TO DISPLAY : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: // DISPLAY PERSONAL DETAILS 
              
              if( first == NULL)
              {
                printf("\nDATA IS EMPTY\n");
              }
              else
              {
                display_personal();
              }       

              break;

        case 2: // DISPLAY VECHILE DETAILS 
          
              if( first == NULL )
              {
                printf("\nDATA IS EMPTY\n");
              }
              else
              {
                display_vehicle();
              }
              

              break;

        case 3: // DISPLAY ACCOUNT DETAILS 
        
              if( first == NULL )
              {
                printf("\nDATA IS EMPTY\n");
              }
              else
              {
                display_account();
              }
              

              break;

        case 4: // DISPLAY ALL DETAILS 
        
            if( first == NULL )
            {
                printf("\nDATA IS EMPTY\n");
            }
            else
            {
                display_all();
            }
             

             break;

    } // END OF SWITCH CASE 

} // END OF DISPLAY DETAILS FUNCTION 


int main()
{
    int ch;
    first = NULL;

    while(1)
    {
        printf("\n\n1 => ADD DETAILS\n");
        printf("2 => REMOVE DETAILS\n");
        printf("3 => SEARCH DETAILS\n");
        printf("4 => MODIFY DETAILS \n");
        printf("5 => DISPLAY DETAILS\n");
        printf("6 => EXIT\n\n");
        printf("ENTER YOUR OPRATION: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // ADD DETAILS OF PERSON 

                 add_details();
                 
                 break;

            case 2: // REMOVE DETAILS OF PERSON 
            
                 remove_details();

                 break;

            case 3: // SEARCH DETAILS OF PERSON 
            
                 search_details();

                 break;

            case 4: // MODIFY DETAILS 
            
                 modify_details();

                 break;

            case 5:  // DISPLAY DETAILS 
            
            if ( first == NULL)
            {
                printf("\nDATA IS EMPTY\n");
            }
            else
            {
                display_details();
            }
                
                break;

            case 6:   // EXIT OPRATION  

                exit(0);


        } // END OF SWITCH CASE 
        
    }// END OF WHILE LOOP

    return 0;
}