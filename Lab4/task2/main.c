#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define k 7
void main()
{
	setlocale(LC_ALL, "RUS");
	float x, y, a, b;
	printf("Введите значение х: ");
	scanf("%f", &x);
	printf("\nx=%.1f", x);
	printf("\n=======================================\n");
	printf("\nПроведем рассчеты и найдем у");
	printf("\n1) Неизвестная b = %.1f", log10(fabs(k*x)));
	printf("\n1) Неизвестная a = %.1f", pow(k+x,3));
	printf("\n1) Неизвестная y = %.3f", pow(log10(fabs(k * x)),2)+sqrt(fabs(pow(k + x, 3))));
	printf("\n=======================================\n");
	getchar();
}