#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define CLASSES 11
#define GROUPS 4

void main() 
{
    setlocale(LC_ALL, "RUS");
    int school[CLASSES][GROUPS];
    int max_total = 0;
    int max_parallel = 0;
    // количество учеников
    for (int i = 0; i < CLASSES; i++) 
    {
        for (int j = 0; j < GROUPS; j++) 
        {
            school[i][j] = 21 + rand() % 12;
        }
    }
    printf("\nТаблица учеников:\n");
    printf("     | 1кл 2кл 3кл 4кл | всего\n");
    printf("-----|-----------------|-------\n");

    for (int i = 0; i < CLASSES; i++) 
    {
        int total = 0;
        printf("%2d-е |", i + 1);
        for (int j = 0; j < GROUPS; j++) 
        {
            printf("%4d", school[i][j]);
            total += school[i][j];
        }

        printf(" |%6d\n", total);

        if (total > max_total) 
        {
            max_total = total;
            max_parallel = i + 1;
        }
    }
    printf("\nСамая большая параллель: %d-е классы\n", max_parallel);
    printf("Количество учеников: %d\n", max_total);
    system("pause");
}