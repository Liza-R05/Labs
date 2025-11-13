#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 7

// заполнение массива случайными числами от -10 до 10
void fill_array(int arr[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

// вывод массива на экран
void print_array(int arr[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

// транспонирование
void transf(int arr[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = i + 1; j < SIZE; j++) 
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

// подсчет эл. 2 столбца < -5
int lesM5(int arr[SIZE][SIZE]) 
{
    int count = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        if (arr[i][1] < -5) 
        {
            count++;
        }
    }
    return count;
}

// подсчет пар одинаковых соседних элементов в строках
int count_same_neighbors(int arr[SIZE][SIZE]) 
{
    int count = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE - 1; j++) 
        {
            if (arr[i][j] == arr[i][j + 1]) 
            {
                count++;
            }
        }
    }
    return count;
}

// поиск координат макс элемента
void find_max_coordinates(int arr[SIZE][SIZE]) 
{
    int max = arr[0][0];
    int max_i = 0, max_j = 0;
    for (int j = 0; j < SIZE; j++) 
    {
        for (int i = 0; i < SIZE; i++) 
        {
            if (arr[i][j] >= max) 
            {
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    printf("Максимальный элемент: %d, координаты: [%d][%d]\n", max, max_i, max_j);
}

void main() 
{
    setlocale(LC_ALL, "RUS");
    int a[SIZE][SIZE];
    int c = lesM5(a);
    int p = count_same_neighbors(a);
    fill_array(a);
    printf("Исходный массив:\n");
    print_array(a);
    transf(a);
    printf("\nТранспонированный массив:\n");
    print_array(a);
    printf("\nЭлементов < -5 во втором столбце: %d\n", c);
    printf("Пар одинаковых соседей в строках: %d\n", p);
    find_max_coordinates(a);
    system("pause");
}