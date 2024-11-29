#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���������� ����������� money
typedef struct money {
    float balance; // ������
    float MB_balance; // ������ �������
};

// ���������� ����������� trans
union trans {
    float plus; // ����������
    float minus; // �����������
};

// ��������� ���� �����
typedef struct Node {
    float amount;           // ����� ����������
    struct Node* next;      // ��������� �� ��������� ����
} Node;

// ��������� moneyTracker
struct moneyTracker {
    struct money balanceSettings; 
    union trans transactionSettings;
    struct Node* stack; // ��������� �� ������� �����
};

// ������� ������������ �����
void initializeStack(Node** top);
// ������� �������� ����� �� �������
int isEmpty(Node* top);
// ������� ���������� �������� � ����
void push(Node** top, float newData);
// ������� �������� �������� �� �����
float pop(Node** top);
// ������� �������� ��������� ����������
float removeLastTransFromStack(struct moneyTracker* tracker, FILE* f, FILE* r);
// ������� �������� ������
void openFiles(moneyTracker* tracker, int files, FILE** mt, FILE** ut, FILE** tt, FILE** rt);
// ������� ������ � ����
void printFileContents(FILE* file, int a);
// ������� ������ � �����
float readFloatFromFile(FILE* file);
// ������� ���������� � ����
void rewriteFloatToFile(FILE* file, float value);
// ������� ���������� ������ � ����
void rewriteToFile(FILE* file, float value);
// ������� ����� �������
float inputBalance(float a, FILE* f);
// ������� ���������� ����������
float addTrans(moneyTracker* tracker, FILE* f, FILE* t);
// ������� ���������� �����������
float addReceipt(moneyTracker* tracker, FILE* f, FILE* r);
// ������� ���������� �����
void moneyConverter(float balance);
// ������� �������� ��������
float checkMB_op(float a, moneyTracker* tracker);
// ������� �������� ��������
float checkMB_op_add(float a, moneyTracker* tracker);
// ������� �������
void moneyBox(moneyTracker* tracker, FILE* f, FILE* a);
// ������� �������� ������������ �����
float isInt(int a);

