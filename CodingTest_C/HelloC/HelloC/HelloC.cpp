#include "HelloC.h"
#include "Solutions.h"





void mallocSample()
{
	int *arr;
	int size, i;

	printf("�迭�� ũ�⸦ �Է��ϼ���: ");
	scanf("%d", &size);

	// malloc() �Լ��� ����Ͽ� �������� �޸� �Ҵ�
	arr = (int*)malloc(size * sizeof(int));

	if (arr == NULL)
	{
		printf("�޸� �Ҵ翡 �����߽��ϴ�.");
		return;
	}

	for (i = 0; i < size; i++)
	{
		printf("arr[%d]�� ���� �Է��ϼ���: ", i);
		scanf("%d", &arr[i]);
	}

	printf("�Է��� ���� ������ �����ϴ�.\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	// �������� �Ҵ��� �޸� ����
	free(arr);
}

void PrintConsole()
{
	printf("=============== [C ���α׷��� �ڵ��׽�Ʈ Ǯ��] ===============\n");
	printf("���� �ۼ��� : 2023.04.13\n");
	printf("�ֱ� ������ : 2023.04.16\n");
	printf("developed by KimDaewhi\n");
	printf("Ver 1.1.0\n");
	printf("==============================================================\n");
	printf("[1] 2016��\n");
	printf("[2] ��� ���� ��������\n");
	printf("[3] �� ���� ������ ��\n");
	printf("[4] ���ڿ� �������� ����\n");
	printf("\n");
}

void PrintSolution(int i)
{
	printf("\n");
	switch (i)
	{
		case 49:			// 1
		{
			int a, b;
			printf("2���� ������ �Է��ϼ��� : ");

			scanf("%d", &a);
			scanf("%d", &b);

			if ((a == 0 || b == 0) || (a > 12 || b > 31))
			{
				printf("��/���� �Է��� �߸��Ǿ����ϴ�.\n");
				return;
			}
			char* rslt = solutionMonth(a, b);
			printf("2016�� %d�� %d���� %s�Դϴ�.\n", a, b, rslt);;
		}
		break;

		case 50:			// 2
		{
			// char str[] = "abcdef";
			char str[100];
			printf("���ڿ� �Է��ϼ��� : ");
			scanf("%s", str);
			int len = strlen(str);

			printf("�Էµ� ���ڿ�: %s , ���ڿ� ũ�� : %d\n", str, strlen(str));
			char* rslt = solutionMiddleCharacter(str);
			printf("rslt : %s\n", rslt);
		}
		break;

		case 51:			// 3
		{
			int a, b;
			printf("2���� ������ �Է��ϼ��� : ");
			scanf("%d", &a);
			scanf("%d", &b);

			long rslt = solutionBetweenAdd(a, b);
			printf("%d ~ %d ������ ������ ���� %d �Դϴ�.\n", a, b, rslt);
		}
		break;

		case 52:			// 4
		{
			char str[100];
			printf("���ڿ� �Է��ϼ��� : ");
			scanf("%s", str);

			char* rslt = solutionStrDesc(str);
			printf("������������ ���ĵ� ���ڴ� ������ �����ϴ�.\n");
			printf("%s", str);
			printf(" >> %s\n", rslt);
		}
		break;

		default:
			printf("���� ������ �߸��Ǿ����ϴ�.\n");
			break;
	}
	printf("����Ϸ��� �ƹ�Ű�� �Է��ϼ���.\n");
	getchar();
	getchar();			// getchar()�� ���ۿ� �����ִ� ���� ���ڸ� �о���� ������ �ѹ� �� ȣ���ؼ� ���๮�ڱ��� �о�;� ��.
	system("cls");
}


int main(void)
{
	while (true)
	{
		char ch;
		PrintConsole();
		printf("������ �����ϼ���. �����Ϸ��� ESC�� �Է��ϼ��� : ");
		ch = _getch();
		if (ch == 27)
		{
			break;
		}
		PrintSolution(ch);
	}





	return 0;
}