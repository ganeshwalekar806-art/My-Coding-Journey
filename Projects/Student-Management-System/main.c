#include<stdio.h>
#include<stdlib.h>

struct student 
{
    int id;
    char name[50];
    int age;
    float marks;

};

int id;

int main()
{
    struct student *p1 = NULL;
    int ch,i;
    int count = 0;

    while(1)
    {
        printf("\n======= STUDENT MANAGEMENT SYSTEM =======\n\n\n");
        printf("1 => ADD STUDENT\n");
        printf("2 => DISPLAY ALL STUDENT\n");
        printf("3 => SEARCH STUDENT\n");
        printf("4 => UPDATE STUDENT\n");
        printf("5 => DELETE STUDENT\n");
        printf("6 => EXIT\n\n");
        printf("enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // perfoem student add opration 
         {
            count++;

            p1 = (struct student *)realloc(p1, (count * sizeof(struct student)));

            printf("enter student id: ");
            scanf("%d",&p1[count - 1].id);

            printf("enter student name: ");
            scanf("%s",p1[count - 1].name);

            printf("enter student age : ");
            scanf("%d",&p1[count - 1].age);

            printf("enter student marks: ");
            scanf("%f",&p1[count - 1].marks);

            printf("\n\n\n = = = = STUDENT SUCCESSFULLY ADDED = = = = = \n\n\n");

            break;
         }

            case 2: //performing display student information opration
        {
              if(count == 0)
            {
                printf("STUDENT IS NOTHIN OUR DATABASE\n");
            }
            else
            {
                for(i=0;i<count;i++)
                 {
                    printf("student id: %d\n",p1[i].id);
                    printf("student name: %s\n",p1[i].name);
                    printf("student age: %d\n",p1[i].age);
                    printf("student marks: %f\n",p1[i].marks);

                 }
            }
            break;
        }
            case 3: // performing search student opration
        {    
            printf("enter your student id : ");
            scanf("%d",&id);

            int found = 0;

            for(i=0;i<count;i++)
            {
                if(p1[i].id == id)
                {
                    found = 1;
                    
                    printf("student name: %s\n",p1[i].name);
                    printf("student age: %d\n",p1[i].age);
                    printf("student marks: %f\n",p1[i].marks);
                } 
            }

            if(found == 0)
            {
                printf("\n\n= = = STUDENT IS NOT FOUND = = =\n\n");
            }
               break;
        }
            
            case 4: // performing update your account      
        {
            printf("\n\n1 => UPDATE ID\n");
            printf("2 => UPDATE NAME\n");
            printf("3 => UPDATE AGE \n");
            printf("4 => UPDATE MARKS\n\n");
            printf("enter your choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1: // update id
            {
                int found = 0;

                printf("enter student id: ");
                scanf("%d",&id);

                for(i = 0;i < count;i++)
                {
                    if(p1[i].id == id)
                    {          
                        found = 1;

                             printf("enter student updated id: ");
                             scanf("%d",&p1[i].id);

                              printf("\n\n= = = = STUDENT ID WAS SUCCESSFULLY UPDATED = = = =\n\n");

                              break;
                        

                    }
                }
                if(found == 0)
                {
                    printf("\n\n= = = STUDENT IS NOT FOUND = = = \n\n");
                }

               break;//end nested of case 1
            }
                case 2: // update student name
            {
                int found = 0;

                printf("enter student id: ");
                scanf("%d",&id);

                for(i=0;i<count;i++)
                {
                    if(p1[i].id == id)
                    { 
                        found = 1;

                      
                             printf("enter student updated name: ");
                             scanf("%s",p1[i].name);

                             printf("\n\n= = = = STUDENT NAME WAS SUCCESSFULLY UPDATED = = = =\n\n");

                             break;
                        
                    }
                }
                if(found == 0)
                {
                    printf("\n\n= = = STUDENT IS NOT FOUND = = = \n\n");
                }

                break; // end nested of case 2
            }

                case 3: // update student age 
            {
                int found = 0;

                printf("enter student id: ");
                scanf("%d",&id);

                for(i=0;i<count;i++)
                {
                    if(p1[i].id == id)
                    {
                        found = 1;
                       
                             printf("enter student age:  ");
                             scanf("%d",&p1[i].age);

                             printf("\n\n= = = = STUDENT AGE WAS SUCCESSFULLY UPDATED = = = =\n\n");

                             break;
                        
                    }
                }
                if(found == 0)
                {
                     printf("\n\n= = = STUDENT IS NOT FOUND = = = \n\n");
                }

                break;//end of nested case 3
            }

                case 4: // update student marks
            {
                int found = 0;

                printf("enter student id: ");
                scanf("%d",&id);

                for(i=0;i<count;i++)
                {
                    if(p1[i].id == id)
                    {
                        found = 1;
                
                        printf("enter student updated marks: ");
                        scanf("%f",&p1[i].marks);
            
                        printf("\n\n= = = = STUDENT MARKS WAS SUCCESSFULLY UPDATED = = = =\n\n");

                           break;
                        
                    }
                }
                if(found == 0)
                {
                     printf("\n\n= = = STUDENT IS NOT FOUND = = = \n\n");
                }
                break; // end of nested case 4
            }

            }// end of case 4 nested switch case end of case 4 innner switch case 

            break;
        }

            case 5: // performing 
        {
            int index = -1;

            printf("enter student id: ");
            scanf("%d",&id);

            for(i=0;i<count;i++)
            {
                if(p1[i].id == id)
                {
                    index = i;
                    break;
                }
            }

            if(index == -1)
            {
              printf("\n\n= = = NOTHING STUDENT ON DATABASE = = = \n\n");
            }
            else
            {
                for(i=index;i<count-1;i++)
                {
                    p1[i]=p1[i+1];
                }

                count--;

                if(count == 0)
                {
                    free(p1);
                    p1 = NULL;
                }
                else
                {
                    p1 =realloc(p1,count*sizeof(struct student));
                }

                printf("\n\n = = = STUDENT WAS SUCCESSFULLY DELETED = = = \n\n");


            }//end of else statement
        
            break; //end of case 5 satement
        }     

            case 6: //exit opration 
            {
                exit(0); // end of case 6
            }

        } // end of outer switch case
    
    }// end of while loop

    return 0;

}// end of main programm 
