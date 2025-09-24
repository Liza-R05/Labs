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
	puts("Введите число: ");
	scanf("%d", &dym);
	printf("Введено число: %d \n\n", dym);
	result1 = D * dym;
	printf("%d дюймов – это %.1f см\n\n", dym, result1);
	int pulgada;
	float result2;
	puts("Введите число: ");
	scanf("%d", &pulgada);
	printf("Введено число: %d \n\n", pulgada);
	result2 = A * pulgada;
	printf("%d испанских дюймов – это %.1f см\n\n", pulgada, result2);
}
