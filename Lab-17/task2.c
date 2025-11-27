#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Функция формирования массива
int* full_array(int* ptrarr, int n)
{
    for (int i = 0; i < n; i++)
    {
        ptrarr[i] = rand() % 100; // числа от 0 до 99
    }
    return ptrarr;
}

// Функция вывода массива
int put_array(int* ptrarr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
    return 0;
}

// а) Пузырьковая сортировка
void sort_bubble(int* ptrarr, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ptrarr[j] > ptrarr[j + 1])
            {
                temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

// б) Шейкерная сортировка
void sort_kokteil(int* ptrarr, int n)
{
    int Left = 0;
    int Right = n - 1;
    int temp, j;

    while (Left <= Right)
    {
        // Слева направо
        for (j = Left; j < Right; j++)
        {
            if (ptrarr[j] > ptrarr[j + 1])
            {
                temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
        Right--;

        // Справа налево
        for (j = Right; j > Left; j--)
        {
            if (ptrarr[j] < ptrarr[j - 1])
            {
                temp = ptrarr[j];
                ptrarr[j] = ptrarr[j - 1];
                ptrarr[j - 1] = temp;
            }
        }
        Left++;
    }
}

// в) Сортировка простым выбором
void sort_select(int* ptrarr, int n)
{
    int i, j, imin, temp;
    for (i = 0; i < n - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < n; j++)
        {
            if (ptrarr[j] < ptrarr[imin])
            {
                imin = j;
            }
        }
        if (imin != i)
        {
            temp = ptrarr[i];
            ptrarr[i] = ptrarr[imin];
            ptrarr[imin] = temp;
        }
    }
}

// г) Сортировка вставками
void sort_insert(int* ptrarr, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = ptrarr[i];
        j = i;
        while (j > 0 && ptrarr[j - 1] > temp)
        {
            ptrarr[j] = ptrarr[j - 1];
            j--;
        }
        ptrarr[j] = temp;
    }
}

void main()
{
    setlocale(LC_ALL, "RUS");

    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    // Выделение памяти для массива
    int* ptrarr = (int*)malloc(size * sizeof(int));

    // Формирование массива
    full_array(ptrarr, size);

    printf("Исходный массив: ");
    put_array(ptrarr, size);

    // Замер времени для сортировки вставками
    clock_t t = clock();
    sort_insert(ptrarr, size);
    double time = (clock() - t) * 1. / CLOCKS_PER_SEC;

    printf("Отсортированный массив: ");
    put_array(ptrarr, size);
    printf("Время сортировки вставками: %.6f секунд\n", time);

    // Замер времени для других сортировок
    int* arr2 = (int*)malloc(size * sizeof(int));
    int* arr3 = (int*)malloc(size * sizeof(int));
    int* arr4 = (int*)malloc(size * sizeof(int));

    // Пузырьковая сортировка
    full_array(arr2, size);
    t = clock();
    sort_bubble(arr2, size);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Время пузырьковой сортировки: %.6f секунд\n", time);

    // Шейкерная сортировка
    full_array(arr3, size);
    t = clock();
    sort_kokteil(arr3, size);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Время шейкерной сортировки: %.6f секунд\n", time);

    // Сортировка выбором
    full_array(arr4, size);
    t = clock();
    sort_select(arr4, size);
    time = (clock() - t) * 1. / CLOCKS_PER_SEC;
    printf("Время сортировки выбором: %.6f секунд\n", time);

    // Освобождение памяти
    free(ptrarr);
    free(arr2);
    free(arr3);
    free(arr4);

    system("pause");
}
