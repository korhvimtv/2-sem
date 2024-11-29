#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Структура узла дерева
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
struct Node* isMin(struct Node* root);
struct Node* deleteNode(struct Node* root, int data);
void preOrder(struct Node* root);
void inOrder(struct Node* root);
void postOrder(struct Node* root);
