#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    char filename[100];
    char new_filename[150];
    FILE* input_file;
    FILE* output_file;
    double number;
    int count = 0;

    printf("Введите имя файла с числами: ");
    scanf("%s", filename);

    input_file = fopen(filename, "rt");
    if (input_file == NULL)
    {
        printf("Ошибка\n");
        system("pause");
        return 1;
    }

    // новое имя файла
    // найдем точку для вставки "sq"
    char* dot = strrchr(filename, '.');
    if (dot != NULL)
    {
        sprintf(new_filename, "%.*ssq%s", (int)(dot - filename), filename, dot);
    }
    else
    {
        sprintf(new_filename, "%ssq", filename);
    }

    // новый файл для записи
    output_file = fopen(new_filename, "wt");
    if (output_file == NULL)
    {
        printf("Ошибка\n", new_filename);
        fclose(input_file);
        system("pause");
        return 1;
    }

    while (fscanf(input_file, "%lf", &number) == 1)
    {
        printf("%.2lf\n", number);
        number = number * number;
        printf("Квадрат: %.2lf\n", number);
        // результат в новый файл
        fprintf(output_file, "%.6lf\n", number);

        count++;
    }

    fclose(input_file);
    fclose(output_file);

    printf("\n");
    system("pause");
    return 0;
}
