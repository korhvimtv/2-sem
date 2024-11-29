#include "source.h"

int main() 
{
    setlocale(LC_ALL, "rus");
    struct Node* root = NULL;
    int choice, value;

    while (1) 
    {
        system("cls");
        printf(" �������� ������\n1. �������� ����\n2. ������� ����\n3. ������ �������\n4. ������������ �������\n5. �������� �������\n6. �����\n");
        printf("������� ��� �����: ");
        scanf_s("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("������� �������� ��� ����������: ");
            scanf_s("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("������� �������� ��� ��������: ");
            scanf_s("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            if (root == NULL)
            {
                printf("������ ������");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            printf("������ �������: ");
            preOrder(root);
            printf("\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 4:
            if (root == NULL)
            {
                printf("������ ������");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            printf("������������ �������: ");
            inOrder(root);
            printf("\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 5:
            if (root == NULL)
            {
                printf("������ ������");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            printf("�������� �������: ");
            postOrder(root);
            printf("\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 6:
            exit(0);
        default:
            printf("�������� �����, ���������� �����.\n");
            rewind(stdin);
            while (getchar() != '\n');
        }
    }
}