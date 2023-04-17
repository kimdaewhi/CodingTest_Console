#include "Solutions.h"


// https://school.programmers.co.kr/learn/courses/30/lessons/12912
long solutionBetweenAdd(int a, int b)
{
	long answer = 0;
	if (a <= b)
	{
		for (int i = a; i <= b; i++)
		{
			answer += i;
		}
	}
	else
	{
		for (int i = a; i >= b; i--)
		{
			answer += i;
		}
	}
	return answer;
}


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


// https://school.programmers.co.kr/learn/courses/30/lessons/12917?language=c
char* solutionStrDesc(const char* s)
{
	char* temp;
	temp = (char*)malloc(strlen(s) * sizeof(char));
	strcpy(temp, s);
	int len = strlen(temp);

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if ((int)temp[j] < (int)temp[j + 1])
			{
				char tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	char* answer = (char*)malloc(strlen(temp) * sizeof(char));
	strcpy(answer, temp);
	return answer;
}

