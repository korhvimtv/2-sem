#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define PLACE 30
#define NAME 20

typedef struct
{
    char street[PLACE]; // ���� ��� �������� �������� �����, ������������ ����� 
    char house[PLACE]; // ���� ��� �������� ������ ����, ������������ �����
    char flat[PLACE]; // ���� ��� �������� ������ ��������, ������������ ����� 

} CityAddress;

typedef struct
{

    char region[PLACE]; // ���� ��� �������� �������� �������, ������������ �����  
    char city[PLACE]; // ���� ��� �������� �������� ������, ������������ �����  
    char street[PLACE]; // ���� ��� �������� �������� �����, ������������ �����  
    char house[PLACE]; // ���� ��� �������� ������ ����, ������������ �����  
    char flat[PLACE]; // ���� ��� �������� ������ ��������, ������������ �����  

} RegionCityAddress;

typedef struct
{

    char region[PLACE]; // ���� ��� �������� �������� �������, ������������ �����  
    char district[PLACE]; // ���� ��� �������� �������� ������, ������������ �����  
    char city[PLACE]; // ���� ��� �������� �������� ������, ������������ �����  
    char street[PLACE]; // ���� ��� �������� �������� �����, ������������ �����  
    char house[PLACE]; // ���� ��� �������� ������ ����, ������������ �����  
    char flat[PLACE]; // ���� ��� �������� ������ ��������, ������������ �����  

} RegionDistrictCityAddress;


typedef struct
{

    char region[PLACE]; // ���� ��� �������� �������� �������, ������������ �����  
    char district[PLACE]; // ���� ��� �������� �������� ������, ������������ �����  
    char village[PLACE]; // ���� ��� �������� �������� �������, ������������ �����  
    char house[PLACE]; // ���� ��� �������� ������ ����, ������������ �����  

} RegionDistrictVillageAddress;


typedef union
{

    CityAddress cityAddress; // ���� ���� CityAddress
    RegionCityAddress regionCityAddress; // ���� ���� RegionCityAddress
    RegionDistrictCityAddress regionDistrictCityAddress; // ���� ���� RegionDistrictCityAddress
    RegionDistrictVillageAddress regionDistrictVillageAddress; // ���� ���� RegionDistrictVillageAddress

} Residence;


typedef struct
{
    char name[NAME]; // ���� ��� �������� ����� �������� 
    char LastName[NAME]; // ���� ��� �������� ������� ��������
    Residence residence; // ���� ���� Residence ��� �������� ������ ��������
    int residenceType; // ���� ��� �������� ���� ������ ��������: 0 - �����, 1 - ��������� �����, 2 - �������� �����, 3 - �������
} Student;

// ����������� ��������� ����
typedef struct Node
{
    Student data;
    struct Node* next;
    struct Node* prev;
} Node;



Node* createNode(Student data);
void insertEnd(Node** head, Student data);
void deleteNode(Node** head);
void display(int count, Node* head);
void enter_student_info(Node** head, Student* student); // ������� ����� ���������� � ������ ��������
void enter_residence(Student* student); // ������� ��� ����� ������ � ��������
void print_students(Student* students, int num_students, FILE* mt); // ������� ��� ������ ������ ��������
void print_city_student(int student_num, CityAddress address); // ������� ��� ������ ���������� � ������ ����� ��������� 
void print_region_city_student(int student_num, RegionCityAddress address); // ����� ��������� �� ��������� �������
void print_region_district_city_student(int student_num, RegionDistrictCityAddress address); // ����� ��������� �� ��������
void print_region_district_village_student(int student_num, RegionDistrictVillageAddress address); // ����� ��������� �� ��������
void enter_address(char fields[][30], char* addresses[], int num_fields); // ������� ��� ����� ������ ����������
void search_students_by_residence_type(Student* student, int num_students); //������� ��� ������ ��������� �� ���� ����������
int is_word(const char* str); // �������� ����� �� �����
void create_or_open_file(FILE** file, const char* filename, const char* mode);
void read_from_file(Student** students, int* num_students, FILE* mt);
void write_to_file(Student* students, int num_students, FILE** mt);
void write_ring_to_file(FILE* file, Node* head);
void process_students_space(Student* students, int num_students);
void process_students_slash(Student* students, int num_students);