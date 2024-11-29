#include "functions.h"

Node* head = NULL;
Node* tail = NULL;
int student_count = 0;

void write_to_file(Node* s, const char* filename) // Функция записи в файл
{
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    fprintf(file, "%s|%s|%s", s->name, s->surname, s->clas);
    for (int i = 0; i < NUM_GRADES; i++) {
        fprintf(file, "|%d", s->grades[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}


void input_data() // Функция управляет вводом с клавиатуры
{
    if (student_count >= 100) {
        printf("Max student limit reached.\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    getchar();

    printf("Enter name: ");
    fgets(new_node->name, NAME_LEN, stdin);
    new_node->name[strcspn(new_node->name, "\n")] = '\0';

    printf("Enter surname: ");
    fgets(new_node->surname, NAME_LEN, stdin);
    new_node->surname[strcspn(new_node->surname, "\n")] = '\0';

    printf("Enter class: ");
    fgets(new_node->clas, CLASS_LEN, stdin);
    new_node->clas[strcspn(new_node->clas, "\n")] = '\0';

    printf("Enter %d grades: ", NUM_GRADES);
    for (int i = 0; i < NUM_GRADES; i++) {
        scanf("%d", &new_node->grades[i]);
    }

    if (head == NULL) {
        head = tail = new_node;
        new_node->next = head;
    }
    else {
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }
    student_count++;

    write_to_file(new_node, "student_data.txt");
}


void read_data(const char* filename) // Функция считывает данные
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Node* new_node = (Node*)malloc(sizeof(Node));

        char* token = strtok(line, "|");
        strcpy(new_node->name, token);

        token = strtok(NULL, "|");
        strcpy(new_node->surname, token);

        token = strtok(NULL, "|");
        strcpy(new_node->clas, token);

        for (int i = 0; i < NUM_GRADES; i++) {
            token = strtok(NULL, "|");
            new_node->grades[i] = atoi(token);
        }

        if (head == NULL) {
            head = tail = new_node;
            new_node->next = head;
        }
        else {
            tail->next = new_node;
            new_node->next = head;
            tail = new_node;
        }
        student_count++;
    }

    fclose(file);
}


void search_student_by_last_name(const char* surname)
{
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    FILE* outpt = fopen("output.txt", "w");

    fprintf(outpt, "%-20s | %-20s | %-15s | %-10s\n", "First Name", "Last Name", "Class", "Grades");

    Node* current = head;
    int found = 0;
    do {
        if (strcmp(current->surname, surname) == 0) {
            fprintf(outpt, "-------------------------------------------------------------------------------\n");
            fprintf(outpt, "%-20s | %-20s | %-15s |", current->name, current->surname, current->clas);
            for (int i = 0; i < NUM_GRADES; i++) {
                fprintf(outpt, "%d ", current->grades[i]);
            }
            fprintf(outpt, "\n");
            found = 1;
        }
        current = current->next;
    } while (current != head);
    fclose(outpt);

    if (!found) {
        system("cls");
        printf("Student with last name %s not found.\n", surname);
        return;
    }
    print();
}

void output_all_students()
{
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    FILE* outpt = fopen("output.txt", "w");

    fprintf(outpt, "%-20s | %-20s | %-15s | %-10s\n", "First Name", "Last Name", "Class", "Grades");

    Node* current = head;
    do {
        fprintf(outpt, "-------------------------------------------------------------------------------\n");
        fprintf(outpt, "%-20s | %-20s | %-15s |", current->name, current->surname, current->clas);
        for (int i = 0; i < NUM_GRADES; i++) {
            fprintf(outpt, " %d", current->grades[i]);
        }
        fprintf(outpt, "\n");
        current = current->next;
    } while (current != head);
    fclose(outpt);
    print();
}

void delete_student_by_last_name(const char* surname)
{
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    do {
        if (strcmp(current->surname, surname) == 0)
        {
            if (prev == NULL) {
                // Deleting head node
                if (head == head->next) {
                    free(head);
                    head = tail = NULL;
                }
                else {
                    tail->next = head->next;
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
            }
            else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;
                }
                free(current);
            }
            student_count--;
            printf("Deleted student with last name %s.\n", surname);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Student with last name %s not found.\n", surname);
}

void task()
{
    int choice;
    system("cls");
    printf("Choose task:\n");
    printf("1. Get number of students with good marks only\n");
    printf("2. Get list of best students\n");
    scanf("%d", &choice);

    system("cls");

    FILE* outpt = fopen("output.txt", "w");

    switch (choice)
    {
    case 1:
        fprintf(outpt, "Number of students without marks below 4: %d\n", count_students_without_low_marks(tail));
        break;
    case 2:
        printTopStudents(tail);
        break;
    default:
        break;
    }
    fclose(outpt);
    print();

}

// Функция для подсчета количества учеников без оценок ниже четырех
int count_students_without_low_marks(Node* tail)
{
    if (head == NULL)
        return 0;
    int count = 0;

    Node* current = head;
    do {
        int hasLowMark = 0;
        for (int i = 0; i < 5; i++) {
            if (current->grades[i] < 4) {
                hasLowMark = 1;
                break;
            }
        }
        if (!hasLowMark) {
            count++;
        }
        current = current->next;
    } while (current != head);

    return count;
}

// Функция для вывода лучших учеников
void printTopStudents(Node* tail) {
    if (head == NULL) return;

    Node* current = head;
    FILE* outpt = fopen("output.txt", "w");

    fprintf(outpt, "%-20s | %-20s | %-15s | %-10s\n", "First Name", "Last Name", "Class", "Average");

    do {
        int hasLowMark = 0;
        float totalMarks = 0;
        for (int i = 0; i < 5; i++) {
            if (current->grades[i] < 4) {
                hasLowMark = 1;
                break;
            }
            totalMarks += current->grades[i];
        }
        totalMarks /= 5;
        if (!hasLowMark) {
            fprintf(outpt, "-------------------------------------------------------------------------------\n");
            fprintf(outpt, "%-20s | %-20s | %-15s | %-10.1f\n", current->name, current->surname, current->clas, totalMarks);
        }
        current = current->next;
    } while (current != head);
    fclose(outpt);
}

void print() // Функция выводит данные на экран
{
    FILE* outpt = NULL;
    outpt = fopen("output.txt", "r");
    char line[80];
    system("cls");
    while (fgets(line, 80, outpt))
    {
        printf("%s", line);
    }
    fclose(outpt);
}