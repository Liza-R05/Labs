#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// целое число от 1 до mmax
int rand10(int mmax)
{
    return 1 + rand() % mmax;
}

// вещественное число в заданном диапазоне
double rand_double(double dmin, double dmax)
{
    double scale = rand() / (double)RAND_MAX;
    return dmin + scale * (dmax - dmin);
}

// массив из n целых чисел от 1 до mmax
int* rand_array_int(int n, int mmax)
{
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand10(mmax);
    }
    return arr;
}

// массив из n вещественных чисел в диапазоне от -dm до +dm
double* rand_array_double(int n, double dm)
{
    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand_double(-dm, dm);
    }
    return arr;
}

void main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // рандомизаци€

    // сравнение последовательностей
    printf("ѕервые 5 чисел: ");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", rand10(10));
    }
    printf("\n—ледующие 5 чисел: ");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", rand10(10));
    }
    printf("\n\n");

    // 2
    printf("÷елые числа от 1 до 10:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", rand10(10));
    }
    printf("\n\n");

    // 3
    printf("¬ещественные числа от 0.0 до 1.0:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", rand_double(0.0, 1.0));
    }
    printf("\n\n");

    // 4
    printf("ћассив из 8 целых чисел от 1 до 100:\n");
    int* int_arr = rand_array_int(8, 100);
    for (int i = 0; i < 8; i++) 
    {
        printf("%d ", int_arr[i]);
    }
    printf("\n\n");

    // 5
    printf("ћассив из 6 вещественных чисел от -5.0 до +5.0:\n");
    double* double_arr = rand_array_double(6, 5.0);
    for (int i = 0; i < 6; i++) 
    {
        printf("%.2f ", double_arr[i]);
    }
    printf("\n");
    system("pause");
}