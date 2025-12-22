#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

double** file_matrix(double** A, int n, int m, const char* filename); // функция ввода матрицы с клавиатуры
double** input_matrix(double** A, int n, int m); // функция заполнения матрицы случайными числами
double** random_matrix(double** A, int n, int m); // функция чтения матрицы из файла
double** sort(double** A, int n, int m); // функция сортировки столбцов матрицы
void print_matrix(double** A, int n, int m); // функция вывода матрицы
double find_max_module(double** A, int n, int m, int* max_i, int* max_j); // функция поиска максимального по модулю элемента
int validate_k(int k, int n, int m); // функция проверки корректности k
double** move_max(double** A, int n, int m, int k, int jmax, int imax); // функция перемещения максимального элемента

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    printf("**********************************************************************\n");
    printf("*                                                                    *\n");
    printf("*  Курсовой проект по дисциплине: \"Основы программирования и         *\n");
    printf("*                               алгоритмования\"                      *\n");
    printf("*  Тема: \"Реализация динамического многомерного массива\"             *\n");
    printf("*  Выполнила: Рассоха Е.Д., группа 6ИД-252                           *\n");
    printf("*                                                                    *\n");
    printf("**********************************************************************\n");
    printf("\n");

    printf("Программа создает динамическую матрицу и выполняет сортировку выбором, перестановку строк и столбцов.\n");
    printf("\tСортирует исходную матрицу и находит элемент с максимальным модулем, перемещает его на позицию [k][k] путем\n");
    printf("\tперестановки строки k со строкой максимального элемента и столбца k со столбцом максимального элемента.\n");
    printf("\n");

    printf("Программа предоставляет различные режимы работы:\n");
    printf("\tЗаполнение матрицы вручную, случайными числами или с помощью считывания файла\n");
    printf("\tПростой или подробный вывод результатов\n");
    printf("\tВозможность многократного выполнения с разными данными\n");
    printf("\n");
    printf("\n");
    printf("\n");
    int work = 1; /* флаг продолжения работы программы */
    while (work)
    {
        int n, m, k; // n - строки, m - столбцы, k - целевая позиция
        int choice_input = 0, input_done = 0; // выбор и флаг завершения заполнения матрицы
        int choice_output = 0, output_done = 0; // выбор и флаг завершения вывода результатов
        int imax, jmax; // координаты максимального элемента
        int valid_k = 0; // флаг корректности значения k
        char filename[100]; // имя файла для чтения
        double max_val; // значение максимального элемента

        printf("Введите количество строк n: ");
        scanf("%d", &n);
        printf("Введите количество столбцов m: ");
        scanf("%d", &m);

        /* выделение памяти под массив */
        double** A = (double**)malloc(n * sizeof(double*));
        if (A == NULL)
        {
            printf("Ошибка выделения памяти\n");
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            A[i] = (double*)malloc(m * sizeof(double));
        }

        while (!input_done) /* выбор способа заполнения массива */
        {
            printf("\nСпособ заполнения матрицы:\n");
            printf("1. Ввод с консоли\n");
            printf("2. Случайные числа\n");
            printf("3. Чтение из файла\n");
            printf("Выберите способ: ");
            scanf("%d", &choice_input);

            switch (choice_input) /* инициализация по выбору пользователя */
            {
            case 1:

                input_matrix(A, n, m);
                input_done = 1;
                break;

            case 2:

                random_matrix(A, n, m);
                input_done = 1;
                break;

            case 3:

                printf("Введите имя файла: ");
                scanf("%s", filename);
                file_matrix(A, n, m, filename);
                input_done = 1;
                break;

            default:

                printf("Неверный выбор! Пожалуйста, выберите 1, 2 или 3\n");
                break;

            }
        }
        while (!output_done) /* выбор способа вывода массива */
        {
            printf("\nСпособ вывода результатов:\n");
            printf("1. Простой вывод (только массивы)\n");
            printf("2. Подробный вывод с комментариями\n");
            printf("Выберите способ: ");
            scanf("%d", &choice_output); 

            while (!valid_k) /* ввод и проверка значения k */
            {
                printf("Введите k: ");
                scanf("%d", &k);

                if (validate_k(k, n, m))
                {
                    valid_k = 1;
                }
                else
                {
                    printf("Повторите ввод\n");
                }
            }

            switch (choice_output) /*вывод результатов по выбору пользователя*/
            {
            case 1:

                printf("\nИсходная матрица:\n");
                print_matrix(A, n, m);

                printf("\nСортировка матрицы:\n");
                sort(A, n, m);
                print_matrix(A, n, m);

                max_val = find_max_module(A, n, m, &imax, &jmax);
                move_max(A, n, m, k, jmax, imax);

                printf("\nРезультат:\n");
                print_matrix(A, n, m);
                output_done = 1;
                break;

            case 2:

                printf("\n=== ИСХОДНЫЙ МАССИВ ===\n");
                printf("Размер: %d строк х %d столбцов\n", n, m);
                printf("\nИсходная матрица:\n");
                print_matrix(A, n, m);
                printf("\nВЫПОЛНЕННЫЕ ДЕЙСТВИЯ:\n");

                printf("\nСортировка матрицы:\n");
                sort(A, n, m);
                print_matrix(A, n, m);

                max_val = find_max_module(A, n, m, &imax, &jmax);
                printf("\nМаксимальный элемент: %.2f в позиции [%d][%d]\n", max_val, imax, jmax);
                printf("k = %d\n", k);

                move_max(A, n, m, k, jmax, imax);

                printf("\n=== ПРЕОБРАЗОВАННЫЙ МАССИВ ===\n");
                print_matrix(A, n, m);
                printf("\nМаксимальный элемент теперь в A[%d][%d] = %.2f\n", k, k, A[k][k]);
                output_done = 1;
                break;

            default:
                printf("Неверный выбор! Пожалуйста, выберите 1 или 2\n");
                break;
            }
        }
        
        for (int i = 0; i < n; i++) /* освобождение памяти */
        {
            free(A[i]);
        }
        free(A);

        printf("\n=================================\n");
        printf("Хотите продолжить работу?\n");
        printf("1. Продолжить (создать новую матрицу)\n");
        printf("2. Завершить работу\n");
        printf("Выберите действие: ");
        scanf("%d", &choice_input);

        if (choice_input == 2)
        {
            work = 0;
            printf("Работа программы завершена\n");
        }
        else
        {
            printf("\nПродолжаем работу...\n");
            printf("=================================\n\n");
        }
        input_done = 0;
        output_done = 0;
        valid_k = 0;  // сбрасываем для следующей итерации
    }

    system("pause");
    return 0;
}

