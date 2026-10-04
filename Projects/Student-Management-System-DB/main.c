#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h> 

struct student 
{
    int id;
    char name[50];
    int age;
    float marks;
};

int main()
{
    int ch, sub_ch;
    int id, age;
    char name[50];
    float marks;
    char query[300];

    // MySQL Connection Variables 
    MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *res;
    MYSQL_ROW row;

    if (conn == NULL) {
        printf("MySQL Initialization failed!\n");
        return 1;
    }

    // Database Connection OF STUDENT DATABASE NAME 
    if (mysql_real_connect(conn, "localhost", "root", "kali", "student_info", 0, NULL, 0) == NULL)
    {
        printf("CONNECTION FAILED: %s\n", mysql_error(conn));
        return 1;
    }
    else
    {
        printf("\n=========================================");
        printf("\n  CONNECTION SUCCESSFULLY CONNECTED!  ");
        printf("\n=========================================\n");
    }

    while(1)
    {
        printf("\n======= STUDENT MANAGEMENT SYSTEM =======\n");
        printf("1 => ADD STUDENT\n");
        printf("2 => DISPLAY ALL STUDENTS\n");
        printf("3 => SEARCH STUDENT\n");
        printf("4 => UPDATE STUDENT\n");
        printf("5 => DELETE STUDENT\n");
        printf("6 => EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: // ADD STUDENT INFORMATION 
            {
                printf("\nEnter student id: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student age: ");
                scanf("%d", &age);
                printf("Enter student marks: ");
                scanf("%f", &marks);

                // TO MAKE SQL QUERY 
                snprintf(query, sizeof(query), 
                         "INSERT INTO student VALUES(%d, '%s', %d, %f)", 
                         id, name, age, marks);

                if (mysql_query(conn, query)) {
                    printf("\nError adding student: %s\n", mysql_error(conn));
                } else {
                    printf("\n= = = STUDENT SUCCESSFULLY ADDED TO DATABASE = = =\n");
                }
                break;
            }

            case 2: // DISPLAY ALL STUDENTS INFORMATION 
            {
                if (mysql_query(conn, "SELECT * FROM student")) {
                    printf("Fetch Error: %s\n", mysql_error(conn));
                    break;
                }

                res = mysql_store_result(conn);
                
                if (mysql_num_rows(res) == 0) {
                    printf("\nNO STUDENTS FOUND IN DATABASE\n");
                } else {
                    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "NAME", "AGE", "MARKS");
                    printf("--------------------------------------------------\n");
                    while ((row = mysql_fetch_row(res))) {
                        printf("%-10s %-20s %-10s %-10s\n", row[0], row[1], row[2], row[3]);
                    }
                }
                mysql_free_result(res);
                break;
            }

            case 3: // SEARCH STUDENT INFORMATION 
            {    
                printf("Enter student id to search: ");
                scanf("%d", &id);

                snprintf(query, sizeof(query), "SELECT * FROM student WHERE id = %d", id);
                
                if (mysql_query(conn, query)) {
                    printf("Search Error: %s\n", mysql_error(conn));
                    break;
                }

                res = mysql_store_result(conn);

                if ((row = mysql_fetch_row(res))) {
                    printf("\n= = = STUDENT FOUND = = =\n");
                    printf("ID    : %s\n", row[0]);
                    printf("Name  : %s\n", row[1]);
                    printf("Age   : %s\n", row[2]);
                    printf("Marks : %s\n", row[3]);
                } else {
                    printf("\n= = = STUDENT NOT FOUND = = =\n");
                }
                mysql_free_result(res);
                break;
            }
            
            case 4: // UPDATE STUDENT  INFORAMTION 
            {
                printf("\n1 => UPDATE NAME\n");
                printf("2 => UPDATE AGE\n");
                printf("3 => UPDATE MARKS\n");
                printf("Enter choice: ");
                scanf("%d", &sub_ch);

                printf("Enter student ID to update: ");
                scanf("%d", &id);

                if (sub_ch == 1) {
                    printf("Enter new name: ");
                    scanf("%s", name);
                    snprintf(query, sizeof(query), "UPDATE student SET name='%s' WHERE id=%d", name, id);
                } else if (sub_ch == 2) {
                    printf("Enter new age: ");
                    scanf("%d", &age);
                    snprintf(query, sizeof(query), "UPDATE student SET age=%d WHERE id=%d", age, id);
                } else if (sub_ch == 3) {
                    printf("Enter new marks: ");
                    scanf("%f", &marks);
                    snprintf(query, sizeof(query), "UPDATE student SET marks=%f WHERE id=%d", marks, id);
                } else {
                    printf("Invalid Choice!\n");
                    break;
                }

                if (mysql_query(conn, query)) {
                    printf("Update Failed: %s\n", mysql_error(conn));
                } else {
                    printf("\n= = = STUDENT UPDATED SUCCESSFULLY = = =\n");
                }
                break;
            }

            case 5: // DELETE STUDENT
            {
                printf("Enter student id to delete: ");
                scanf("%d", &id);

                snprintf(query, sizeof(query), "DELETE FROM student WHERE id = %d", id);

                if (mysql_query(conn, query)) {
                    printf("Delete Failed: %s\n", mysql_error(conn));
                } else {
                    printf("\n= = = STUDENT WAS SUCCESSFULLY DELETED = = =\n");
                }
                break;
            }     

            case 6: // EXIT
            {
                mysql_close(conn); // Connection सुरक्षित बंद करा
                exit(0);
            }

            default:
                printf("Invalid Choice! Try again.\n");
        } 
    }

    return 0;

}
