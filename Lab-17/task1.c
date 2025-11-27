#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

// Функция для вывода массива
void print_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    setlocale(LC_ALL, "RUS");
    int n = 10;
    int arr1[10], arr2[10], arr3[10], arr4[10];
    // Заполнение массивов случайными числами от 0 до 10
    for (int i = 0; i < n; i++) 
    {
        int num = rand() % 11; // числа от 0 до 10
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
        arr4[i] = num;
    }
    printf("Исходный массив: ");
    print_array(arr1, n);
    printf("\n");

    // Проверка пузырьковой сортировки
    sort_bubble(arr1, n);
    printf("Пузырьковая: ");
    print_array(arr1, n);

    // Проверка шейкерной сортировки
    sort_kokteil(arr2, n);
    printf("Шейкерная:   ");
    print_array(arr2, n);

    // Проверка сортировки выбором
    sort_select(arr3, n);
    printf("Выбором:     ");
    print_array(arr3, n);

    // Проверка сортировки вставками
    sort_insert(arr4, n);
    printf("Вставками:   ");
    print_array(arr4, n);

    system("pause");
}