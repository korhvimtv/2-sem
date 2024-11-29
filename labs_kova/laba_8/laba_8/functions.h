#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define CLASS_LEN 10
#define NUM_GRADES 5

typedef struct Node {
    char name[NAME_LEN];
    char surname[NAME_LEN];
    char clas[CLASS_LEN];
    int grades[NUM_GRADES];
    struct Node* next;
} Node;

void write_to_file(Node* s, const char* filename);

void input_data();

void read_data(const char* filename);

void search_student_by_last_name(const char* surname);

void output_all_students();

void delete_student_by_last_name(const char* surname);

void task();

int count_students_without_low_marks(Node* tail);

void printTopStudents(Node* tail);

void print();