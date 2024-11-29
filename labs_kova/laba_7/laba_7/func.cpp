#include "source.h"

// Функция создания нового узла
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция добавления узла в дерево
struct Node* insertNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data); // Запись вершины
    }

    if (data < root->data) 
    {
        root->left = insertNode(root->left, data); // Запись в левое поддерево
    }
    else if (data > root->data) 
    {
        root->right = insertNode(root->right, data); // Запись в правое поддерево
    }

    return root;
}

// Функция нахождения минимального значения в правом поддереве
struct Node* isMin(struct Node* root) 
{
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

// Функция удаления узла из дерева
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return root; // Дерево пустое
    }

    if (data < root->data) 
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) 
    {
        root->right = deleteNode(root->right, data);
    }
    else 
    {
        if (root->left == NULL) // Если нету левого дочернего узла
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) // Если нету правого дочернего узла
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Есть и правый, и левый дечерние узлы

        struct Node* temp = isMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Функция просмотра дерева в прямом порядке
void preOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preOrder(root->left); // Рекурсивный вызов для обхода левого поддерева
        preOrder(root->right); // Рекурсивный вызов для обхода правого поддерева
    }
}

// Функция просмотра дерева в симметричном порядке
void inOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        inOrder(root->left); // Рекурсивный вызов для обхода левого поддерева
        printf("%d ", root->data);
        inOrder(root->right); // Рекурсивный вызов для обхода правого поддерева
    }
}

// Функция просмотра дерева в обратном порядке
void postOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        postOrder(root->left); // Рекурсивный вызов для обхода левого поддерева
        postOrder(root->right); // Рекурсивный вызов для обхода правого поддерева
        printf("%d ", root->data);
    }
}
