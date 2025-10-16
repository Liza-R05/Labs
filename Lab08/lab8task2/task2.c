#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	double x1, x2, step, fx;
    printf("Табулирование функции f(x) = x^3 - 3x^2 - 3\n");
    printf("Введите начальное значение x: ");
    scanf("%lf", &x1);
    printf("Введите конечное значение x: ");
    scanf("%lf", &x2);
    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);
    printf("\n");
    printf("__________________\n");
    printf("|  x  |   f(x)   |\n");
    printf("|-----|----------|\n");
    while (x1 <= x2) 
    {
        fx = x1*x1*x1 - 3*x1*x1 - 3;
        printf("|%5.2lf|%10.2lf|\n", x1, fx);
        x1 += step;
    }
    printf("__________________\n");
    return 0;
    system("pause");
}
