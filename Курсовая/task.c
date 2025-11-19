#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    int work = 1;
    while (work)
    {
        int n, m, k;
        int c1 = 0, vc1 = 0;
        int c2 = 0, vc2 = 0;
        // ввод размеров матрицы
        printf("Введите количество строк n: ");
        scanf("%d", &n);
        printf("Введите количество столбцов m: ");
        scanf("%d", &m);

        // создаем матрицу как массив указателей
        int** A = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++)
        {
            A[i] = (int*)malloc(m * sizeof(int));
        }

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
                // ввод элементов матрицы с консоли
                printf("Введите элементы матрицы %dx%d:\n", n, m);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        printf("A[%d][%d] = ", i, j);
                        scanf("%d", &A[i][j]);
                    }
                }
                vc1 = 1;
                break;
            }
            case 2:
            {
                // заполнение случайными числами
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        A[i][j] = rand() % 21; // числа от 0 до 20
                    }
                }
                printf("Массив заполнен случайными числами от 0 до 20\n");
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
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        printf("%4d", A[i][j]);
                    }
                    printf("\n");
                }
                int imax = 0, jmax = 0;
                int max_value = abs(A[0][0]);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (abs(A[i][j]) > max_value)
                        {
                            max_value = abs(A[i][j]);
                            imax = i;
                            jmax = j;
                        }
                        // else: элемент не больше, продолжаем поиск
                    }
                }
                printf("Введите k: ");
                scanf("%d", &k);

                if (k < 0 || k >= n || k >= m)
                {
                    printf("Ошибка! k должно быть от 0 до %d\n", (n < m) ? n - 1 : m - 1);
                    // освобождаем память
                    for (int i = 0; i < n; i++)
                    {
                        free(A[i]);
                    }
                    free(A);
                    return 1;
                }
                // else: k корректно, продолжаем выполнение

                // меняем строки местами
                if (imax != k)
                {
                    int* temp = A[imax];
                    A[imax] = A[k];
                    A[k] = temp;
                }
                else
                {
                    printf("Максимальный элемент уже в строке %d, перестановка не нужна\n", k);
                }

                // меняем столбцы местами  
                if (jmax != k)
                {
                    for (int i = 0; i < n; i++)
                    {
                        int temp = A[i][jmax];
                        A[i][jmax] = A[i][k];
                        A[i][k] = temp;
                    }
                }
                else
                {
                    printf("Максимальный элемент уже в столбце %d, перестановка не нужна\n", k);
                }

                // вывод результата
                printf("\nРезультат:\n");
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        printf("%4d", A[i][j]);
                    }
                    printf("\n");
                }
                vc2 = 1;
                break;
            }
            case 2:
            {
                printf("\n=== ИСХОДНЫЙ МАССИВ ===\n");
                printf("Размер: %d строк х %d столбцов\n", n, m);
                printf("\nИсходная матрица:\n");
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        printf("%4d", A[i][j]);
                    }
                    printf("\n");
                }
                printf("\nВЫПОЛНЕННЫЕ ДЕЙСТВИЯ:\n");
                int imax = 0, jmax = 0;
                int max_value = abs(A[0][0]);

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (abs(A[i][j]) > max_value)
                        {
                            max_value = abs(A[i][j]);
                            imax = i;
                            jmax = j;
                        }
                        // else: элемент не больше, продолжаем поиск
                    }
                }
                printf("\nМаксимальный элемент: %d в позиции [%d][%d]\n", A[imax][jmax], imax, jmax);
                printf("Введите k: ");
                scanf("%d", &k);

                if (k < 0 || k >= n || k >= m)
                {
                    printf("Ошибка! k должно быть от 0 до %d\n", (n < m) ? n - 1 : m - 1);
                    // освобождаем память
                    for (int i = 0; i < n; i++)
                    {
                        free(A[i]);
                    }
                    free(A);
                    return 1;
                }
                // else: k корректно, продолжаем выполнение

                // меняем строки местами
                if (imax != k)
                {
                    int* temp = A[imax];
                    A[imax] = A[k];
                    A[k] = temp;
                    printf("Поменяли строки %d и %d\n", imax, k);
                }
                else
                {
                    printf("Максимальный элемент уже в строке %d, перестановка не нужна\n", k);
                }

                // меняем столбцы местами  
                if (jmax != k)
                {
                    for (int i = 0; i < n; i++)
                    {
                        int temp = A[i][jmax];
                        A[i][jmax] = A[i][k];
                        A[i][k] = temp;
                    }
                    printf("Поменяли столбцы %d и %d\n", jmax, k);
                }
                else
                {
                    printf("Максимальный элемент уже в столбце %d, перестановка не нужна\n", k);
                }

                // вывод результата
                printf("\n=== ПРЕОБРАЗОВАННЫЙ МАССИВ ===\n");
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        printf("%4d", A[i][j]);
                    }
                    printf("\n");
                }
                printf("\nМаксимальный элемент теперь в A[%d][%d] = %d\n", k, k, A[k][k]);
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
        for (int i = 0; i < n; i++)
            free(A[i]);
        free(A);
        // запрос на продолжение работы
        int continue_choice;
        printf("\n=================================\n");
        printf("Хотите продолжить работу?\n");
        printf("1. Продолжить (создать новую матрицу)\n");
        printf("2. Завершить работу\n");
        printf("Выберите действие: ");
        scanf("%d", &continue_choice);

        if (continue_choice == 2)
        {
            work = 0;
            printf("Работа программы завершена\n");
        }
        else
        {
            printf("\nПродолжаеи работу...\n");
            printf("=================================\n\n");
        }
    }

    system("pause");
    return 0;
}