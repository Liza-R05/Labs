#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
    setlocale(LC_ALL, "RUS");
    double x1, x2, step, x, fx;
    printf("Табулирование функции f(x) = x^3 + 3*x^2 - 3\n");
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

    for (x = x1; x <= x2; x += step) 
    {
        fx = pow(x, 3) + 3 * pow(x, 2) - 3;
        printf("|%5.2lf|%10.2lf|\n", x, fx);
    }
    printf("__________________\n");
    return 0;
    system("pause");
}
