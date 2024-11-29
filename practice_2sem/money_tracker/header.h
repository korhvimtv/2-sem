#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Объявление объединения money
typedef struct money {
    float balance; // Баланс
    float MB_balance; // Баланс копилки
};

// Объявление объединения trans
union trans {
    float plus; // Транзакция
    float minus; // Поступление
};

// Структура узла стека
typedef struct Node {
    float amount;           // Сумма транзакции
    struct Node* next;      // Указатель на следующий узел
} Node;

// Структура moneyTracker
struct moneyTracker {
    struct money balanceSettings; 
    union trans transactionSettings;
    struct Node* stack; // Указатель на вершину стека
};

// функция инициализаци стека
void initializeStack(Node** top);
// функция проверки стека на пустоту
int isEmpty(Node* top);
// функция добавления элемента в стек
void push(Node** top, float newData);
// функция удаления элемента со стека
float pop(Node** top);
// функция удаления последней транзакции
float removeLastTransFromStack(struct moneyTracker* tracker, FILE* f, FILE* r);
// функция открытия файлов
void openFiles(moneyTracker* tracker, int files, FILE** mt, FILE** ut, FILE** tt, FILE** rt);
// функция записи в файл
void printFileContents(FILE* file, int a);
// функция чтения с файла
float readFloatFromFile(FILE* file);
// функция перезаписи в файл
void rewriteFloatToFile(FILE* file, float value);
// функция добавления записи в файл
void rewriteToFile(FILE* file, float value);
// функция ввода баланса
float inputBalance(float a, FILE* f);
// функция добавления транзакции
float addTrans(moneyTracker* tracker, FILE* f, FILE* t);
// функция добавления поступелния
float addReceipt(moneyTracker* tracker, FILE* f, FILE* r);
// функция конвертера валют
void moneyConverter(float balance);
// функция проверки значения
float checkMB_op(float a, moneyTracker* tracker);
// функция проверки значения
float checkMB_op_add(float a, moneyTracker* tracker);
// функция копилки
void moneyBox(moneyTracker* tracker, FILE* f, FILE* a);
// функция проверки корректности ввода
float isInt(int a);

