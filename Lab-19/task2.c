#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    double x1, x2, step, x, fx;
    FILE* file;
    char m;

    printf("Табулирование функции f(x) = x^3 + 3*x^2 - 3\n\n");
    printf("1 - Запись в новый файл\n");
    printf("2 - Добавление в конец существующего\n");
    printf("Выбор: ");
    scanf(" %c", &m);

    if (m == '1')
    {
        file = fopen("temp.txt", "wt");
    }
    else if (m == '2')
    {
        file = fopen("temp.txt", "at");
    }
    else
    {
        printf("Ошибка: неверный выбор режима.\n");
        system("pause");
        return 1;
    }
    if (file == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        system("pause");
        return 1;
    }

    printf("Введите начальное значение x: ");
    scanf("%lf", &x1);
    printf("Введите конечное значение x: ");
    scanf("%lf", &x2);
    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);

    if (m == '2')
    {
        fprintf(file, "\n\n------\n");
    }

    printf("\n");
    printf("Результаты табулирования:\n");
    printf("__________________\n");
    printf("|  x  |   f(x)   |\n");
    printf("|-----|----------|\n");

    // в файл
    fprintf(file, "Табулирование функции f(x) = x^3 + 3*x^2 - 3\n");
    fprintf(file, "Интервал: [%.2lf, %.2lf], Шаг: %.2lf\n\n", x1, x2, step);
    fprintf(file, "__________________\n");
    fprintf(file, "|  x  |   f(x)   |\n");
    fprintf(file, "|-----|----------|\n");

    for (x = x1; x <= x2; x += step)
    {
        fx = pow(x, 3) + 3 * pow(x, 2) - 3;
        // в консоль
        printf("|%5.2lf|%10.2lf|\n", x, fx);
        // в файл
        fprintf(file, "|%5.2lf|%10.2lf|\n", x, fx);
    }

    printf("__________________\n");
    fprintf(file, "__________________\n");

    fclose(file);
    system("pause");
    return 0;
}
