#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "func.h"
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

int is_word(const char* str) {
    while (*str) {
        if (!isalpha((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void enter_student_info(Student* student) {
    char buffer[100];
    do {
        printf("\n������� ��� ��������: ");
        scanf_s("%s", buffer, sizeof(buffer));
        if (!is_word(buffer)) {
            printf("������: ���� ������ ��������� ������ �����. ���������� ��� ���.\n");
        }
    } while (!is_word(buffer));
    spaceToSlash(student->name);
    strncpy_s(student->name, buffer, sizeof(student->name));

    do {
        printf("\n������� ������� ��������: ");
        scanf_s("%s", buffer, sizeof(buffer));
        if (!is_word(buffer)) {
            printf("������: ���� ������ ��������� ������ �����. ���������� ��� ���.\n");
        }
    } while (!is_word(buffer));
    strncpy_s(student->LastName, buffer, sizeof(student->LastName));
    enter_residence(student);
}


void enter_address(char fields[][30], char* addresses[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\n������� %s: ", fields[i]);
        rewind(stdin);
        fgets(addresses[i], 30, stdin);
        spaceToSlash(addresses[i]);
        addresses[i][strcspn(addresses[i], "\n")] = 0; // �������� ������� ����� ������
    }
}

void enter_residence(Student* student) {

    while (getchar() != '\n'); // ������� ������ �����
    do {
        printf("\n������� ��� ���������� �������� ( 0 - �����, 1 - ��������� �����, 2 - �������� �����, 3 - �������): ");
        if (scanf_s("%d", &(student->residenceType)) != 1 || student->residenceType < 0 || student->residenceType > 3) {
            printf("\n������: ������������ ����. ����������, ������� �����.\n");
        }
        else {
            break; // ����� �� �����, ���� ���� ���������
        }
    } while (true); // ����������� ����, ������� �����������, ����� ���� ���������� ����������
    getchar(); // �������� ������� ����� ������
    char cityFields[3][30] = {"�����", "����� ����", "����� ��������" }; // �������� �������� ��� �������� ���������� � ���������� ��������
    char* cityAddresses[] = {student->residence.cityAddress.street, student->residence.cityAddress.house, student->residence.cityAddress.flat };

    char regionCityFields[5][30] = { "�������", "�����", "�����", "����� ����", "����� ��������" };
    char* regionCityAddresses[] = { student->residence.regionCityAddress.region, student->residence.regionCityAddress.city, student->residence.regionCityAddress.street, student->residence.regionCityAddress.house, student->residence.regionCityAddress.flat };

    char regionDistrictCityFields[6][30] = { "�������", "�����", "�����", "�����", "����� ����", "����� ��������" };
    char* regionDistrictCityAddresses[] = { student->residence.regionDistrictCityAddress.region, student->residence.regionDistrictCityAddress.district, student->residence.regionDistrictCityAddress.city, student->residence.regionDistrictCityAddress.street, student->residence.regionDistrictCityAddress.house, student->residence.regionDistrictCityAddress.flat };

    char regionDistrictVillageFields[4][30] = { "�������", "�����", "�������", "����� ����" };
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
void print_city_student(int rez, int student_num, char* name, char* lastname, CityAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", rez, student_num, name, lastname, "�����", "-", "-", "-", "-", address.street, address.house, address.flat);
}

void print_region_city_student(int rez, int student_num, char* name, char* lastname, RegionCityAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", rez, student_num, name, lastname, "��������� �����", address.region, "-", "-", address.city, address.street, address.house, address.flat);
}

void print_region_district_city_student(int rez, int student_num, char* name, char* lastname, RegionDistrictCityAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", rez, student_num, name, lastname, "�������� �����", address.region, address.district, "-", address.city, address.street, address.house, address.flat);
}

void print_region_district_village_student(int rez, int student_num, char* name, char* lastname, RegionDistrictVillageAddress address) {
    printf("| %d  | %-10d | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", rez, student_num, name, lastname, "�������", address.region, address.district, address.village, "-", "-", address.house, "-");
}

void print_students(Student* students, int num_students, FILE* mt) {
    printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    printf("| %s  | %-10s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "�", "�������", "���", "�������", "���", "�������", "�����", "�������", "�����", "�����", "���", "��������");
    printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    for (int i = 0; i < num_students; i++) {
        Student* student = &students[i];
        switch (student->residenceType) {
        case 0:
            print_city_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.cityAddress);
            break;
        case 1:
            print_region_city_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.regionCityAddress);
            break;
        case 2:
            print_region_district_city_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.regionDistrictCityAddress);
            break;
        case 3:
            print_region_district_village_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.regionDistrictVillageAddress);
            break;
        }
        printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    }
}

void write_to_file(Student* students, int num_students, FILE** mt) // ������� ��� ������ � ��������� ���������� �����
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

void search_students_by_residence_type(Student* students, int num_students) {
    int response;
    int residence_type;
    do {
        printf("\n������ �� �� ���������� ����� �� ���� ���������� ��������? (1 - ��, 0 - ���):  ");
        scanf_s("%d", &response);
        if (response != 0 && response != 1) {
            printf("������: ������� 1 ��� �� ��� 0 ��� ���. ");
            continue;
        }
    } while (response != 0 && response != 1);

    if (response == 1) {
        do {
            printf("�� ������ ���� ���������� �� ������ ���������� �����? (0 - �����, 1 - ��������� �����, 2 - �������� �����, 3 - �������): ");
            scanf_s("%d", &residence_type);
            if (residence_type < 0 || residence_type > 3) {
                printf("������: ������� ����� �� 0 �� 3.\n");
                continue;
            }
        } while (residence_type < 0 || residence_type > 3);

        printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
        printf("| %s  | %-10s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "�", "�������", "���", "�������", "���", "�������", "�����", "�������", "�����", "�����", "���", "��������");
        printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
        for (int i = 0; i < num_students; i++) {
            Student* student = &students[i];
            if (student->residenceType == residence_type) {
                switch (student->residenceType) {
                case 0:
                    print_city_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.cityAddress);
                    break;
                case 1:
                    print_region_city_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.regionCityAddress);
                    break;
                case 2:
                    print_region_district_city_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.regionDistrictCityAddress);
                    break;
                case 3:
                    print_region_district_village_student(student->residenceType, i + 1, student->name, student->LastName, student->residence.regionDistrictVillageAddress);
                    break;
                }
                printf("+----+------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
            }
        }
    }
}

void read_from_file(Student** students, int* num_students, FILE* mt) {
    int capacity = 10; // ��������� ������� ������� ���������
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
            break; // ����� �����
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
            break; // ����� �����
        }
        else if (res < 0) {
            fprintf(stderr, "Error reading file\n");
            break; // ������ ������
        }

        (*num_students)++;
    }
}