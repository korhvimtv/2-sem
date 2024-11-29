#include "functions.h"

int main() {
    int choice;
    char surname[NAME_LEN];

    while (1) {
        printf("1. Input data\n");
        printf("2. Read data from file\n");
        printf("3. Do main task\n");
        printf("4. Search student by last name\n");
        printf("5. Output all student data\n");
        printf("6. Delete student by last name\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice) {
        case 1:
            input_data();
            break;
        case 2:
            read_data("student_data.txt");
            break;
        case 3:
            task();
            break;
        case 4:
            printf("Enter last name of the student to search: ");
            scanf("%s", surname);
            search_student_by_last_name(surname);
            break;
        case 5:
            output_all_students();
            break;
        case 6:
            printf("Enter last name of the student to delete: ");
            rewind(stdin);
            fgets(surname, 51, stdin);
            surname[strlen(surname) - 1] = '\0';
            delete_student_by_last_name(surname);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
