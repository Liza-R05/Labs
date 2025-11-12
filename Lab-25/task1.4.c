#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "RUS");
    int m = 1 + rand() % 3;
    int k;
    printf("1 - Камень\n");
    printf("2 - Ножницы\n");
    printf("3 - Бумага\n");
    printf("Ваш выбор: ");
    scanf("%d", &k);

    switch (k)
    {
    case 1:
        switch (m)
        {
        case 1:
            printf("Компьютер выбрал: Камень\n");
            printf("Ничья\n");
            break;
        case 2: 
            printf("Компьютер выбрал: Ножницы\n");
            printf("Победа\n");
            break;
        case 3: 
            printf("Компьютер выбрал: Бумага\n");
            printf("Проигрыш\n");
            break;
        }
        break;
    case 2:
        switch (m)
        {
        case 1:
            printf("Компьютер выбрал: Камень\n");
            printf("Проигрыш\n");
            break;
        case 2: 
            printf("Компьютер выбрал: Ножницы\n");
            printf("Ничья\n");
            break;
        case 3: 
            printf("Компьютер выбрал: Бумага\n");
            printf("Победа\n");
            break;
        }
        break;
    case 3:
        switch (m)
        {
        case 1: 
            printf("Компьютер выбрал: Камень\n");
            printf("Победа\n");
            break;
        case 2: 
            printf("Компьютер выбрал: Ножницы\n");
            printf("Проигрыш\n");
            break;
        case 3: 
            printf("Компьютер выбрал: Бумага\n");
            printf("Ничья\n");
            break;
        }
        break;
    }
    system("pause");
}