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
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d] = %.2f\n", i, ptr_array[i]);
    }
}
// 1 вычисления суммы элементов от begin до end включительно
double sum_elements(double* ptr_array, int begin, int end) 
{
    double sum = 0.0;
    for (int i = begin; i <= end; i++) 
    {
        sum += ptr_array[i];
    }
    return sum;
}
// 2 поиск элемента равного a
int find_element(double* ptr_array, int n, double element) 
{
    for (int i = 0; i < n; i++) 
    {
        if (ptr_array[i] == element) 
        {
            return i;  // индекс найденного элемента
        }
    }
    return -1;  // не найден
}
void main()
{
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size;
    int begin, end;
    double a;
    printf("Введите размер массива > ");
    scanf("%d", &size);
    full_elements(array, size);
    put_elements(array, size);
    printf("\n");
    printf("Введите начальный индекс> ");
    scanf("%d", &begin);
    printf("Введите конечный индекс > ");
    scanf("%d", &end);
    double sum = sum_elements(array, begin, end);
    printf("Сумма элементов от [%d] до [%d] = %.2f\n\n", begin, end, sum);
    printf("Введите элемент для поиска > ");
    scanf(" %lf", &a);
    int b = find_element(array, size, a);
    if (b != -1) 
    {
        printf("Элемент %.2f найден по индексу %d\n", a, b);
    }
    else 
    {
        printf("Элемент %.2f не найден\n", a);
    }
    system("pause");
}
