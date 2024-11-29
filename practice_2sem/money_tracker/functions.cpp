#include "header.h"

// ������������� �����
void initializeStack(Node** top) 
{
    *top = NULL;
}

// ��������, ���� �� ����
int isEmpty(Node* top) 
{
    return (top == NULL);
}

// ���������� �������� � ����
void push(Node** top, float newData) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("������ ��������� ������\n");
        exit(EXIT_FAILURE);
    }
    newNode->amount = newData;
    newNode->next = *top;
    *top = newNode;
}

// �������� �������� �� �����
float pop(Node** top) 
{
    if (isEmpty(*top)) 
    {
        printf("���� ����\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    float data = temp->amount;
    *top = (*top)->next;
    free(temp);
    return data;
}

// ������� ���������� ���������� � ����
void addTransToStack(struct moneyTracker* tracker, float amount) 
{
    push(&(tracker->stack), amount);
}


int isBalanceZero(float a)
{
    if (a == 0)
    {
        printf("ERROR!\nYour balance is NULL.\n");
        rewind(stdin);
        while (getchar() != '\n');
        return 0;
    }
    else
    {
        return 1;
    }
}

float isFloat(float a)
{
    int result = 0;
    do
    {
        rewind(stdin);
        result = scanf_s("%f", &a);
        if (result == true) // �������� ����
        {
            return a;
        }
        else
        {
            printf("INVALID VALUE! Try again.\n > ");
            rewind(stdin);
        }
    } while (1);
}

float isInt(int a)
{
    int result = 0;
    do
    {
        rewind(stdin);
        result = scanf_s("%d", &a);
        if (result == true) // �������� ����
        {
            return a;
        }
        else
        {
            printf("INVALID VALUE! Try again.\n > ");
            rewind(stdin);
        }
    } while (1);
}

void openFiles(moneyTracker* tracker, int files, FILE** mt, FILE** ut, FILE** tt, FILE** rt)
{
    /* W+ - ������� ����� + ������ � ������ � ������
       R+ - �������� ����� + ������ � ������ � ������ */

    errno_t mrr, urr, trr, rrr;
    if (files == 1)
    {
        mrr = fopen_s(mt, "balance.txt", "w+");
        if (mrr != 0) // �������� �� �������� �����
        {
            printf("������ �������� �����.");
            return;
        }
        urr = fopen_s(ut, "moneybox.txt", "w+");
        if (urr != 0)
        {
            printf("������ �������� �����.");
            return;
        }
        trr = fopen_s(tt, "transactions.txt", "w+");
        if (trr != 0)
        {
            printf("������ �������� �����.");
            return;
        }
        rrr = fopen_s(rt, "recieves.txt", "w+");
        if (rrr != 0)
        {
            printf("������ �������� �����.");
            return;
        }
    }
    else
    {
        mrr = fopen_s(mt, "balance.txt", "r+");
        if (mrr != 0) // �������� �� �������� �����
        {
            printf("������ �������� �����.");
            return;
        }
        urr = fopen_s(ut, "moneybox.txt", "r+");
        if (urr != 0)
        {
            printf("������ �������� �����.");
            return;
        }
        trr = fopen_s(tt, "transactions.txt", "r+");
        if (trr != 0)
        {
            printf("������ �������� �����.");
            return;
        }
        rrr = fopen_s(rt, "recieves.txt", "r+");
        if (rrr != 0)
        {
            printf("������ �������� �����.");
            return;
        }
        fscanf_s(*mt, "%f", &tracker->balanceSettings.balance); // ������ �������� �� �����
        fscanf_s(*ut, "%f", &tracker->balanceSettings.MB_balance); // ������ �������� �� �����
    }
}

void printFileContents(FILE* file, int a)
{
    char line[100] = {};

    if (a == 5)
    {
        printf("Transactions:\n");
    }
    else
    {
        printf("Receipts:\n");
    }
    rewind(file); // ���������� ������� � ����� �� ������
    while (fgets(line, sizeof(line), file)) 
    {
        printf("%s\n", line);
    }
    rewind(stdin);
    while (getchar() != '\n');
}

void rewriteFloatToFile(FILE* file, float value) 
{
    // ���������, �������� �� ���� �������
    if (file != NULL) 
    {
        // ���������� ��������� � ������ �����
        fseek(file, 0, SEEK_SET);
        // �������������� ��������
        fprintf(file, "%f", value);
        // ������� ����� ������
        fflush(file);
    }
}

void rewriteToFile(FILE* file, float value) 
{
    // ���������, �������� �� ���� �������
    if (file != NULL) 
    {
        // �������������� ��������
        fprintf(file, "%f\n", value);
        // ������� ����� ������
        fflush(file);
    }
}

float readFloatFromFile(FILE* file)
{
    float value;
    // ���������, ��� ���� ������
    if (file == NULL) 
    {
        fprintf(stderr, "������: ���� �� ������!\n");
        return 0.0f;
    }

    // ������ �������� ���� float �� �����
    if (fscanf_s(file, "%f", &value) != 1)
    {
        fprintf(stderr, "������ ������ �������� ���� float �� �����!\n");
        return 0.0f;
    }

    return value;
}

float inputBalance(float balance, FILE* f)
{
    do
    {
        printf("Current balance: %.2f", balance);
        rewind(stdin);
        printf("\n\nEnter balance (min = 0.01 | max = 1 000 000 000.00) > ");
        balance = isFloat(balance); // �������� �� ���� ����������� ��������
        if (balance < 0.01 || balance > 1000000000.00)
        {
            system("cls");
            printf("Invalid value.\nPlease, try again.");
            continue;
        }
        system("cls");
    } while (balance < 0.01 || balance > 1000000000.00);
    rewriteFloatToFile(f, balance); // ���������� ������� � ����
    return balance;
}


float addTrans(struct moneyTracker* tracker, FILE* f, FILE* t) 
{
    int choice;
    float help = 0.00;
    int rezult = 0;
    rezult = isBalanceZero(tracker->balanceSettings.balance); // �������� �� �������� �������
    if (rezult == 0) 
    {
        return 0.0;
    }
    printf("What kind of transaction do you want to add?\n");
    printf("1 - Home\n2 - Health\n3 - Food\n4 - Other\n");
    scanf_s("%d", &choice);

    /* ��� ���������� */
    switch (choice) 
    {
    case 1:
        printf("        HOME\n");
        printf("---------------------\n");
        break;
    case 2:
        printf("        HEALTH\n");
        printf("---------------------\n");
        break;
    case 3:
        printf("        FOOD\n");
        printf("---------------------\n");
        break;
    case 4:
        printf("        OTHER\n");
        printf("---------------------\n");
        break;
    default:
        printf("Invalid choice\n");
        rewind(stdin);
        while (getchar() != '\n');
        return 0.0;
    }

    printf("Enter the purchase amount > ");
    scanf_s("%f", &(tracker->transactionSettings.minus));
    tracker->balanceSettings.balance -= tracker->transactionSettings.minus;

    // ���������� �������� � ����
    addTransToStack(tracker, tracker->transactionSettings.minus);

    // ������ �������� � ����
    rewriteToFile(t, tracker->transactionSettings.minus);

    // ���������� �������
    rewriteFloatToFile(f, tracker->balanceSettings.balance);

    return tracker->balanceSettings.balance;
}

float removeLastTransFromStack(moneyTracker* tracker, FILE* f, FILE* r) 
{
    if (isEmpty(tracker->stack)) 
    {
        printf("ERROR! You have no transactions in this session\n");
        rewind(stdin);
        while (getchar() != '\n');
        return 0.0;
    }
    float lastTrans = pop(&(tracker->stack));
    tracker->balanceSettings.balance += lastTrans;
    rewriteFloatToFile(f, tracker->balanceSettings.balance);
    rewriteToFile(r, lastTrans);
    return lastTrans;
}

float addReceipt(moneyTracker* tracker, FILE* f, FILE* r)
{
    int choice;
    printf("What kind of cash receipt do you want to add?\n");
    printf("1 - Salary\n2 - Fee\n3 - Admission\n4 - Other\n > ");
    scanf_s("%d", &choice);
    /* ��� ����������� */
    switch (choice)
    {
    case 1:
        printf("       SALARY\n");
        printf("---------------------\n");
        break;
    case 2:
        printf("         FEE\n");
        printf("---------------------\n");
        break;
    case 3:
        printf("      ADMISSION\n");
        printf("---------------------\n");
        break;
    case 4:
        printf("        OTHER\n");
        printf("---------------------\n");
        break;
    default:
        printf("Invalid choice\n");
        rewind(stdin);
        while (getchar() != '\n');
        return 0.0;
    }
    printf("Enter the amount > ");
    scanf_s("%f", &(tracker->transactionSettings.plus));
    tracker->balanceSettings.balance += tracker->transactionSettings.plus;
    rewriteToFile(r, tracker->transactionSettings.plus); // ������ ����������� � ����
    rewriteFloatToFile(f, tracker->balanceSettings.balance); // ���������� �������
    return tracker->balanceSettings.balance;
}

void moneyConverter(float balance)
{
    int rezult = 0;
    rezult = isBalanceZero(balance);
    if (rezult == 0)
    {
        return;
    }
    int choiceCon = 0;
    float helpAm = 0.0;
    printf("Choose desired currency\n\n 1 - USD\n 2 - RUB\n 3 - CNY\n  > ");
    scanf_s("%d", &choiceCon);
    printf("Enter the amount you want you transfer. (from 0.00 to %.2f)\n  > ", balance);
    while (1)
    {
        helpAm = isFloat(helpAm); // �������� �� ���� ����������� ��������
        if (helpAm >= balance || helpAm < 0)
        {
            printf("Invalid value!\nPlease, try again.");
        }
        else
        {
            break;
        }
    }

    /* ����� ������ ��� ��������������� */
    switch (choiceCon)
    {
    case 1:
        printf("\nYour current balance in USD - %f\nThe entered amount in USD - %f", balance = balance / 3.23, helpAm = helpAm / 3.23);
        rewind(stdin);
        while (getchar() != '\n');
        break;
    case 2:
        printf("\nYour current balance in RUB - %f\nThe entered amount in RUB - %f", balance = balance * 3.56, helpAm = helpAm * 3.56);
        rewind(stdin);
        while (getchar() != '\n');
        break;
    case 3:
        printf("\nYour current balance in CYN - %f\nThe entered amount in CYN - %f", balance = balance * 2.28, helpAm = helpAm * 2.28);
        rewind(stdin);
        while (getchar() != '\n');
        break;
    }
}

float checkMB_op(float a, moneyTracker* tracker)
{
    do
    {
        a = isFloat(a); // �������� �� ���� ����������� ��������
        if (a <= 0 || a > tracker->balanceSettings.MB_balance)
        {
            printf("ERROR! Try again.\n > ");
        }
        else
        {
            return a;
        }
    } while (1);
}

float checkMB_op_add(float a, moneyTracker* tracker)
{
    do
    {
        a = isFloat(a); // �������� �� ���� ����������� ��������
        if (a <= 0 || a > tracker->balanceSettings.balance)
        {
            printf("ERROR! Try again.\n > ");
        }
        else
        {
            return a;
        }
    } while (1);
}

void moneyBox(moneyTracker* tracker, FILE* f, FILE* a)
{
    int rezult = 0, rez = 0;
    int MB_choice = 0;
    float MB_operation = 0;
    do
    {
        MB_operation = 0;
        printf("      MONEY BOX\n---------------------\n");
        printf("  BALANCE: %.2f\n", tracker->balanceSettings.MB_balance);
        printf("Do you want to receive (1) or add (2) money? (Any key to EXIT)\n > ");
        scanf_s("%d", &MB_choice);
        if (MB_choice == 1)
        {
            if (tracker->balanceSettings.MB_balance == 0.00)
            {
                printf("ERROR!\nYou habe no money in your money box.");
                rewind(stdin);
                while (getchar() != '\n');
                break;
            }
            else
            {
                rez = isBalanceZero(tracker->balanceSettings.MB_balance); // �������� �� �������� �������
                if (rez == 0)
                {
                    return;
                }
                printf("\n Please, enter the sum what you want to recive\n(min = 0 | max = %.2f)\n > ", tracker->balanceSettings.MB_balance);
                MB_operation = checkMB_op(MB_operation, tracker); // �������� �����
                tracker->balanceSettings.MB_balance -= MB_operation;
                tracker->balanceSettings.balance += MB_operation;
                break;
            }
        }
        else if (MB_choice == 2)
        {
            rez = isBalanceZero(tracker->balanceSettings.balance); // �������� �� �������� �������
            if (rez == 0)
            {
                return;
            }
            printf("\n Please, enter the sum what you want to add\n(min = 0 | max = %.2f)\n > ", tracker->balanceSettings.balance);
            MB_operation = checkMB_op_add(MB_operation, tracker); // �������� �����
            tracker->balanceSettings.MB_balance += MB_operation;
            tracker->balanceSettings.balance -= MB_operation;
            break;
        }
        else
        {
            system("cls");
            printf("INVALID VALUE!\nTry again.");
        }
    } while (MB_choice == 1 || MB_choice == 2);
    rewriteFloatToFile(f, tracker->balanceSettings.balance); // ���������� �������
    rewriteFloatToFile(a, tracker->balanceSettings.MB_balance); // ���������� ������� �������
}