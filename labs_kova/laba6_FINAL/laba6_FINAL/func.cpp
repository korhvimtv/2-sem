#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "source.h"
#include <string.h>
#include <ctype.h>

void spaceToSlash(char* arr)
{
    while (*arr != '\n')
    {
        if (*arr == ' ')
        {
            *arr = '_';
        }
        arr++;
    }
}

void slashToSpace(char* arr)
{
    while (*arr != '\0')
    {
        if (*arr == '_')
        {
            *arr = ' ';
        }
        arr++;
    }
}

void process_students_space(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        slashToSpace(students[i].name);
        slashToSpace(students[i].LastName);

        switch (students[i].residenceType) {
        case 0:
            slashToSpace(students[i].residence.cityAddress.street);
            slashToSpace(students[i].residence.cityAddress.house);
            slashToSpace(students[i].residence.cityAddress.flat);
            break;
        case 1:
            slashToSpace(students[i].residence.regionCityAddress.region);
            slashToSpace(students[i].residence.regionCityAddress.city);
            slashToSpace(students[i].residence.regionCityAddress.street);
            slashToSpace(students[i].residence.regionCityAddress.house);
            slashToSpace(students[i].residence.regionCityAddress.flat);
            break;
        case 2:
            slashToSpace(students[i].residence.regionDistrictCityAddress.region);
            slashToSpace(students[i].residence.regionDistrictCityAddress.district);
            slashToSpace(students[i].residence.regionDistrictCityAddress.city);
            slashToSpace(students[i].residence.regionDistrictCityAddress.street);
            slashToSpace(students[i].residence.regionDistrictCityAddress.house);
            slashToSpace(students[i].residence.regionDistrictCityAddress.flat);
            break;
        case 3:
            slashToSpace(students[i].residence.regionDistrictVillageAddress.region);
            slashToSpace(students[i].residence.regionDistrictVillageAddress.district);
            slashToSpace(students[i].residence.regionDistrictVillageAddress.village);
            slashToSpace(students[i].residence.regionDistrictVillageAddress.house);
            break;
        }
    }
}

void process_students_slash(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        spaceToSlash(students[i].name);
        spaceToSlash(students[i].LastName);

        switch (students[i].residenceType) {
        case 0:
            spaceToSlash(students[i].residence.cityAddress.street);
            spaceToSlash(students[i].residence.cityAddress.house);
            spaceToSlash(students[i].residence.cityAddress.flat);
            break;
        case 1:
            spaceToSlash(students[i].residence.regionCityAddress.region);
            spaceToSlash(students[i].residence.regionCityAddress.city);
            spaceToSlash(students[i].residence.regionCityAddress.street);
            spaceToSlash(students[i].residence.regionCityAddress.house);
            spaceToSlash(students[i].residence.regionCityAddress.flat);
            break;
        case 2:
            spaceToSlash(students[i].residence.regionDistrictCityAddress.region);
            spaceToSlash(students[i].residence.regionDistrictCityAddress.district);
            spaceToSlash(students[i].residence.regionDistrictCityAddress.city);
            spaceToSlash(students[i].residence.regionDistrictCityAddress.street);
            spaceToSlash(students[i].residence.regionDistrictCityAddress.house);
            spaceToSlash(students[i].residence.regionDistrictCityAddress.flat);
            break;
        case 3:
            spaceToSlash(students[i].residence.regionDistrictVillageAddress.region);
            spaceToSlash(students[i].residence.regionDistrictVillageAddress.district);
            spaceToSlash(students[i].residence.regionDistrictVillageAddress.village);
            spaceToSlash(students[i].residence.regionDistrictVillageAddress.house);
            break;
        }
    }
}

void create_or_open_file(FILE** file, const char* filename, const char* mode) {
    if (fopen_s(file, filename, mode) != 0) {
        printf("Не удалось открыть файл %s\n", filename);
        exit(1);
    }
}

