#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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

// обработка элементов массива (возведение в квадрат - вариант 4)
double* calc_elements(double* ptr_array, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        ptr_array[i] = ptr_array[i] * ptr_array[i];
    }
    return ptr_array;
}

void main() 
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
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
    double* result_array = (double*)malloc(size * sizeof(double));
    if (result_array == NULL) 
    {
        printf("error\n");
        free(ptr_array);
        return -1;
    }
    for (int i = 0; i < size; i++) 
    {
        result_array[i] = ptr_array[i];
    }
    calc_elements(result_array, size);
    printf("\nИсходный массив:\n");
    put_elements(ptr_array, size);
    printf("\nПреобразованный массив:\n");
    put_elements(result_array, size);
    free(ptr_array);
    free(result_array);
    system("pause");
}
