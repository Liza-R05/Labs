#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define N 100
double* full_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        double x = i * 0.1;
        ptr_array[i] = x * x * x + 2 * x;
    }
    return ptr_array;
}
int put_elements(double* ptr_array, int n)
{
    printf("Ёлементы массива:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d] = %.2f\n", i, ptr_array[i]);
    }
}
// ‘ункци€ определени€ максимального значени€ в интервале [K, M]
double find_max_in_interval(double* ptr_array, int n, int K, int M) 
{
    double max = ptr_array[K];
    for (int i = K + 1; i <= M; i++) 
    {
        if (ptr_array[i] > max) 
        {
            max = ptr_array[i];
        }
    }
    return max;
}
void main()
{
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size;
    int K, M;
    printf("¬ведите размер массива > ");
    scanf("%d", &size);
    full_elements(array, size);
    put_elements(array, size);
    printf("¬ведите начало интервала K > ");
    scanf("%d", &K);
    printf("¬ведите конец интервала M > ");
    scanf("%d", &M);
    double a = find_max_in_interval(array, size, K, M);
    printf("ћаксимальное значение в интервале > %.2f\n", a);
    system("pause");
}