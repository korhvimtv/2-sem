#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "func.h"
#include <string.h>

int main()
{
    int menuChoice, fileCh;
    int num_students = 0, new_students_count = 0;
    
    Student* students = NULL;
    FILE* file = NULL;

    rewind(stdin);
    setlocale(LC_ALL, "rus");

    printf("�� ������ ������� ��� ������� ����? (1 - �������, Any Key - �������)\n > ");
    scanf_s("%d", &fileCh);
    if (fileCh == 1)
    {
        fopen_s(&file, "students.txt", "w+");
        if (file == NULL) {
            printf("�� ������� ������� ����.\n");
            return 1;
        }
    }
    else
    {
        fopen_s(&file, "students.txt", "r+");
        if (file == NULL) {
            printf("�� ������� ������� ����.\n");
            return 1;
        }

        read_from_file(&students, &num_students, file);
        process_students_space(students, num_students);
    }

    while (1)
    {
        system("cls");
        printf("LAB 6\n-----------------\n");
        printf("����:\n1. ������ ����� ���������� � ���������\n2. ������� ������� ���������\n3. �������� ��������\n4. ����� �������� �� ����� ����������\n5. �����\n > ");
        scanf_s("%d", &menuChoice);
        switch (menuChoice)
        {
        case 1:
            fclose(file);
            fopen_s(&file, "students.txt", "w+");
            free(students);
            printf("\n������� ���������� ���������: ");
            scanf_s("%d", &num_students);
            getchar(); // �������� ������� ����� ������
            students = (Student*)malloc(num_students * sizeof(Student));
            for (int i = 0; i < num_students; i++)
            {
                enter_student_info(&students[i]);
            }

            write_to_file(students, num_students, &file);
            process_students_space(students, num_students);
            break;
        case 2:        
            system("cls");
            rewind(stdin);
            print_students(students, num_students, file);
            rewind(stdin);
            while (getchar() != '\n');
            break;       
        case 3:
            rewind(stdin);
            printf("\n������� ���������� ����� ��������� ��� ����������: ");
            scanf("%d", &new_students_count);
            getchar(); // �������� ������� ����� ������

            students = (Student*)realloc(students, (num_students + new_students_count) * sizeof(Student));
            for (int i = 0; i < new_students_count; i++) {
                enter_student_info(&students[num_students + i]);
            }
            num_students += new_students_count;

            write_to_file(students, num_students, &file);  
            break;
        case 4:
            rewind(stdin);
            search_students_by_residence_type(students, num_students);
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 5:
            free(students);
            fclose(file);
            return 0;
        default:
            printf("\n�������� �����, ����������, ���������� �����.\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        }
    }
}


/*
int main() {
    setlocale(LC_ALL, "Rus");
    int l, choice;
    int num_students, new_students_count;
    FILE* mt = NULL;
    Student* student;
    Student* students = NULL;
    while (1)
    {
        system("cls");
        printf("�� ������ ������� ������ ����, ��� ������� �����?\n1 - ������ || Any key - �����\n > ");
        scanf_s("%d", &choice);
        rewind(stdin);
        if (choice == 1)
        {
            fopen_s(&mt, "students.txt", "r+");
            if (mt == NULL) {
                printf("�� ������� ������� ����.\n");
                return 1;
            }

            Student* students = NULL;
            int num_students = 0;

            read_from_file(&students, &num_students, mt);
            print_students(students, num_students, mt);

            printf("\n������� ���������� ����� ��������� ��� ����������: ");
            int new_students_count;
            scanf("%d", &new_students_count);
            getchar(); // �������� ������� ����� ������

            students = (Student*)realloc(students, (num_students + new_students_count) * sizeof(Student));
            for (int i = 0; i < new_students_count; i++) {
                enter_student_info(&students[num_students + i]);
            }
            num_students += new_students_count;

            write_to_file(students, num_students, &mt);
            fclose(mt);

            search_students_by_residence_type(students, num_students);
        }
        else
        {
            fopen_s(&mt, "students.txt", "w+");
            if (mt == NULL)
            {
                printf("�� ������� ������� ����.\n");
                return 1;
            }
            printf("\n������� ���������� ���������: ");
            scanf_s("%d", &num_students);
            getchar(); // �������� ������� ����� ������
            Student* students = (Student*)malloc(num_students * sizeof(Student));
            for (int i = 0; i < num_students; i++)
            {
                enter_student_info(&students[i]);
            }
            print_students(students, num_students, mt);
            write_to_file(students, num_students, &mt);
            search_students_by_residence_type(students, num_students);
            free(students);
            fclose(mt);
        }
    }
}
*/