void read_from_file(Student** students, int* num_students, FILE* mt) {
    int capacity = 10; // начальная ёмкость массива студентов
    *students = (Student*)malloc(capacity * sizeof(Student));
    *num_students = 0;

    while (1) {
        if (*num_students >= capacity) {
            capacity *= 2;
            *students = (Student*)realloc(*students, capacity * sizeof(Student));
        }

        Student* student = &(*students)[*num_students];
        int res = fscanf_s(mt, "%d", &student->residenceType);

        if (res == EOF) {
            break; // конец файла
        }

        switch (student->residenceType) {
        case 0:
            res = fscanf_s(mt, "%s %s %s %s %s",
                student->name, (unsigned)NAME,
                student->LastName, (unsigned)NAME,
                student->residence.cityAddress.street, (unsigned)PLACE,
                student->residence.cityAddress.house, (unsigned)PLACE,
                student->residence.cityAddress.flat, (unsigned)PLACE);
            break;
        case 1:
            res = fscanf_s(mt, "%s %s %s %s %s %s %s",
                student->name, (unsigned)NAME,
                student->LastName, (unsigned)NAME,
                student->residence.regionCityAddress.region, (unsigned)PLACE,
                student->residence.regionCityAddress.city, (unsigned)PLACE,
                student->residence.regionCityAddress.street, (unsigned)PLACE,
                student->residence.regionCityAddress.house, (unsigned)PLACE,
                student->residence.regionCityAddress.flat, (unsigned)PLACE);
            break;
        case 2:
            res = fscanf_s(mt, "%s %s %s %s %s %s %s %s",
                student->name, (unsigned)NAME,
                student->LastName, (unsigned)NAME,
                student->residence.regionDistrictCityAddress.region, (unsigned)PLACE,
                student->residence.regionDistrictCityAddress.district, (unsigned)PLACE,
                student->residence.regionDistrictCityAddress.city, (unsigned)PLACE,
                student->residence.regionDistrictCityAddress.street, (unsigned)PLACE,
                student->residence.regionDistrictCityAddress.house, (unsigned)PLACE,
                student->residence.regionDistrictCityAddress.flat, (unsigned)PLACE);
            break;
        case 3:
            res = fscanf_s(mt, "%s %s %s %s %s %s",
                student->name, (unsigned)NAME,
                student->LastName, (unsigned)NAME,
                student->residence.regionDistrictVillageAddress.region, (unsigned)PLACE,
                student->residence.regionDistrictVillageAddress.district, (unsigned)PLACE,
                student->residence.regionDistrictVillageAddress.village, (unsigned)PLACE,
                student->residence.regionDistrictVillageAddress.house, (unsigned)PLACE);
            break;
        default:
            fprintf(stderr, "Unknown residence type: %d\n", student->residenceType);
            break;
        }

        if (res == EOF) {
            break; // конец файла
        }
        else if (res < 0) {
            fprintf(stderr, "Error reading file\n");
            break; // ошибка чтения
        }

        (*num_students)++;
    }
}

void write_to_file(Student* students, int num_students, FILE** mt) // функция для записи в структуру текстового файла
{
    fclose(*mt);
    fopen_s(mt, "students.txt", "w+");
    process_students_slash(students, num_students);
    for (int i = 0; i < num_students; i++) {
        Student* student = &students[i];
        switch (student->residenceType) {
        case 0:
            fprintf(*mt, "%d %s %s %s %s %s\n", student->residenceType, student->name, student->LastName, student->residence.cityAddress, student->residence.cityAddress.house, student->residence.cityAddress.flat);
            break;
        case 1:
            fprintf(*mt, "%d %s %s %s %s %s %s %s\n", student->residenceType, student->name, student->LastName, student->residence.regionCityAddress.region, student->residence.regionCityAddress.city, student->residence.regionCityAddress.street, student->residence.regionCityAddress.house, student->residence.regionCityAddress.flat);
            break;
        case 2:
            fprintf(*mt, "%d %s %s %s %s %s %s %s %s\n", student->residenceType, student->name, student->LastName, student->residence.regionDistrictCityAddress.region, student->residence.regionDistrictCityAddress.district, student->residence.regionDistrictCityAddress.city, student->residence.regionDistrictCityAddress.street, student->residence.regionDistrictCityAddress.house, student->residence.regionDistrictCityAddress.flat);
            break;
        case 3:
            fprintf(*mt, "%d %s %s %s %s %s %s\n", student->residenceType, student->name, student->LastName, student->residence.regionDistrictVillageAddress.region, student->residence.regionDistrictVillageAddress.district, student->residence.regionDistrictVillageAddress.village, student->residence.regionDistrictVillageAddress.house);
            break;
        }
    }
    fclose(*mt);
}

