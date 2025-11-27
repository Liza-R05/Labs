#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

void input_matrix(double** A, int n, int m)
{
    // ввод элементов матрицы с консоли
    printf("Введите элементы матрицы %dx%d:\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

void random_matrix(double** A, int n, int m)
{
    // заполнение случайными числами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = (double)(rand() % 2001 - 1000) / 100.0; // числа от -10.00 до 10.00
        }
    }
    printf("Массив заполнен случайными числами от -10.00 до 10.00\n");
}

void print_matrix(double** A, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%8.2f", A[i][j]);
        }
        printf("\n");
    }
}

double* find_max_module(double** A, int n, int m)
{
    double* max_ptr = &A[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double c_s = A[i][j] * A[i][j];
            double max_s = (*max_ptr) * (*max_ptr);
            if (c_s > max_s)
            {
                max_ptr = &A[i][j];
            }
        }
    }
    return max_ptr;
}

void swap_r(double** A, int row1, int row2)
{
    double* temp = A[row1];
    A[row1] = A[row2];
    A[row2] = temp;
}

void swap_c(double** A, int n, int col1, int col2)
{
    for (int i = 0; i < n; i++)
    {
        double temp = A[i][col1];
        A[i][col1] = A[i][col2];
        A[i][col2] = temp;
    }
}

int input_k(int n, int m)
{
    int k;
    int valid_k = 0;
    while (!valid_k)
    {
        printf("Введите k: ");
        scanf("%d", &k);

        if (k < 0 || k >= n || k >= m)
        {
            printf("Ошибка! k должно быть от 0 до %d\n", (n < m) ? n - 1 : m - 1);
        }
        else
        {
            valid_k = 1;
        }
    }
    return k;
}

void free_matrix(double** A, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
}

double** allocate_matrix(int n, int m)
{
    double** A = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        A[i] = (double*)malloc(m * sizeof(double));
    }
    return A;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    printf("**********************************************************************\n");
    printf("*                                                                    *\n");
    printf("*  Курсовой проект по дисциплине: \"Основы программирования и         *\n");
    printf("*                               алгоритмования\"                      *\n");
    printf("*  Тема: \"Реализация динамического многомерного массива\"             *\n");
    printf("*  Выполнила: Рассоха Е.Д., группа 6ИД-252                           *\n");
    printf("*                                                                    *\n");
    printf("**********************************************************************\n");
    printf("\n");

    printf("Программа создает динамическую матрицу и выполняет перестановку строк и столбцов.\n");
    printf("\tНаходит элемент с максимальным модулем и перемещает его на позицию [k][k] путем перестановки строки k со\n");
    printf("\tстрокой максимального элемента и столбца k со столбцом максимального элемента.\n");
    printf("\n");

    printf("Программа предоставляет различные режимы работы:\n");
    printf("\tЗаполнение матрицы вручную или случайными числами\n");
    printf("\tПростой или подробный вывод результатов\n");
    printf("\tВозможность многократного выполнения с разными данными\n");
    printf("\n");
    printf("\n");
    printf("\n");
    int work = 1;
    while (work)
    {
        int n, m, k;
        int c1 = 0, vc1 = 0;
        int c2 = 0, vc2 = 0;
        int choice;

        // ввод размеров матрицы
        printf("Введите количество строк n: ");
        scanf("%d", &n);
        printf("Введите количество столбцов m: ");
        scanf("%d", &m);

        // создаем матрицу как массив указателей
        double** A = allocate_matrix(n, m);

        while (!vc1)
        {
            printf("\nСпособ заполнения матрицы:\n");
            printf("1. Ввод с консоли\n");
            printf("2. Случайные числа\n");
            printf("Выберите способ: ");
            scanf("%d", &c1);

            switch (c1)
            {
            case 1:
            {
                input_matrix(A, n, m);
                vc1 = 1;
                break;
            }
            case 2:
            {
                random_matrix(A, n, m);
                vc1 = 1;
                break;
            }
            default:
            {
                printf("Неверный выбор! Пожалуйста, выберите 1 или 2\n");
                break;
            }
            }
        }
        while (!vc2)
        {
            printf("\nСпособ вывода результатов:\n");
            printf("1. Простой вывод (только массивы)\n");
            printf("2. Подробный вывод с комментариями\n");
            printf("Выберите способ: ");
            scanf("%d", &c2);
            switch (c2)
            {
            case 1:
            {
                printf("\nИсходная матрица:\n");
                print_matrix(A, n, m);
                double* max_ptr = find_max_module(A, n, m);
                k = input_k(n, m);
                int imax = (max_ptr - &A[0][0]) / m;
                int jmax = (max_ptr - &A[0][0]) % m;

                // меняем строки местами  
                if (imax != k)
                {
                    swap_r(A, imax, k);
                }
                else
                {
                    printf("Максимальный элемент уже в строке %d, перестановка не нужна\n", k);
                }

                // меняем столбцы местами  
                if (jmax != k)
                {
                    swap_c(A, n, jmax, k);
                }
                else
                {
                    printf("Максимальный элемент уже в столбце %d, перестановка не нужна\n", k);
                }

                // вывод результата
                printf("\nРезультат:\n");
                print_matrix(A, n, m);
                vc2 = 1;
                break;
            }
            case 2:
            {
                printf("\n=== ИСХОДНЫЙ МАССИВ ===\n");
                printf("Размер: %d строк х %d столбцов\n", n, m);
                printf("\nИсходная матрица:\n");
                print_matrix(A, n, m);
                printf("\nВЫПОЛНЕННЫЕ ДЕЙСТВИЯ:\n");
                double* max_ptr = find_max_module(A, n, m);
                int imax = (max_ptr - &A[0][0]) / m;
                int jmax = (max_ptr - &A[0][0]) % m;

                printf("\nМаксимальный элемент: %.2f в позиции [%d][%d]\n", *max_ptr, imax, jmax);
                k = input_k(n, m);

                // меняем строки местами
                if (imax != k)
                {
                    swap_r(A, imax, k);
                    printf("Поменяли строки %d и %d\n", imax, k);
                }
                else
                {
                    printf("Максимальный элемент уже в строке %d, перестановка не нужна\n", k);
                }

                // меняем столбцы местами  
                if (jmax != k)
                {
                    swap_c(A, n, jmax, k);
                    printf("Поменяли столбцы %d и %d\n", jmax, k);
                }
                else
                {
                    printf("Максимальный элемент уже в столбце %d, перестановка не нужна\n", k);
                }

                // вывод результата
                printf("\n=== ПРЕОБРАЗОВАННЫЙ МАССИВ ===\n");
                print_matrix(A, n, m);
                printf("\nМаксимальный элемент теперь в A[%d][%d] = %.2f\n", k, k, A[k][k]);
                vc2 = 1;
                break;
            }
            default:
            {
                printf("Неверный выбор! Пожалуйста, выберите 1 или 2\n");
                break;
            }
            }
        }
        // освобождаем память
        free_matrix(A, n);
        // запрос на продолжение работы
        printf("\n=================================\n");
        printf("Хотите продолжить работу?\n");
        printf("1. Продолжить (создать новую матрицу)\n");
        printf("2. Завершить работу\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        if (choice == 2)
        {
            work = 0;
            printf("Работа программы завершена\n");
        }
        else
        {
            printf("\nПродолжаем работу...\n");
            printf("=================================\n\n");
        }
        vc1 = 0;
        vc2 = 0;
        c1 = 0;
        c2 = 0;
    }

    system("pause");
    return 0;
}
