#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// заполнение массива случайными числами от -1 до 1
double* full_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        ptr_array[i] = -1.0 + 2.0 * rand() / RAND_MAX;
    }
    return ptr_array;
}

// печать элементов массива
int put_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d] = %.2f\n", i, ptr_array[i]);
    }
    return n;
}

// вставка -999 перед максимальным элементом (по образцу из картинки)
double* insert_before_max(double* ptr_arr, int* size)
{
    if (*size == 0) return ptr_arr;
    // находим индекс максимального элемента
    int k = 0;
    for (int i = 1; i < *size; i++)
    {
        if (ptr_arr[i] > ptr_arr[k])
        {
            k = i;
        }
    }
    // увеличиваем размер массива
    int size_n = (*size) + 1;
    double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
    if (ptr_arr_n == NULL)
    {
        printf("error\n");
        return ptr_arr;
    }
    ptr_arr = ptr_arr_n;
    // сдвигаем элементы для вставки
    for (int i = size_n - 1; i > k; i--)
    {
        ptr_arr[i] = ptr_arr[i - 1];
    }
    // вставляем -999
    double num = -999.0;
    ptr_arr[k] = num;
    *size = size_n;

    return ptr_arr;
}

void main()
{
    setlocale(LC_ALL, "RUS");
    double* ptr_array;
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL)
    {
        printf("error\n");
        return -1;
    }
    full_elements(ptr_array, size);
    printf("\nИсходный массив:\n");
    put_elements(ptr_array, size);
    ptr_array = insert_before_max(ptr_array, &size);
    printf("\nМассив после вставки -999 перед максимальным элементом:\n");
    put_elements(ptr_array, size);
    free(ptr_array);
    system("pause");
}

