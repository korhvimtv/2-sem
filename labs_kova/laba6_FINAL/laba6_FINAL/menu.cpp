#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "source.h"
#include <string.h>

int main()
{
    int menuChoice, fileCh;
    int num_students, num_plus;

    Student* students = NULL;
    Node* head = NULL;

    int count = 0;
    
    rewind(stdin);
    setlocale(LC_ALL, "rus");
   
    FILE* file = NULL;

    printf("�� ������ ������� ��� ������� ����? (1 - �������, Any Key - �������)\n > ");
    scanf_s("%d", &fileCh);
    if (fileCh == 1)
    {
        create_or_open_file(&file, "students.txt", "w+");
        create_or_open_file(&file, "ring.txt", "w+");
    }
    else
    {
        create_or_open_file(&file, "students.txt", "r+");
        create_or_open_file(&file, "ring.txt", "w+");
        read_from_file(&students, &num_students, file);
        process_students_space(students, num_students);
    }

    while (1)
    {
        system("cls");
        printf("LAB 6\n-----------------\n");
        printf("����:\n1. ������ ����� ���������� � ���������\n2. ������� ������� ���������\n3. �������� ��������\n4. ������� ��������\n5. �������� ��������� � ����\n6. �������� ������ � ����\n7. ����� �� ����� ����������\n8. �����\n > ");
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
                enter_student_info(&head, &students[i]);
            }

            write_to_file(students, num_students, &file);
            process_students_space(students, num_students);
            break;
        case 2:
        {
            system("cls");
            rewind(stdin);
            display(num_students, head);
            rewind(stdin);
            while (getchar() != '\n');
            break;
        }
        case 3:
        {
            rewind(stdin);
            printf("\n������� ���������� ���������, ������� �� ������ ��������: ");
            scanf_s("%d", &num_plus);
            getchar(); // �������� ������� ����� ������

            // ����������������� ������ ��� ������� ���������
            students = (Student*)realloc(students, (num_students + num_plus) * sizeof(Student));
            if (students == NULL) {
                printf("������ ��������� ������.\n");
                exit(1);
            }

            // ���� ���������� ��� ����� ���������
            for (int i = num_students; i < num_students + num_plus; i++) {
                enter_student_info(&head, &students[i]);
            }

            num_students += num_plus; // ���������� ������ ���������� ���������
            break;
        }
        case 4:
        {
            system("cls");
            rewind(stdin);
            deleteNode(&head);
            break;
        }
        case 5:
            write_to_file(students, num_students, &file);
            fclose(file);
            break;
        case 6:
            write_ring_to_file(file, head);
            fclose(file);
            break;
        case 7:
            rewind(stdin);
            search_students_by_residence_type(students, num_students);
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 8:
            free(students);
            fclose(file);
            return 0;
        default:
            printf("\n�������� �����, ����������, ���������� �����.\n");
            while (getchar() != '\n');
            break;
        }
    }
}