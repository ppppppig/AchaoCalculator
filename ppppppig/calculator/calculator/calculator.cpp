﻿#include"pch.h"
#include <stdio.h>

#include <ctype.h>

#include <time.h>

#include <stdlib.h>

#include <windows.h>

#define IDNO_LENGTH 6

#define CALC_KIND 4



char getSignal();

int getResult(int, int, char);

void takeTest();

void falsePrint(int);

void correctPrint(int);

//main函数

int main()

{
	int n;
	printf("这次你想做多少题啊：");
	scanf_s("%d", &n);

	while (n)

	{
		n--;
		takeTest();

	}

}

//获取随机运算符

char getSignal()

{

	char signal[CALC_KIND] = { '+','-','*','/' };

	srand((unsigned)time(NULL));

	return signal[rand() % 4];

}

//获取随机数

int random(double start, double end)

{

	return (int)(start + (end - start)*rand() / (RAND_MAX + 1.0));

}

//运算

int getResult(int num1, int num2, char signal)

{

	int res;

	switch (signal)

	{

	case '+':

		res = num1 + num2; break;

	case '-':

		res = num1 - num2; break;

	case '*':

		res = num1 * num2; break;

	case '/':

		res = num1 / num2; break;

	default:

		res = 0;

		printf("运算符不符合规则\n");

	}

	return res;

}



//列出题目

void takeTest()

{

	int giveRes;

	int num1;

	int num2;

	char signal;

	int printFlag;

	srand((unsigned)time(NULL));

	signal = getSignal();

	num1 = random(0, 100);

	num2 = random(1, 100);



	if (signal == '-')

	{

		if (num1 < num2)

		{

			int temp;

			temp = num1;

			num1 = num2;

			num2 = temp;

		}

	}

	if (signal == '/')

	{

		if (num2 == 0)

		{

			int temp;

			temp = num1;

			num1 = num2;

			num2 = temp;

		}

	}

	printf("%d%c%d=", num1, signal, num2);

	scanf_s("%d", &giveRes);

	fflush(stdin);



	if (getResult(num1, num2, signal) == giveRes)

	{

		printFlag = random(1, 5);

		correctPrint(printFlag);

	}

	else

	{

		printFlag = random(1, 4);

		falsePrint(printFlag);

		printf("正确答案：%d\n", getResult(num1, num2, signal));

	}

}

//回答正确打印信息

void correctPrint(int num)

{

	switch (num)

	{

	case 1:

		printf("You're right!\n"); break;

	case 2:

		printf("It's OK!\n"); break;

	case 3:

		printf("Correct!\n"); break;

	case 4:

		printf("Perfect!\n"); break;

	case 5:

		printf("Good!\n"); break;

	default:

		printf("Powerful!\n"); break;

	}

}

//回答错误打印信息

void falsePrint(int num)

{

	switch (num)

	{

	case 1:

		printf("You're lost!"); break;

	case 2:

		printf("Failure!"); break;

	case 3:

		printf("Come on!"); break;

	case 4:

		printf("It's wrong!"); break;

	default:

		printf("Incorrect!"); break;

	}

}
