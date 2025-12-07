#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE* in;
    double value;  // чтение значений функции
    double sum = 0.0;
    int count = 0;
    char line[200]; // не содержат числа

    // файл для чтения
    in = fopen("temp.txt", "rt");
    if (in == NULL)
    {
        printf("Ошибка\n");
        system("pause");
        return 1;
    }

    while (!feof(in))
    {
        // прочитать число
        if (fscanf(in, "%lf", &value) == 1)
        {
            sum += value;
            count++;
            printf("Найдено: %.2lf\n", value);
        }
        else
        {
            // не число, пропускаем
            fgetc(in);
        }
    }

    fclose(in);

    if (count == 0)
    {
        printf("Не найдено числовых данных\n");
    }
    else
    {
        double average = sum / count;
        printf("Среднее арифметическое: %.2lf\n", average);
    }

    printf("\n");
    system("pause");
    return 0;
}
