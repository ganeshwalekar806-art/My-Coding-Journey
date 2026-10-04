#include<stdio.h>
#include<stdlib.h>
#define max 5



int main()
{
    int stack1[max];
    int stack2[max];
    int stack3[max];
    int ele,ch,i;
    int top1 = -1;
    int top2 = -1;
    int top3 = -1; 

    while(1)
    {
        printf("\n1 => PUSH OPRATION\n");
        printf("2 => POP OPRATION \n");
        printf("3 => DISPLAY OPRATION\n");
        printf("4 => EXIT\n\n");
        printf("enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // perform PUSH OPRATION  on stack 1 stack 2 and stack 3 
             while(1)
             {
                printf("\n1 => PUSH ON 1 STACK\n");
                printf("2 => PUSH ON 2 STACK\n");
                printf("3 => PUSH ON 3 STACK\n");
                printf("enter your choice: ");
                scanf("%d",&ch);

                switch(ch)
                {
                   case 1: // push on stack 1
                   printf("enter element for push opration: ");
                   scanf("%d",&ele);

                   stack1[top1+1]=ele;
                   top1++;

                   printf("\nSUCCESSFULLY PERFORM PUSH OPRATION ON STACK 1\n");

                   break;

                   case 2: // push on stack 2

                   printf("enter element for push opration: ");
                   scanf("%d",&ele);

                   stack2[top2+1]=ele;
                   top2++;

                   printf("\nSUCCESSFULLY PERFROM PUSH OPRATION STACK 2\n");

                   break;

                   case 3: // push on stack 3 

                   printf("enter element for push opration: ");
                   scanf("%d",&ele);

                   stack3[top3+1]=ele;
                   top3++;

                   printf("\nSUCCESSFULLY PERFORM PUSH OPRATION STACK 3\n");

                   break;

                } // end of main case 1 push opration switch case

                break;

             }// of main case 1 ush opration  while loop

             break;

             case 2: // pop opration on 1,2 and 3 stack 
             
             while(1)
             {
                printf("\n1 => POP FROM STACK 1\n");
                printf("2 => POP FROM STACK 2\n");
                printf("3 => POP FROM STACK 3\n");
                printf("enter your choice: ");
                scanf("%d",&ch);

                switch(ch)
                {
                    case 1: // pop from stack 1 and push on stack2 and stack3 

                    while(1)
                    {
                        printf("\n1 => push on 2 stack\n");
                        printf("2 => push on 3 stack\n");
                        printf("enter your choice: ");
                        scanf("%d",&ch);

                        switch(ch)
                        {
                            case 1: // push on stack 2 and pop from stack 1

                            if( top2 == -1)
                            {
                                stack2[top2+1] = stack1[top1];
                                top2++;
                                top1--;
                                printf("\nSUCESSFULLY PERFORM POP FROM STACK 1 AND PUSH ON STACK 2\n");
                                
                            }
                            else
                            {

                             if(stack1[top1] == stack2[top2])
                             {
                                stack2[top2+1] = stack1[top1];
                                top1--;
                                top2++;
                                printf("\nSUCESSFULLY PERFORM POP FROM STACK 1 AND PUSH ON STACK 2\n");

                             }
                             else
                             {
                                printf("\nVALUE OF STACK 1 AND STACK 2 ARE NOT SAME DO NOT PERFORM PUSH OPRATION\n");
                             }

                            }

                            break;

                            case 2: // push on 3 stack and pop from stack 1

                            if( top3 == -1)
                            {
                                stack3[top3+1] = stack1[top1];
                                top1--;
                                top3++;
                                printf("\nSUCESSFULLY PERFORM POP FROM STACK 1 AND PUSH ON STACK 3\n");

                            }
                            else
                            {
                            
                             if(stack1[top1] == stack3[top3])
                             {
                                stack3[top3+1] = stack1[top1];
                                top1--;
                                top3++;
                                printf("\nSUCESSFULLY PERFORM POP FROM STACK 1 AND PUSH ON STACK 3\n");

                             }
                             else
                             {
                                printf("\nVALUE OF STACK 1 AND STACK 3 ARE NOT SAME DO NOT PERFORM PUSH OPRATION\n");
                             }

                            } 

                           

                            break;

                        }// end of inner case 1 pop opration on first stack switch case

                        break;

                    }//end of inner case 1 pop opration on firts stack  while loop

                    break;

                    case 2: // pop from stack 2 and push on 1 and 3 stack

                    while(1)
                    {
                        printf("\n1 => Push on 1 stack\n");
                        printf("2 => push on 3 stack\n");
                        printf("enter your choice: ");
                        scanf("%d",&ch);

                        switch(ch)
                        {
                            case 1: // push on 1 stack and pop from 2 stack

                            if(top1 == -1)
                            {
                                stack1[top1+1] = stack2[top2];
                                top2--;
                                top1++;
                                printf("\nSUCESSFULLY PERFORM POP FROM STACK 2 AND PUSH ON STACK 1 \n");

                            }

                            else
                            {
                                if(stack2[top2] == stack1[top1])
                                {
                                    stack1[top1+1] = stack2[top2];
                                    top2--;
                                    top1++;
                                    printf("\nSUCESSFULLY PERFORM POP FROM STACK 2 AND PUSH ON STACK 1 \n");

                                }
                                else
                                {
                                    printf("\nVALUE OF STACK 2 AND STACK 1 ARE NOT SAME DO NOT PERFORM PUSH OPRATION\n");
                                }
                            }

                            

                            break;

                            case 2:// push on 3stack and pop from stack of 2
                            
                            if(top3 == -1)
                            {
                                stack3[top3+1] = stack2[top2];
                                top2--;
                                top3++;
                                printf("\nSUCESSFULLY PERFORM POP FROM STACK 2 AND PUSH ON STACK 3 \n");

                            }

                            else
                            {
                                if(stack2[top2] == stack3[top3])
                                {
                                    stack3[top3+1] = stack2[top2];
                                    top2--;
                                    top3++;
                                    printf("\nSUCESSFULLY PERFORM POP FROM STACK 2 AND PUSH ON STACK 3 \n");

                                }
                                else
                                {
                                    printf("\nVALUE OF STACK 2 AND STACK 3 ARE NOT SAME DO NOT PERFORM PUSH OPRATION\n");
                                }
                            }

                            break;

                        }// end of  inner case 2 pop from stack 2 opration switch case 
                        
                        break;

                    }// end of inner case 2 pop from stack 2 opration while loop

                    break;

                    case 3: // pop from 3 and push on 1 and 2 stack 

                    while(1)
                    {
                        printf("\n1 => push on 1 stack\n");
                        printf("2 => push on 2 stack\n");
                        printf("enter your choice: ");
                        scanf("%d",&ch);

                        switch(ch)
                        {
                            case 1: // push on 1 stack and pop from 3 stack

                            if(top1 == -1)
                            {
                                stack1[top1+1] = stack3[top3];
                                top3--;
                                top1++;
                                printf("\nSUCESSFULLY PERFORM POP FROM 3 AND PUSH ON STACK 1\n");
                                
                            }

                            else
                            {
                                if(stack3[top3] == stack1[top1])
                                {
                                    stack1[top1+1] = stack3[top3];
                                    top3--;
                                    top1++;
                                    printf("\nSUCESSFULLY PERFORM POP FROM 3 AND PUSH ON STACK 1\n");

                                }
                                else
                                {
                                    printf("\nVALUE OF STACK 3 AND STACK 1 ARE NOT SAME DO NOT PERFORM PUSH OPRATION\n");
                                }
                            }

                           

                            break;

                            case 2: // push on 2 stack and pop from 3 stack

                            if(top2 == -1)
                            {
                                stack2[top2+1] = stack3[top3];
                                top3--;
                                top2++;
                                printf("\nSUCESSFULLY PERFORM POP FROM 3 AND PUSH ON STACK 2\n");
                                
                            }

                            else
                            {
                                if(stack3[top3] == stack2[top2])
                                {
                                    stack2[top2+1] = stack3[top3];
                                    top2++;
                                    top3--;
                                    printf("\nSUCESSFULLY PERFORM POP FROM 3 AND PUSH ON STACK 2\n");

                                }
                                else
                                {
                                    printf("\nVALUE OF STACK 3 AND STACK 2 ARE NOT SAME DO NOT PERFORM PUSH OPRATION\n");
                                }
                            }

                           

                            break;

                        }// end of inner case 3 pop from stack three switch case  

                        break;

                    }//end of inner case 3 pop from stack three while loop 

                    break;

                }// end of main case 2 pop opration switch case

                break;

             }// end of main case 2 pop opration while loop

             break;

             case 3: // display opration 

             while(1)
             {
                printf("\n\n1 => display 1 stack\n");
                printf("2 => dispaly 2 stack\n");
                printf("3 => display 3 stack\n");
                printf("enter your choice: ");
                scanf("%d",&ch);

                switch(ch)
                {
                    case 1: // display 1 stack

                    if( top1 == -1)
                    {
                        printf("stack 1 is empty do not perform display opration\n");
                    }
                    else
                    {
                        for( i= top1;i>=0;i--)
                        {
                            printf("%d\n",stack1[i]);
                        }

                        printf("\nSUCESSFULLY PROFORM DISPLAY STACK 1 OPRATION\n ");
                    }

                    

                    break;

                    case 2: // display 2 stack 

                    if(top2 == -1)
                    {
                        printf("stack 2 is empty do not perform display opration\n");
                    }
                    else
                    {
                        for(i=top2;i>=0;i--)
                        {
                            printf("%d\n",stack2[i]);
                        }

                        printf("\nSUCCESSFULLY PERFORM DISPLAY OPRATION STACK 2 OPRATION\n");
                    }

                    

                    break;

                    case 3: // display 3 stack

                    if( top3 == -1)
                    {
                        printf("stack 3 is empty do not perform display opration\n");
                    }
                    else
                    {
                        for(i=top3;i>=0;i--)
                        {
                            printf("%d\n",stack3[i]);
                        }

                        printf("SUCCESSFULLY PERFORM DISPLAY STACK 3 OPRATION\\n");
                    }

                    

                    break;

                } // end of main case 3 display opration switch case

                break;

             }//end of main case 3 display opration while loop

             break;

             case 4: // exit opration

             exit(1);

             break;

        }// end of main switch case 

    }// end of main while loop

    return 0;

}
