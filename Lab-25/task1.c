#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "RUS");
    int m = 1 + rand() % 10;
    int k;
    printf("”гадайте число (1-10): ");
    scanf("%d", &k);
    if (k == m) 
    {
        printf("”гадано число %d!\n", m);
    }
    else 
    {
        printf("„исло %d не было угадано\n", m);
    }
    system("pause");
}