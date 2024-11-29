#include "source.h"

int main() 
{
    setlocale(LC_ALL, "rus");
    struct Node* root = NULL;
    int choice, value;

    while (1) 
    {
        system("cls");
        printf(" БИНАРНОЕ ДЕРЕВО\n1. Добавить узел\n2. Удалить узел\n3. Прямой порядок\n4. Симметричный порядок\n5. Обратный порядок\n6. Выход\n");
        printf("Введите ваш выбор: ");
        scanf_s("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Введите значение для добавления: ");
            scanf_s("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Введите значение для удаления: ");
            scanf_s("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            if (root == NULL)
            {
                printf("Дерево пустое");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            printf("Прямой порядок: ");
            preOrder(root);
            printf("\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 4:
            if (root == NULL)
            {
                printf("Дерево пустое");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            printf("Симметричный порядок: ");
            inOrder(root);
            printf("\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 5:
            if (root == NULL)
            {
                printf("Дерево пустое");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            printf("Обратный порядок: ");
            postOrder(root);
            printf("\n");
            rewind(stdin);
            while (getchar() != '\n');
            break;
        case 6:
            exit(0);
        default:
            printf("Неверный выбор, попробуйте снова.\n");
            rewind(stdin);
            while (getchar() != '\n');
        }
    }
}