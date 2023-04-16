#include "HelloC.h"





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

// https://school.programmers.co.kr/learn/courses/30/lessons/12901
char* solutionMonth(int a, int b) 
{
	int daySum = 0;
	int day;
	int months[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// 나머지 연산 시 1일 때가 금(FRI)요일 이므로 시작을 THR부터 잡는다
	const char* days[7] = { "THR", "FRI", "SAT", "SUN", "MON", "TUS", "WED" };

	for (int i = 0; i < a - 1; i++)
	{
		daySum += months[i];
	}
	daySum += b;

	// 리턴할 값은 메모리를 동적 할당해주세요.
	char* answer = (char*)malloc(3);
	strcpy(answer, days[daySum % 7]);

	return answer;
}



// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// https://school.programmers.co.kr/learn/courses/30/lessons/12903
char* solutionMiddleCharacter(const char* s) 
{
	char* temp;
	temp = (char*)malloc(strlen(s) * sizeof(char));
	strcpy(temp, s);

	int size = (strlen(temp) % 2) == 1 ? 1 : 2;
	int startPos = 0;

	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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
	printf("=============== [C 프로그래밍 코딩테스트 풀이] ===============\n");
	printf("최초 작성일 : 2023.04.13\n");
	printf("최근 수정일 : 2023.04.16\n");
	printf("developed by KimDaewhi\n");
	printf("Ver 1.1.0\n");
	printf("==============================================================\n");
	printf("[1] 2016년\n");
	printf("[2] 가운데 글자 가져오기\n");
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

		case 50:
		{
			char str[] = "abcdef";
			int len = strlen(str);

			printf("입력된 문자열: %s , 문자열 크기 : %d\n", str, strlen(str));
			char* rslt = solutionMiddleCharacter(str);
			printf("rslt : %s\n", rslt);
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