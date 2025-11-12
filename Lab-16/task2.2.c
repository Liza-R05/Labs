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
// вставка -999 перед максимальным элементом
double* insert_before_max(double* ptr_array, int* n) 
{
    if (*n == 0) return ptr_array;
    // индекс максимального элемента
    int max_index = 0;
    for (int i = 1; i < *n; i++) 
    {
        if (ptr_array[i] > ptr_array[max_index]) 
        {
            max_index = i;
        }
    }
    // увеличиваем на 1 элемент
    double* new_array = (double*)malloc((*n + 1) * sizeof(double));
    if (new_array == NULL) 
    {
        printf("error\n");
        return ptr_array;
    }
    // копируем элементы до максимального
    for (int i = 0; i < max_index; i++) 
    {
        new_array[i] = ptr_array[i];
    }
    new_array[max_index] = -999.0;
    // остальные элементы
    for (int i = max_index; i < *n; i++) 
    {
        new_array[i + 1] = ptr_array[i];
    }
    (*n)++;
    free(ptr_array);
    return new_array;
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
