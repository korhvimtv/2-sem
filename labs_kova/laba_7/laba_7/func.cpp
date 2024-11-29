#include "source.h"

// ������� �������� ������ ����
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ������� ���������� ���� � ������
struct Node* insertNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data); // ������ �������
    }

    if (data < root->data) 
    {
        root->left = insertNode(root->left, data); // ������ � ����� ���������
    }
    else if (data > root->data) 
    {
        root->right = insertNode(root->right, data); // ������ � ������ ���������
    }

    return root;
}

// ������� ���������� ������������ �������� � ������ ���������
struct Node* isMin(struct Node* root) 
{
    while (root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

// ������� �������� ���� �� ������
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return root; // ������ ������
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
        if (root->left == NULL) // ���� ���� ������ ��������� ����
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) // ���� ���� ������� ��������� ����
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // ���� � ������, � ����� �������� ����

        struct Node* temp = isMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// ������� ��������� ������ � ������ �������
void preOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        preOrder(root->left); // ����������� ����� ��� ������ ������ ���������
        preOrder(root->right); // ����������� ����� ��� ������ ������� ���������
    }
}

// ������� ��������� ������ � ������������ �������
void inOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        inOrder(root->left); // ����������� ����� ��� ������ ������ ���������
        printf("%d ", root->data);
        inOrder(root->right); // ����������� ����� ��� ������ ������� ���������
    }
}

// ������� ��������� ������ � �������� �������
void postOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        postOrder(root->left); // ����������� ����� ��� ������ ������ ���������
        postOrder(root->right); // ����������� ����� ��� ������ ������� ���������
        printf("%d ", root->data);
    }
}
