#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// вычисление 2 в степени n
int power_of_two(int n)
{
    // базовый случай
    if (n == 0)
    {
        return 1;
    }

    // рекурсивный случай 2^n = 2 * 2^(n-1)
    return 2 * power_of_two(n - 1);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    printf("Введите степень n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Степень не может быть отрицательной\n");
        return 1;
    }

    if (n > 30)
    {
        printf("При n > 30 может произойти переполнение int\n");
    }

    int result = power_of_two(n);

    printf("2^%d = %d\n", n, result);

    // тестовые
    // printf("2^0 = %d\n", power_of_two(0));
    // printf("2^1 = %d\n", power_of_two(1));
    // printf("2^5 = %d\n", power_of_two(5));
    // printf("2^10 = %d\n", power_of_two(10));

    return 0;
}