#include "HelloC.h"
#include "Solutions.h"





void mallocSample()
{
	int *arr;
	int size, i;

	printf("배열의 크기를 입력하세요: ");
	scanf("%d", &size);

	// malloc() 함수를 사용하여 동적으로 메모리 할당
	arr = (int*)malloc(size * sizeof(int));

	if (arr == NULL)
	{
		printf("메모리 할당에 실패했습니다.");
		return;
	}

	for (i = 0; i < size; i++)
	{
		printf("arr[%d]의 값을 입력하세요: ", i);
		scanf("%d", &arr[i]);
	}

	printf("입력한 값은 다음과 같습니다.\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	// 동적으로 할당한 메모리 해제
	free(arr);
}

void PrintConsole()
{
	printf("=============== [C 프로그래밍 코딩테스트 풀이] ===============\n");
	printf("최초 작성일 : 2023.04.13\n");
	printf("최근 수정일 : 2023.04.16\n");
	printf("developed by KimDaewhi\n");
	printf("Ver 1.1.0\n");
	printf("==============================================================\n");
	printf("[1] 2016년\n");
	printf("[2] 가운데 글자 가져오기\n");
	printf("[3] 두 정수 사이의 합\n");
	printf("[4] 문자열 내림차순 정렬\n");
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
			printf("2개의 정수를 입력하세요 : ");

			scanf("%d", &a);
			scanf("%d", &b);

			if ((a == 0 || b == 0) || (a > 12 || b > 31))
			{
				printf("월/일의 입력이 잘못되었습니다.\n");
				return;
			}
			char* rslt = solutionMonth(a, b);
			printf("2016년 %d월 %d일은 %s입니다.\n", a, b, rslt);;
		}
		break;

		case 50:			// 2
		{
			// char str[] = "abcdef";
			char str[100];
			printf("문자열 입력하세요 : ");
			scanf("%s", str);
			int len = strlen(str);

			printf("입력된 문자열: %s , 문자열 크기 : %d\n", str, strlen(str));
			char* rslt = solutionMiddleCharacter(str);
			printf("rslt : %s\n", rslt);
		}
		break;

		case 51:			// 3
		{
			int a, b;
			printf("2개의 정수를 입력하세요 : ");
			scanf("%d", &a);
			scanf("%d", &b);

			long rslt = solutionBetweenAdd(a, b);
			printf("%d ~ %d 사이의 정수의 합은 %d 입니다.\n", a, b, rslt);
		}
		break;

		case 52:			// 4
		{
			char str[100];
			printf("문자열 입력하세요 : ");
			scanf("%s", str);

			char* rslt = solutionStrDesc(str);
			printf("내림차순으로 정렬된 문자는 다음과 같습니다.\n");
			printf("%s", str);
			printf(" >> %s\n", rslt);
		}
		break;

		default:
			printf("문제 선택이 잘못되었습니다.\n");
			break;
	}
	printf("계속하려면 아무키나 입력하세요.\n");
	getchar();
	getchar();			// getchar()가 버퍼에 남아있는 개행 문자를 읽어오기 때문에 한번 더 호출해서 개행문자까지 읽어와야 함.
	system("cls");
}


int main(void)
{
	while (true)
	{
		char ch;
		PrintConsole();
		printf("문제를 선택하세요. 종료하려면 ESC를 입력하세요 : ");
		ch = _getch();
		if (ch == 27)
		{
			break;
		}
		PrintSolution(ch);
	}





	return 0;
}