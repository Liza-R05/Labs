#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define N 100
double* full_elements(double* ptr_array, int n) // x^3 + 2x
{
    for (int i = 0; i < n; i++) 
    {
        double x = i * 0.1;
        ptr_array[i] = x * x * x + 2 * x;
    }
}
int put_elements(double* ptr_array, int n) 
{
    printf("Ёлементы массива:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("[%d] = %.2f\n", i, ptr_array[i]);
    }
}
double* calc_elements(double* ptr_array, int n) // возведение в квадрат
{
    for (int i = 0; i < n; i++) 
    {
        ptr_array[i] = ptr_array[i] * ptr_array[i];
    }
}

void main()
{
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size;
    printf("¬ведите размер массива > \n");
    scanf("%d", &size);
    full_elements(array, size);
    put_elements(array, size);
    printf("\n");
    calc_elements(array, size);
    printf("\n");
    put_elements(array, size);
    system("pause");
}