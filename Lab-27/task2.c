#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// произведение цифр числа
int product_of_digits(int n) 
{
    // базовый случай
    if (n < 10) 
    {
        return n;
    }

    // рекурсивный случай - последняя цифра * произв цифр оставшегося числа
    return (n % 10) * product_of_digits(n / 10);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int number;
    printf("Введите натуральное число: ");
    scanf("%d", &number);

    if (number < 0) 
    {
        number = -number; // модуль для отрицательных чисел
    }

    if (number == 0) 
    {
        printf("Произведение цифр числа 0 = 0\n");
    }
    else
    {
        int result = product_of_digits(number);
        printf("Произведение цифр числа %d = %d\n", number, result);
    }

    // тестовые
    //printf("Число 123: %d\n", product_of_digits(123));      // 1*2*3 = 6
    //printf("Число 456: %d\n", product_of_digits(456));      // 4*5*6 = 120
    //printf("Число 7: %d\n", product_of_digits(7));          // 7
    //printf("Число 100: %d\n", product_of_digits(100));      // 1*0*0 = 0

    return 0;
}
