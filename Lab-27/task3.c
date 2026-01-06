#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// способы подъема
int count_ways(int n) 
{
    // базовые случаи
    if (n < 0) 
    {
        return 0;
    }
    if (n == 0) 
    {
        return 1;  // 1 способ
    }

    // рекурсивный случай (n-1) + (n-2) + (n-3)
    return count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3);
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    int n;
    printf("Введите количество ступенек (0-15): ");
    scanf("%d", &n);

    if (n < 0 || n > 15) 
    {
        printf("Ошибка: количество ступенек должно быть от 0 до 15\n");
        return 1;
    }

    int ways = count_ways(n);
    printf("Количество способов подняться: %d\n", ways);

    // тестовые
    //printf("N = 0: %d\n", count_ways(0));
    //printf("N = 1: %d\n", count_ways(1));
    //printf("N = 2: %d\n", count_ways(2));
    //printf("N = 3: %d\n", count_ways(3));
    //printf("N = 4: %d\n", count_ways(4));
    //printf("N = 5: %d\n", count_ways(5));

    return 0;
}
