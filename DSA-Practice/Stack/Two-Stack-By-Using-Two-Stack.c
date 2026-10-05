#include<stdio.h>
#define max 10

int main()
{
    int pstack[max];
    int sstack[max];
    int ptop = -1;
    int stop = -1;
    int ele,ch;

    while(1)
    {
        printf(" 1 => PUSH OPRATION\n");
        printf(" 2 => pop opration\n");
        printf(" 3 => display opration\n");
        printf(" 4 => exit opration\n");
        printf(" enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: //push opration perform only in primary srack 
                if(ptop == max-1)
                {
                    printf(" primary stack is overflow\n");
                }
                else
                {
                    printf(" enter the element to push in primary stack: ");
                    scanf("%d",&ele);

                    pstack[ptop+1] = ele;
                    ptop++;
                }

                break;

                case 2: // pop oparation perform primary stack and push the poped element in secondary stack
                     
                    printf(" 1 => pop from primary stack\n");
                    printf(" 2 => pop from secondary stack\n");
                    printf(" enter your choice : ");
                    scanf("%d",&ch);

                    switch(ch)
                    {
                        case 1: // pop from primary stack and push in secondary stack

                            if(ptop == -1)
                            {
                                printf(" stack underflow\n");
                            }

                            else
                            {
                                sstack[stop+1] = pstack[ptop];
                                ptop--;
                                stop++;
                                printf(" element poped from pimary stack and pushed in secondary stack \n");

                            }

                            break;

                        case 2: // pop from secodary stack 
                        
                        printf(" 1 => restore the element in primary stack \n");
                        printf(" 2 => discard the element \n");
                        printf(" enter your choice : ");
                        scanf("%d",&ch);

                        switch(ch)
                        {
                            case 1: // restore the element in primary stack

                               if(stop == -1)
                               {
                                printf(" seconsary stack is underflow\n");
                               }

                               else
                               {
                                pstack[ptop+1] = sstack[stop];
                                stop--;
                                ptop++;
                                printf(" element restored in primary stack \n");

                               }

                               case 2: // discard the element from secondary stack

                               if(stop == -1)
                               {
                                printf(" secondary stack is underflow\n");
                               }

                               else
                               {
                                printf(" element %d discard in secondary stack \n",sstack[stop]);
                                stop--;

                               }

                               break;


                        }
                        
                    } 

                 case 3: // display the element in parimary stack and secondar stack

                 printf("\n\n\n= = = = = = = =  display of primary stack = = = = = = = \n\n");
                 for( int i=ptop; i>=0;i--)
                 {
                    printf("%d\n",pstack[i]);
                 }

                 printf("  \n\n\n = = = = = display of secondary stack = = = = = = =  \n\n");
                 for( int j=stop;j>=0;j--)
                 {
                    printf("%d\n",sstack[j]);
                 }

                 break;

        }
    }

    return 0;


}