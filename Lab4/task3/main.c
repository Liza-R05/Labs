#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int A = 778, B = 1, C = 29;
	int a = (A % 2 == 0 && B % 2 != 0) || (A % 2 != 0 && B % 2 == 0);
	int b = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);
	printf("Условие а):\n");
	printf("A %% 2 = %d, B %% 2 = %d\n", A % 2, B % 2);
	printf("Условие выполнено (1 - да, 0 - нет): %d\n\n", a);
	printf("Условие б):\n");
	printf("A %% 3 = %d, B %% 3 = %d, C %% 3 = %d\n", A % 3, B % 3, C % 3);
	printf("Условие выполнено (1 - да, 0 - нет): %d\n", b);
	getchar();
}
