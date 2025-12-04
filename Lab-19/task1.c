#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    char fname[20] = "number.txt";
    FILE* out; // указатель на файл
    float number;

    puts("Создание файла number.txt");

    printf("Введите цифру для записи в файл: ");
    scanf("%f", &number);

    // oткрытие файла для записи (write text)
    if ((out = fopen(fname, "at")) == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        system("pause");
        return 0;
    }

    fprintf(out, "%.2f\n", number);
    fclose(out); // закрыть файл
    system("pause");
    return 0;
}