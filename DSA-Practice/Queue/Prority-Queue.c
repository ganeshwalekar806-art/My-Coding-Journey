#include <stdio.h>
#include <stdlib.h> // system("cls") साठी

struct Task
{
    char tname[25];
    int reqt;
    int reqr;
    int reqm;
};

void print_tasks(struct Task t[])
{
    int i;
    printf("\n\n");
    printf("%-25s\t %s\t %s\t %s\n", "Task Name", "Time", "Res", "Mem");
    printf("------------------------------------------------------------\n"); 
    for(i = 0; i <= 6; i++)
    {
        printf("%-25s\t %d\t %d\t %d\n", t[i].tname, t[i].reqt, t[i].reqr, t[i].reqm);
    }
}

void asc_order_of_time(struct Task t[])
{
    int i, j;
    struct Task temp;

    for(i = 0; i <= 5; i++)
    {
        for(j = i + 1; j <= 6; j++)
        {
            if(t[i].reqt > t[j].reqt)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void desc_order_of_time(struct Task t[])
{
    int i, j;
    struct Task temp;

    for(i = 0; i <= 5; i++)
    {
        for(j = i + 1; j <= 6; j++)
        {
            if(t[i].reqt < t[j].reqt)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void asc_order_of_resources(struct Task t[])
{
    int i, j;
    struct Task temp;

    for(i = 0; i <= 5; i++)
    {
        for(j = i + 1; j <= 6; j++)
        {
            if(t[i].reqr > t[j].reqr)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void desc_order_of_resources(struct Task t[])
{
    int i, j;
    struct Task temp;

    for(i = 0; i <= 5; i++)
    {
        for(j = i + 1; j <= 6; j++)
        {
            if(t[i].reqr < t[j].reqr)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void asc_order_of_memory(struct Task t[])
{
    int i, j;
    struct Task temp;

    for(i = 0; i <= 5; i++)
    {
        for(j = i + 1; j <= 6; j++)
        {
            if(t[i].reqm > t[j].reqm)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void desc_order_of_memory(struct Task t[])
{
    int i, j;
    struct Task temp;

    for(i = 0; i <= 5; i++)
    {
        for(j = i + 1; j <= 6; j++)
        {
            if(t[i].reqm < t[j].reqm)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

int main()
{
    struct Task t[7] = {
        {"Copy Paste", 12, 3, 115},
        {"Open Browser", 4, 2, 200},
        {"Open My Computer", 7, 2, 75},
        {"Open Network Systems", 10, 8, 210},
        {"Refresh", 1, 1, 50},
        {"Download Song", 7, 6, 160},
        {"Open Media Player", 8, 6, 180}
    };

    int ch;
    char ch2;

    system("cls"); // Screen Clear करण्यासाठी

    printf("\n\nTotal Tasks Enqueued ");
    print_tasks(t);
    printf("\nPress Enter to continue...");
    getchar();

    while(1)
    {
      system("cls");
      printf("\n\nSelect Priority Constraint \n");
      printf("1 - Required Time \n");
      printf("2 - Required Resources \n");
      printf("3 - Required Memory \n");
      printf("4 - Exit \n");
      printf("Provide your choice : ");
      scanf("%d", &ch);

      if (ch == 4) break;

      switch(ch)
      {
        case 1:
            printf("\tSelect Priority \n");
            printf("\tA - Ascending order of Required TIME \n");
            printf("\tD - Descending order of Required TIME \n");
            printf("\tProvide your choice : ");
            scanf(" %c", &ch2); // Space दिली आहे जेणेकरून Enter Key Ignore होईल
            switch(ch2)
            {
                case 'A':
                case 'a':
                    asc_order_of_time(t);
                    print_tasks(t);
                    break;
                case 'D':
                case 'd':
                    desc_order_of_time(t);
                    print_tasks(t);
                    break;
            }
            break;

        case 2:
            printf("\tSelect Priority \n");
            printf("\tA - Ascending order of Required RESOURCES \n");
            printf("\tD - Descending order of Required RESOURCES \n");
            printf("\tProvide your choice : ");
            scanf(" %c", &ch2);
            switch(ch2)
            {
                case 'A':
                case 'a':
                    asc_order_of_resources(t);
                    print_tasks(t);
                    break;
                case 'D':
                case 'd':
                    desc_order_of_resources(t);
                    print_tasks(t);
                    break;
            }
            break;

        case 3:
            printf("\tSelect Priority \n");
            printf("\tA - Ascending order of Required MEMORY \n");
            printf("\tD - Descending order of Required MEMORY \n");
            printf("\tProvide your choice : ");
            scanf(" %c", &ch2);
            switch(ch2)
            {
                case 'A':
                case 'a':
                    asc_order_of_memory(t);
                    print_tasks(t);
                    break;
                case 'D':
                case 'd':
                    desc_order_of_memory(t);
                    print_tasks(t);
                    break;
            }
            break;

        default:
            printf("Invalid Choice!");
            break;
      }
      
      printf("\nPress Enter to continue...");
      getchar(); // Enter clear करण्यासाठी
      getchar(); // Output पाहण्यासाठी थांबायला
    }

    printf("\n\nBye Bye ... \n");
    return 0;
}