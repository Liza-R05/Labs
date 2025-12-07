#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    char output_filename[100];
    FILE* input_file;
    FILE* output_file;
    int ch;

    input_file = fopen("winter.txt", "rt");
    if (input_file == NULL)
    {
        printf("Ошибка\n");
        system("pause");
        return 1;
    }

    printf("Введите имя для нового файла: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "wt");
    if (output_file == NULL)
    {
        printf("Ошибка\n");
        fclose(input_file);
        system("pause");
        return 1;
    }

    while (1)
    {
        ch = fgetc(input_file);  // читаем один символ
        if (ch == -1)  // если достигли конца файла
        {
            break;  // выходим из цикла
        }

        if (ch != ' ')  // если символ не пробел
        {
            fputc(ch, output_file);  // записываем в новый файл
        }
    }

    fclose(input_file);
    fclose(output_file);

    system("pause");
    return 0;
}