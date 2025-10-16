#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	printf("+");
	for (int start = 1; start <= 5; start++)
	{
		putchar('*');
		putchar('!');
	}
	for (int start = 1; start <= 5; start++)
	{
		putchar('$');
		putchar('!');
	}
	printf("+");
	printf("\n\n\n");
	system("pause");
}
