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
	puts("Введите число: ");
	scanf("%d", &num);
	printf("Введено число: %d \n\n", num);
	int numm;
	puts("Введите число: ");
	scanf("%d", &numm);
	printf("Введено число: %d \n\n", numm);
	printf("Сумма введенных чисел: %d + %d = %d\n", num, numm, num + numm);
	printf("Разность введенных чисел: %d - %d = %d\n", num, numm, num - numm);
	printf("Произведение введенных чисел: %d * %d = %d\n", num, numm, num * numm);
	printf("Частное введенных чисел: %d : %d = %d\n", num, numm, num / numm);
	printf("Остаток от деления второго числа на первое: %d %% %d = %d\n", num, numm, num % numm);
}
