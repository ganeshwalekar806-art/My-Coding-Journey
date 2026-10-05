#include<stdio.h>
#define max 10

int main()
{
    int stack[max]; 
    int ptop = 4; 
    int stop = 5;
    int ele,ch;

    while(1)
    {
        printf(" \n\n1 => perform push opartion\n");
        printf(" 2 => perform pop opartion \n");
        printf(" 3 => perform display opration\n");
        printf(" 4 exit\n");
        printf(" enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: // perform push opration on primary stack 

            if(ptop ==  max-1)
            {
                printf(" primary stack overflow /n");
            }

            else
            {
                printf(" enter the element to be puhed in primary stack:  ");
                scanf("%d",&ele);

                stack[ptop+1] = ele;
                ptop++;
                printf(" element %d is pushed in primary stack \n",ele);
            }

            break;

            case 2: // perform pop opration on both primary and secondary stack 

            printf(" 1 => perform pop opration on primary stack /n");
            printf(" 2 => perform pop opration on secondary stack /n");
            printf(" enter your choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1: //perform pop opration on primary stack an push the popped element in secondary stack 

                if(ptop == 4)
                {
                    printf(" stack underflow/n");
                }

                else if(stop == -1)
                {
                    printf(" secondary stack overflow /n");
                }
                else
                {
                    stack[stop-1] = stack[ptop];
                    stop--;
                    ptop--;
                    printf(" element is popped from primary stack and pushed in secondary stack /n");
                    
                }

                break;

                case 2: // perform pop opration on secondary stack and push the popped element in primary stack 

                printf(" 1 => restore/n");
                printf(" 2 => discard /n");
                printf(" enter your choice: ");
                scanf("%d",&ch);

                switch(ch)
                {
                    case 1: // perform pop opration on secondary stack and restore in primary stack 

                    if( stop == 5)
                    {
                        printf(" seconadry stack underflow/n");

                    }

                    else if( ptop == max -1 )
                    {
                        printf(" primary stack overflow");

                    }

                    else
                    {
                        stack[ptop+1]=stack[stop];
                        stop++;
                        ptop++;

                        printf(" element is popped on secondary stack and push the popped element in primary stack \n");

                    }
                    break;

                    case 2: // perofrom discard opration secondary opration 

                    if( stop == 5)
                    {
                        printf(" stack is empty\n");
                    }

                    else
                    {
                        printf(" %d element popped on secondary stack ",stack[stop]);
                        stop++;

                    }

                    break;

                } // end nested main 2nds pop secondary stack nested restore and discard opration 

                break;

            case 3: // perform display opration on both primary and secondary stack 

            printf(" 1 => display primary stack/n ");
            printf(" 2 => display seconadry stack/n ");
            printf(" enter your choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1: // perfrom display opration on primary stack 

                if(ptop == 4)
                {
                    printf(" stack is allready empty nothing to perform display opration/n");
                }
                else
                {
                    for(int i=ptop;i>4;i--)
                    {
                        printf("%d/n",stack[i]);
                    }
                }
                break;

                case 2: // perform display opration on secondary stack 

                if(stop =5)
                {
                    printf(" stack is allready empty nothig to perform display opratioin /n");

                }
                else
                {
                    for( int i=stop;i<5;i++)
                    {
                        printf("%d/n",stack[i]);
                    }
                }

                break;

            } // end of 3rd display nested  switch case 

            break;

        } 

    } // end of main switch case 
    
} // end of while loop 


return 0;

}
