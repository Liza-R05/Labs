#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int min, max;
    int N, R;
    printf("Введите минимальное значение: ");
    scanf("%d", &min);
    printf("Введите максимальное значение: ");
    scanf("%d", &max);
    printf("Введите количество чисел: ");
    scanf("%d", &N);
    printf("Введите длину гистограммы: ");
    scanf("%d", &R);
    int K = max - min + 1;
    int counter[100] = { 0 };
    // генерация случайных чисел в заданном интервале
    int array[1000];
    for (int i = 0; i < N; i++)
    {
        array[i] = min + rand() % K;
    }
    // подсчет частоты
    for (int i = 0; i < N; i++)
    {
        int number = array[i];
        counter[number - min]++; // сдвиг на min
    }
    // поиск максимального значения
    int max_count = 0;
    for (int i = 0; i < K; i++)
    {
        if (counter[i] > max_count)
        {
            max_count = counter[i];
        }
    }
    // вывод гистограммы
    printf("\nГистограмма для чисел от %d до %d:\n", min, max);
    for (int i = 0; i < K; i++)
    {
        printf("%2d: ", i + min); // выводим число из интервала
        int s = counter[i] * R / max_count;
        for (int j = 0; j < s; j++)
        {
            printf("*");
        }
        printf(" (%d)\n", counter[i]);
    }
    printf("\n");
    system("pause");
}
