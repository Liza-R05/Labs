#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int n, m, s = 0;
	int k = 1;
	printf("Введите значения n, m: \n");
	scanf("%d%d", &n, &m);
	for (int i = m; i >= n; i--)
	{
		s += i;
		printf("выполнено %d раз\n", k++);
	}
	printf("результат %d\n", s);
	system("pause");
}
