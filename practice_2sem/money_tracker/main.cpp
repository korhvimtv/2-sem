#include "header.h"

int main()
{
	struct moneyTracker* tracker; // ������������� ���������
	int menuChoice = 0;
	tracker = (struct moneyTracker*)malloc(1 * sizeof(struct moneyTracker));
	tracker->balanceSettings.balance = 0;
	tracker->balanceSettings.MB_balance = 0;
	initializeStack(&(tracker->stack));
	int files;
	FILE* mt = NULL;
	FILE* ut = NULL;
	FILE* tt = NULL;
	FILE* rt = NULL;
	printf("Do you want to delete old data, or use old data?\n 1 - DELETE || Any Key - OLD DATA\n > ");
	scanf_s("%d", &files);
	openFiles(tracker, files, &mt, &ut, &tt, &rt); // ������� �������� ������
	do
	{
		system("cls");
		rewind(stdin);
		printf(" MONEY TRACKER ");
		printf("\n\n");
		printf(" BALANCE: %.2f\n\n", tracker->balanceSettings.balance);
		printf(" MENU: \n");
		printf("0 - Input balance\n1 - Add transaction\n2 - Add receipt\n3 - Money box\n4 - Currency converter\n5 - Your transactions\n6 - Your receipts\n7 - Remove last transaction\n8 - EXIT\n\n");
		printf("Enter point > ");
		menuChoice = isInt(menuChoice);

		/* ���� ���������� */

		switch (menuChoice)
		{
		case 0:
			system("cls");
			tracker->balanceSettings.balance = inputBalance(tracker->balanceSettings.balance, mt); // ����� ������� ����� �������
			continue;

		case 1:
			system("cls");
			addTrans(tracker, mt, tt); // ����� ������� ���������� ����������
			continue;

		case 2:
			system("cls");
			addReceipt(tracker, mt, rt); // ����� ������� ���������� �����������
			continue;

		case 3:
			system("cls");
			moneyBox(tracker, mt, ut); // ����� ������� �������
			continue;

		case 4:
			system("cls");
			moneyConverter(tracker->balanceSettings.balance); // ����� ������� ���������� �����
			continue;

		case 5:
			system("cls");
			printFileContents(tt, menuChoice); // ����� ������� ������ ����������
			continue;

		case 6:
			system("cls");
			printFileContents(rt, menuChoice); // ����� ������� ������ �����������
			continue;

		case 7:
			system("cls");
			removeLastTransFromStack(tracker, mt, rt);
			continue;

		case 8:
			system("cls");
			return 0;

		default:
			continue;
		}
	} while (1);
}
