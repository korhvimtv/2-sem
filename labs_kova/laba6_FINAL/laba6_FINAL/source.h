#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define PLACE 30
#define NAME 20

typedef struct
{
    char street[PLACE]; // Поле для хранения названия улицы, максимальная длина 
    char house[PLACE]; // Поле для хранения номера дома, максимальная длина
    char flat[PLACE]; // Поле для хранения номера квартиры, максимальная длина 

} CityAddress;

typedef struct
{

    char region[PLACE]; // Поле для хранения названия области, максимальная длина  
    char city[PLACE]; // Поле для хранения названия города, максимальная длина  
    char street[PLACE]; // Поле для хранения названия улицы, максимальная длина  
    char house[PLACE]; // Поле для хранения номера дома, максимальная длина  
    char flat[PLACE]; // Поле для хранения номера квартиры, максимальная длина  

} RegionCityAddress;

typedef struct
{

    char region[PLACE]; // Поле для хранения названия области, максимальная длина  
    char district[PLACE]; // Поле для хранения названия района, максимальная длина  
    char city[PLACE]; // Поле для хранения названия города, максимальная длина  
    char street[PLACE]; // Поле для хранения названия улицы, максимальная длина  
    char house[PLACE]; // Поле для хранения номера дома, максимальная длина  
    char flat[PLACE]; // Поле для хранения номера квартиры, максимальная длина  

} RegionDistrictCityAddress;


typedef struct
{

    char region[PLACE]; // Поле для хранения названия области, максимальная длина  
    char district[PLACE]; // Поле для хранения названия района, максимальная длина  
    char village[PLACE]; // Поле для хранения названия деревни, максимальная длина  
    char house[PLACE]; // Поле для хранения номера дома, максимальная длина  

} RegionDistrictVillageAddress;


typedef union
{

    CityAddress cityAddress; // Поле типа CityAddress
    RegionCityAddress regionCityAddress; // Поле типа RegionCityAddress
    RegionDistrictCityAddress regionDistrictCityAddress; // Поле типа RegionDistrictCityAddress
    RegionDistrictVillageAddress regionDistrictVillageAddress; // Поле типа RegionDistrictVillageAddress

} Residence;


typedef struct
{
    char name[NAME]; // Поле для хранения имени студента 
    char LastName[NAME]; // Поле для хранения фамилии студента
    Residence residence; // Поле типа Residence для хранения адреса студента
    int residenceType; // Поле для хранения типа адреса студента: 0 - Минск, 1 - Областной центр, 2 - Районный город, 3 - Деревня
} Student;

// Определение структуры узла
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
void enter_student_info(Node** head, Student* student); // функция ввода информации о каждом студенте
void enter_residence(Student* student); // функция для ввода данных о студенте
void print_students(Student* students, int num_students, FILE* mt); // функция для вывода данных таблицей
void print_city_student(int student_num, CityAddress address); // функции для вывода информации о разных типах студентов 
void print_region_city_student(int student_num, RegionCityAddress address); // вывод студентов из областных центров
void print_region_district_city_student(int student_num, RegionDistrictCityAddress address); // вывод студентов из областей
void print_region_district_village_student(int student_num, RegionDistrictVillageAddress address); // вывод студентов из деревень
void enter_address(char fields[][30], char* addresses[], int num_fields); // функция для ввода адреса проживания
void search_students_by_residence_type(Student* student, int num_students); //функция для поиска студентов по типу проживания
int is_word(const char* str); // проверка ввода на слово
void create_or_open_file(FILE** file, const char* filename, const char* mode);
void read_from_file(Student** students, int* num_students, FILE* mt);
void write_to_file(Student* students, int num_students, FILE** mt);
void write_ring_to_file(FILE* file, Node* head);
void process_students_space(Student* students, int num_students);
void process_students_slash(Student* students, int num_students);