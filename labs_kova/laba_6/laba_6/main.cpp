#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "source.h"
#include <string.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int l, choice, ch;
    int num_students;
    FILE* mt = NULL;
    Student* student;
    Node* head = NULL;
    int count = 0;
    rewind(stdin);
    while (1)
    {
        system("cls");
        printf("�� ������ ������� ������ ����, ��� ������� �����?\n1 - ������ || Any key - �����\n > ");
        scanf_s("%d", &choice);
        if (choice == 1)
        {
            fopen_s(&mt, "students.txt", "r+");
            if (mt == NULL)
            {
                printf("�� ������� ������� ����.\n");
                return 1;
            }
            read_from_file(&student, &num_students, mt);
            print_students(student, num_students, mt);
            search_students_by_residence_type(student, num_students);
            fclose(mt);
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
                enter_student_info(&count, &head, &students[i]);
            }
            print_students(students, num_students, mt);
            write_to_file(students, num_students, &mt);
            printf("����� ��������� ���������� � ������:\n");
            display(num_students, head);
            printf("������ ������� �������� � ������?\n 1 - �� || Any key - ���");
            rewind(stdin);
            scanf_s("%d", &ch);
            rewind(stdin);
            if (ch == 1)
            {
                deleteNode(&head);
            }
            search_students_by_residence_type(students, num_students);
            free(students);
            fclose(mt);
        }
    }
}