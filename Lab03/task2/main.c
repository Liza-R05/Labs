#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define      D       2.54
#define      A       2,32166
void main()
{
	setlocale(LC_ALL, "RUS");
	int dym;
	float result1;
	puts("������� �����: ");
	scanf("%d", &dym);
	printf("������� �����: %d \n\n", dym);
	result1 = D * dym;
	printf("%d ������ � ��� %.1f ��\n\n", dym, result1);
	int pulgada;
	float result2;
	puts("������� �����: ");
	scanf("%d", &pulgada);
	printf("������� �����: %d \n\n", pulgada);
	result2 = A * pulgada;
	printf("%d ��������� ������ � ��� %.1f ��\n\n", pulgada, result2);
}