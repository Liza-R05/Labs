#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

// прототипы
double** sort(double** A, int n, int m);
double** file_matrix(double** A, int n, int m, const char* filename);
double** input_matrix(double** A, int n, int m);
double** random_matrix(double** A, int n, int m);
void print_matrix(double** A, int n, int m);
double find_max_module(double** A, int n, int m, int* max_i, int* max_j);
int val_k(int k, int n, int m);
double** move_max(double** A, int n, int m, int k, int jmax, int imax);

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
    int work = 1;
    while (work)
    {
        int n, m, k;
        int c1 = 0, vc1 = 0;
        int c2 = 0, vc2 = 0;
        int choice; int imax, jmax;
        int valid_in = 0; char filename[100];
        double max_val;

        // ввод размеров матрицы
        printf("Введите количество строк n: ");
        scanf("%d", &n);
        printf("Введите количество столбцов m: ");
        scanf("%d", &m);

        // создаем матрицу как массив указателей
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

        while (!vc1)
        {
            printf("\nСпособ заполнения матрицы:\n");
            printf("1. Ввод с консоли\n");
            printf("2. Случайные числа\n");
            printf("3. Чтение из файла\n");
            printf("Выберите способ: ");
            scanf("%d", &c1);

            switch (c1)
            {
            case 1:

                input_matrix(A, n, m);
                vc1 = 1;
                break;

            case 2:

                random_matrix(A, n, m);
                vc1 = 1;
                break;

            case 3:

                printf("Введите имя файла: ");
                scanf("%s", filename);
                file_matrix(A, n, m, filename);
                vc1 = 1;
                break;

            default:

                printf("Неверный выбор! Пожалуйста, выберите 1, 2 или 3\n");
                break;

            }
        }
        while (!vc2)
        {
            printf("\nСпособ вывода результатов:\n");
            printf("1. Простой вывод (только массивы)\n");
            printf("2. Подробный вывод с комментариями\n");
            printf("Выберите способ: ");
            scanf("%d", &c2);

            // ввод К
            while (!valid_in)
            {
                printf("Введите k: ");
                scanf("%d", &k);

                if (val_k(k, n, m))
                {
                    valid_in = 1;
                }
                else
                {
                    printf("Повторите ввод\n");
                }
            }

            switch (c2)
            {
            case 1:

                printf("\nИсходная матрица:\n");
                print_matrix(A, n, m);

                printf("\nСортировка матрицы:\n");
                sort(A, n, m);
                print_matrix(A, n, m);

                // смена строк и столбцов
                max_val = find_max_module(A, n, m, &imax, &jmax);
                move_max(A, n, m, k, jmax, imax);

                // вывод результата
                printf("\nРезультат:\n");
                print_matrix(A, n, m);
                vc2 = 1;
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

                // смена строк и столбцов
                move_max(A, n, m, k, jmax, imax);

                // вывод результата
                printf("\n=== ПРЕОБРАЗОВАННЫЙ МАССИВ ===\n");
                print_matrix(A, n, m);
                printf("\nМаксимальный элемент теперь в A[%d][%d] = %.2f\n", k, k, A[k][k]);
                vc2 = 1;
                break;

            default:
                printf("Неверный выбор! Пожалуйста, выберите 1 или 2\n");
                break;
            }
        }
        // освобождаем память
        for (int i = 0; i < n; i++)
        {
            free(A[i]);
        }
        free(A);
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
        valid_in = 0;  // сбрасываем для следующей итерации
    }

    system("pause");
    return 0;
}

// реализация функций
double** sort(double** A, int n, int m)
{
    for (int col = 0; col < m; col++)
    {
        // Сортировка выбором для текущего столбца
        for (int i = 0; i < n - 1; i++)
        {
            int min_idx = i;

            // Находим минимальный элемент в столбце от i до n-1
            for (int j = i + 1; j < n; j++)
            {
                if (A[j][col] < A[min_idx][col])
                {
                    min_idx = j;
                }
            }

            // Меняем местами элементы столбца
            if (min_idx != i)
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
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Ошибка, не удалось открыть файл\n");
        return A;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
    return A;
}

double** random_matrix(double** A, int n, int m)
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
    return A;
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

double find_max_module(double** A, int n, int m, int* max_i, int* max_j)
{
    double max_sq = A[0][0] * A[0][0];
    *max_i = 0;
    *max_j = 0;

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
    return A[*max_i][*max_j]; // возвр значение элемента
}

int val_k(int k, int n, int m) // проверка К что она не выходит за пределы массива
{
    if (k < 0 || k >= n || k >= m)
    {
        printf("Ошибка, k должна быть в диапазоне\n");
        return 0;
    }
    return 1;
}

double** move_max(double** A, int n, int m, int k, int jmax, int imax) //перемещаем элемент
{
    if (imax != k)
    {
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
