#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int num;
	puts("������� �����: ");
	scanf("%d", &num);
	printf("������� �����: %d \n\n", num);
	int numm;
	puts("������� �����: ");
	scanf("%d", &numm);
	printf("������� �����: %d \n\n", numm);
	printf("����� ��������� �����: %d + %d = %d\n", num, numm, num + numm);
	printf("�������� ��������� �����: %d - %d = %d\n", num, numm, num - numm);
	printf("������������ ��������� �����: %d * %d = %d\n", num, numm, num * numm);
	printf("������� ��������� �����: %d : %d = %d\n", num, numm, num / numm);
	printf("������� �� ������� ������� ����� �� ������: %d %% %d = %d\n", num, numm, num % numm);
}