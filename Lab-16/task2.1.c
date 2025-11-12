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
// удаление двух максимальных элементов
double* remove_two_max(double* ptr_array, int* n) 
{
    if (*n < 2) return ptr_array;
    // находим индексы двух максимальных элементов
    int max1_index = 0, max2_index = 1;
    if (ptr_array[1] > ptr_array[0]) 
    {
        max1_index = 1;
        max2_index = 0;
    }
    for (int i = 2; i < *n; i++) 
    {
        if (ptr_array[i] > ptr_array[max1_index]) 
        {
            max2_index = max1_index;
            max1_index = i;
        }
        else
        {
            max2_index = i;
        }
    }
    // удаляем элементы
    if (max1_index < max2_index) 
    {
        int temp = max1_index;
        max1_index = max2_index;
        max2_index = temp;
    }
    // с большим индексом
    for (int i = max1_index; i < *n - 1; i++) 
    {
        ptr_array[i] = ptr_array[i + 1];
    }
    (*n)--;
    // с меньшим индексом
    for (int i = max2_index; i < *n - 1; i++) 
    {
        ptr_array[i] = ptr_array[i + 1];
    }
    (*n)--;
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
    printf("\nИсходный массив:\n");
    put_elements(ptr_array, size);
    remove_two_max(ptr_array, &size);
    printf("\nМассив после удаления двух максимальных элементов:\n");
    put_elements(ptr_array, size);
    free(ptr_array);
    system("pause");
}