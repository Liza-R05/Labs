#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 20
void main()
{
    setlocale(LC_ALL, "RUS");
    int n, m;
    int a[MAX][MAX];
    int c = 0;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    printf("Введите количество столбцов: ");
    scanf("%d", &m);
    // заполнение суммой индексов
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            a[i][j] = i + j;
        }
    }
    printf("\nМассив:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nПравый нижний угол: %d\n", a[n - 1][m - 1]);
    printf("\n");
    printf("Введите столбец: ");
    scanf("%d", &c);
    int max = a[0][c-1];
    for (int i = 1; i < n; i++) 
    {
        if (a[i][c-1] > max) 
        {
            max = a[i][c-1];
        }
    }
    printf("Максимум в столбце %d: %d\n", c, max);
    system("pause");
}