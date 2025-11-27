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
        ptrarr[i] = rand() % 1000; // числа от 0 до 999
    }
    return ptrarr;
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

    int sizes[] = { 100, 1000, 10000 };
    int num_sizes = 3;

    printf("Сравнение времени сортировки:\n\n");
    printf("Размер массива | Пузырьковая | Шейкерная   | Выбором     | Вставками\n");
    printf("--------------------------------------------------------------------\n");

    for (int s = 0; s < num_sizes; s++)
    {
        int size = sizes[s];
        printf("%14d |", size);

        // Тестируем пузырьковую сортировку
        int* arr1 = (int*)malloc(size * sizeof(int));
        full_array(arr1, size);
        clock_t t = clock();
        sort_bubble(arr1, size);
        double time_bubble = (clock() - t) * 1000. / CLOCKS_PER_SEC; //в миллисекундах
        printf("%12.3f |", time_bubble);
        free(arr1);

        // Тестируем шейкерную сортировку
        int* arr2 = (int*)malloc(size * sizeof(int));
        full_array(arr2, size);
        t = clock();
        sort_kokteil(arr2, size);
        double time_kokteil = (clock() - t) * 1000. / CLOCKS_PER_SEC;
        printf("%11.3f |", time_kokteil);
        free(arr2);

        // Тестируем сортировку выбором
        int* arr3 = (int*)malloc(size * sizeof(int));
        full_array(arr3, size);
        t = clock();
        sort_select(arr3, size);
        double time_select = (clock() - t) * 1000. / CLOCKS_PER_SEC;
        printf("%11.3f |", time_select);
        free(arr3);

        // Тестируем сортировку вставками
        int* arr4 = (int*)malloc(size * sizeof(int));
        full_array(arr4, size);
        t = clock();
        sort_insert(arr4, size);
        double time_insert = (clock() - t) * 1000. / CLOCKS_PER_SEC;
        printf("%11.3f\n", time_insert);
        free(arr4);
    }
    system("pause");
}