void write_ring_to_file(FILE* file, Node* head) {
    if (head == NULL) {
        fprintf(file, "List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        fprintf(file, "%s %s %d\n", temp->data.name, temp->data.LastName, temp->data.residenceType);
        switch (temp->data.residenceType) {
        case 0:
            fprintf(file, "%s %s %s\n", temp->data.residence.cityAddress.street, temp->data.residence.cityAddress.house, temp->data.residence.cityAddress.flat);
            break;
        case 1:
            fprintf(file, "%s %s %s %s %s\n", temp->data.residence.regionCityAddress.region, temp->data.residence.regionCityAddress.city, temp->data.residence.regionCityAddress.street, temp->data.residence.regionCityAddress.house, temp->data.residence.regionCityAddress.flat);
            break;
        case 2:
            fprintf(file, "%s %s %s %s %s %s\n", temp->data.residence.regionDistrictCityAddress.region, temp->data.residence.regionDistrictCityAddress.district, temp->data.residence.regionDistrictCityAddress.city, temp->data.residence.regionDistrictCityAddress.street, temp->data.residence.regionDistrictCityAddress.house, temp->data.residence.regionDistrictCityAddress.flat);
            break;
        case 3:
            fprintf(file, "%s %s %s %s\n", temp->data.residence.regionDistrictVillageAddress.region, temp->data.residence.regionDistrictVillageAddress.district, temp->data.residence.regionDistrictVillageAddress.village, temp->data.residence.regionDistrictVillageAddress.house);
            break;
        }
        temp = temp->next;
    } while (temp != head);
}

// Функция для создания нового узла
Node* createNode(Student data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка: не удалось выделить память для нового узла.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(Node** head, Student data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Ошибка: не удалось выделить память для нового узла.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;  // Ссылка на сам себя
        newNode->prev = newNode;  // Ссылка на сам себя
    }
    else {
        Node* tail = (*head)->prev;  // Предыдущий элемент головы - хвост списка
        tail->next = newNode;        // Хвост указывает на новый элемент
        newNode->prev = tail;        // Новый элемент указывает на хвост
        newNode->next = *head;       // Новый элемент указывает на голову
        (*head)->prev = newNode;     // Голова указывает на новый элемент
    }
}

// Функция для удаления узла с определенными данными
void deleteNode(Node** head) {
    char key[NAME]; // Используем массив char для ключа (фамилии студента)

    printf("Введите фамилию студента: ");
    rewind(stdin); // Очищаем stdin перед вводом
    scanf_s("%s", key, sizeof(key)); // Считываем фамилию студента

    if (*head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    Node* curr = *head;
    Node* prev = NULL;

    // Цикл для поиска удаляемого узла
    do {
        if (strcmp(curr->data.LastName, key) == 0) {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    // Если узел не найден
    if (curr == *head && strcmp(curr->data.LastName, key) != 0) {
        printf("Узел с фамилией %s не найден.\n", key);
        return;
    }

    // Случай с одним узлом
    if (curr->next == curr && curr->prev == curr) {
        *head = NULL;
        free(curr);
        return;
    }

    // Если удаляемый узел - головной узел
    if (curr == *head) {
        prev = (*head)->prev;
        *head = (*head)->next;
        prev->next = *head;
        (*head)->prev = prev;
        free(curr);
    }
    else if (curr->next == *head) { // Если удаляемый узел - последний узел
        prev->next = *head;
        (*head)->prev = prev;
        free(curr);
    }
    else { // Если удаляемый узел - промежуточный
        Node* temp = curr->next;
        prev->next = temp;
        temp->prev = prev;
        free(curr);
    }

    display(2, *head);
}


void print_city_student(char* name, char* lastname, CityAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", name, lastname, "Минск", "-", "-", "-", "-", address.street, address.house, address.flat);
}

void print_region_city_student(char* name, char* lastname, RegionCityAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", name, lastname, "Областной центр", address.region, "-", "-", address.city, address.street, address.house, address.flat);
}

void print_region_district_city_student(char* name, char* lastname, RegionDistrictCityAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", name, lastname, "Районный город", address.region, address.district, "-", address.city, address.street, address.house, address.flat);
}

void print_region_district_village_student(char* name, char* lastname, RegionDistrictVillageAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", name, lastname, "Деревня", address.region, address.district, address.village, "-", "-", address.house, "-");
}

// Функция для печати содержимого двусвязного кольцевого списка
void display(int count, Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Имя", "Фамилия", "Тип", "Область", "Район", "Деревня", "Город", "Улица", "Дом", "Квартира");
    printf("+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");


    Node* temp = head;
    for (int i = 0; i < count; i++) {
        switch (temp->data.residenceType) {
        case 0:
            print_city_student(temp->data.name, temp->data.LastName, temp->data.residence.cityAddress);
            break;
        case 1:
            print_region_city_student(temp->data.name, temp->data.LastName, temp->data.residence.regionCityAddress);
            break;
        case 2:
            print_region_district_city_student(temp->data.name, temp->data.LastName, temp->data.residence.regionDistrictCityAddress);
            break;
        case 3:
            print_region_district_village_student(temp->data.name, temp->data.LastName, temp->data.residence.regionDistrictVillageAddress);
            break;
        }
        temp = temp->next;
        // If we have reached the head again, break out of the loop
        if (temp == head) {
            break;
        }
    }
    printf("+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
}

int is_word(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}


void enter_student_info(Node** head, Student* student) {
    char buffer[100];
    do {
        printf("\nВведите имя студента: ");
        scanf_s("%s", buffer);
        if (!is_word(buffer)) {
            printf("Ошибка: ввод должен содержать только буквы. Попробуйте еще раз.\n");
        }
    } while (!is_word(buffer));
    strncpy_s(student->name, buffer, sizeof(student->name));

    do {
        printf("\nВведите фамилию студента: ");
        scanf_s("%s", buffer);
        if (!is_word(buffer)) {
            printf("Ошибка: ввод должен содержать только буквы. Попробуйте еще раз.\n");
        }
    } while (!is_word(buffer));
    strncpy_s(student->LastName, buffer, sizeof(student->LastName));

    enter_residence(student);
    insertEnd(head, *student);
}


void enter_address(char fields[][30], char* addresses[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\nВведите %s: ", fields[i]);
        rewind(stdin);
        fgets(addresses[i], 30, stdin);
        spaceToSlash(addresses[i]);
        addresses[i][strcspn(addresses[i], "\n")] = 0; // Удаление символа новой строки
    }
}

void enter_residence(Student* student) {

    while (getchar() != '\n'); // Очистка буфера ввода
    do {
        printf("\nВведите тип проживания студента ( 0 - Минск, 1 - Областной центр, 2 - Районный город, 3 - Деревня): ");
        if (scanf_s("%d", &(student->residenceType)) != 1 || student->residenceType < 0 || student->residenceType > 3) {
            printf("\nОшибка: некорректный ввод. Пожалуйста, введите число.\n");
        }
        else {
            break; // Выход из цикла, если ввод корректен
        }
    } while (true); // Бесконечный цикл, который прерывается, когда ввод становится корректным
    getchar(); // Удаление символа новой строки
    char cityFields[3][30] = { "улицу", "номер дома", "номер квартиры" }; // создание массивом для храниния информации о проживании студента
    char* cityAddresses[] = { student->residence.cityAddress.street, student->residence.cityAddress.house, student->residence.cityAddress.flat };

    char regionCityFields[5][30] = { "область", "город", "улицу", "номер дома", "номер квартиры" };
    char* regionCityAddresses[] = { student->residence.regionCityAddress.region, student->residence.regionCityAddress.city, student->residence.regionCityAddress.street, student->residence.regionCityAddress.house, student->residence.regionCityAddress.flat };

    char regionDistrictCityFields[6][30] = { "область", "район", "город", "улицу", "номер дома", "номер квартиры" };
    char* regionDistrictCityAddresses[] = { student->residence.regionDistrictCityAddress.region, student->residence.regionDistrictCityAddress.district, student->residence.regionDistrictCityAddress.city, student->residence.regionDistrictCityAddress.street, student->residence.regionDistrictCityAddress.house, student->residence.regionDistrictCityAddress.flat };

    char regionDistrictVillageFields[4][30] = { "область", "район", "деревня", "номер дома" };
    char* regionDistrictVillageAddresses[] = { student->residence.regionDistrictVillageAddress.region, student->residence.regionDistrictVillageAddress.district, student->residence.regionDistrictVillageAddress.village, student->residence.regionDistrictVillageAddress.house };
    switch (student->residenceType) {
    case 0:
        enter_address(cityFields, cityAddresses, 3);
        break;
    case 1:
        enter_address(regionCityFields, regionCityAddresses, 5);
        break;
    case 2:
        enter_address(regionDistrictCityFields, regionDistrictCityAddresses, 6);
        break;
    case 3:
        enter_address(regionDistrictVillageFields, regionDistrictVillageAddresses, 4);
        break;
    }

}

void search_students_by_residence_type(Student* students, int num_students) {
    int response;
    int residence_type;
    do {
        rewind(stdin);
        printf("\nХотите ли вы произвести поиск по типу проживания студента? (1 - Да, 0 - Нет):  ");
        scanf_s("%d", &response);
        if (response != 0 && response != 1) {
            printf("Ошибка: введите 1 для Да или 0 для Нет. ");
            continue;
        }
    } while (response != 0 && response != 1);

    if (response == 1) {
        do {
            printf("По какому типу проживания вы хотите произвести поиск? (0 - Минск, 1 - Областной центр, 2 - Районный город, 3 - Деревня): ");
            scanf_s("%d", &residence_type);
            if (residence_type < 0 || residence_type > 3) {
                printf("Ошибка: введите число от 0 до 3.\n");
                continue;
            }
        } while (residence_type < 0 || residence_type > 3);

        printf("+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
        printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Имя", "Фамилия", "Тип", "Область", "Район", "Деревня", "Город", "Улица", "Дом", "Квартира");
        printf("+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
        for (int i = 0; i < num_students; i++) {
            Student* student = &students[i];
            if (student->residenceType == residence_type) {
                switch (student->residenceType) {
                case 0:
                    print_city_student(student->name, student->LastName, student->residence.cityAddress);
                    break;
                case 1:
                    print_region_city_student(student->name, student->LastName, student->residence.regionCityAddress);
                    break;
                case 2:
                    print_region_district_city_student(student->name, student->LastName, student->residence.regionDistrictCityAddress);
                    break;
                case 3:
                    print_region_district_village_student(student->name, student->LastName, student->residence.regionDistrictVillageAddress);
                    break;
                }
                printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
            }
        }
    }
}