double** sort(double** A, int n, int m)    // функция предназначена для того, чтобы 
{                                          // отсортировать каждый столбец матрицы
    for (int col = 0; col < m; col++)      // по возрастанию методом выбора
    {
        for (int i = 0; i < n - 1; i++)
        {
            int min_idx = i;

            for (int j = i + 1; j < n; j++) // находим минимальный элемент в столбце
            {
                if (A[j][col] < A[min_idx][col])
                {
                    min_idx = j;
                }
            }

            if (min_idx != i) // меняем местами элементы столбца
            {
                double temp = A[i][col];
                A[i][col] = A[min_idx][col];
                A[min_idx][col] = temp;
            }
        }
    }
    return A;
}

double** file_matrix(double** A, int n, int m, const char* filename)
{
    FILE* file = fopen(filename, "r");              // функция предназначена для того, чтобы
    if (file == NULL)                               // заполнить матрицу числами из файла
    {
        printf("Ошибка, не удалось открыть файл\n");
        return A;
    }

    for (int i = 0; i < n; i++) // читаем построчно: сначала первую строку матрицы
    {
        for (int j = 0; j < m; j++) // в каждой строке читаем все элементы столбцов
        {
            if (fscanf(file, "%lf", &A[i][j]) != 1)
            {
                printf("Ошибка, недостаточно данных в файле\n");
                fclose(file);
                return A;
            }
        }
    }

    fclose(file);
    return A;
}

double** input_matrix(double** A, int n, int m)
{
    printf("Введите элементы матрицы %dx%d:\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    return A;
}

double** random_matrix(double** A, int n, int m)
{
    for (int i = 0; i < n; i++)                   // функция предназначена для того, чтобы
    {                                             // массив инициализировался случайными
        for (int j = 0; j < m; j++)               // сгенерированными числами от -10.00 до 10.00
        {
            A[i][j] = (double)(rand() % 2001 - 1000) / 100.0;
        }
    }
    printf("Массив заполнен случайными числами от -10.00 до 10.00\n");
    return A;
}

void print_matrix(double** A, int n, int m)   // функция предназначена для того, чтобы
{                                             // массив выводился на экран 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%8.2f", A[i][j]);
        }
        printf("\n");
    }
}

double find_max_module(double** A, int n, int m, int* max_i, int* max_j)
{
    double max_sq = A[0][0] * A[0][0];   // функция предназначена для того, чтобы
    *max_i = 0;                          // найти элемент с максимальным модулем
    *max_j = 0;                          // и вернуть его координаты

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double c_sq = A[i][j] * A[i][j];
            if (c_sq > max_sq)
            {
                max_sq = c_sq;
                *max_i = i;
                *max_j = j;
            }
        }
    }
    return A[*max_i][*max_j]; // возвращаем значение максимального элемента
}

int validate_k(int k, int n, int m)       // функция предназначена для того, чтобы
{                                         // проверить корректность значения k
    if (k < 0 || k >= n || k >= m)        // (k должно быть в пределах матрицы)
    {
        printf("Ошибка, k должна быть в диапазоне\n");
        return 0;
    }
    return 1;
}

double** move_max(double** A, int n, int m, int k, int jmax, int imax) 
{                          // функция предназначена для того, чтобы
    if (imax != k)         // переместить максимальный элемент на позицию [k][k]
    {                      // путем перестановки строк и столбцов
        double* temp = A[imax];
        A[imax] = A[k];
        A[k] = temp;
    }
   
    if (jmax != k)
    {
        for (int i = 0; i < n; i++)
        {
            double temp = A[i][jmax];
            A[i][jmax] = A[i][k];
            A[i][k] = temp;
        }
    }
  
    return A;
}
