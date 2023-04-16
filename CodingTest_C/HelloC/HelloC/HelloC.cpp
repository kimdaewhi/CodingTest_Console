#include "HelloC.h"





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

// https://school.programmers.co.kr/learn/courses/30/lessons/12901
char* solutionMonth(int a, int b) 
{
	int daySum = 0;
	int day;
	int months[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// ������ ���� �� 1�� ���� ��(FRI)���� �̹Ƿ� ������ THR���� ��´�
	const char* days[7] = { "THR", "FRI", "SAT", "SUN", "MON", "TUS", "WED" };

	for (int i = 0; i < a - 1; i++)
	{
		daySum += months[i];
	}
	daySum += b;

	// ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
	char* answer = (char*)malloc(3);
	strcpy(answer, days[daySum % 7]);

	return answer;
}



// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
// https://school.programmers.co.kr/learn/courses/30/lessons/12903
char* solutionMiddleCharacter(const char* s) 
{
	char* temp;
	temp = (char*)malloc(strlen(s) * sizeof(char));
	strcpy(temp, s);

	int size = (strlen(temp) % 2) == 1 ? 1 : 2;
	int startPos = 0;

	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	char* answer = (char*)malloc((size + 1) * sizeof(char));
	if (size == 1)
	{
		startPos = (strlen(temp) / 2); // abcde
		answer[0] = temp[startPos];
	}
	else
	{
		startPos = (strlen(s) / 2) - 1;
		answer[0] = temp[startPos];
		answer[1] = temp[startPos + 1];
	}
	answer[size] = '\0';

	return answer;
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
	printf("\n");
}

void PrintSolution(int i)
{
	printf("\n");
	switch (i)
	{
		case 49:
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

		case 50:
		{
			char str[] = "abcdef";
			int len = strlen(str);

			printf("�Էµ� ���ڿ�: %s , ���ڿ� ũ�� : %d\n", str, strlen(str));
			char* rslt = solutionMiddleCharacter(str);
			printf("rslt : %s\n", rslt);
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