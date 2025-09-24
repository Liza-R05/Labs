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
	int a, b;
	printf("¬ведите a и b: ");
	scanf("%d %d", &a, &b);
	printf("___________________\n");
    printf("| a*b | a+b | a-b |\n");
    printf("-------------------\n");
    printf("|%2d*%-2d|%2d+%-2d|%2d-%-2d|\n", a, b, a, b, a, b);
    printf("-------------------\n");
    printf("|%3d  |%3d  |%3d  |\n", a * b, a + b, a - b);
    printf("-------------------\n");
}