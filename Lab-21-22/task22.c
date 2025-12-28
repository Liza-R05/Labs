#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define SCREENW 60
#define SCREENH 40

// тип указателя на функцию
typedef double (*TFun)(double);

// прототипы
double fun1(double);
double fun2(double);
double fun3(double);
void tabulate_function(TFun, double, double, double, int*); // возвращает количество точек
void plot(double, double, TFun, char screen[SCREENW][SCREENH]); // только заполняет массив
double calculate_at_point(TFun, double); // просто вычисляет значение

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice, func_choice;
    TFun selected_func = NULL;
    char* func_name;
    double a, b, h, x, result;
    int count;
    char screen[SCREENW][SCREENH];

    do
    {
        printf("\n\n-----       МЕНЮ ПРОГРАММЫ      -----\n");
        printf("Выберите действие:\n");
        printf("1. Вычислить значение функции\n");
        printf("2. Табулировать функцию\n");
        printf("3. Выполнить операцию (построить график)\n");
        printf("0. Выход\n");
        printf("----------------------------------------\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Выход из программы...\n");
            break;
        }

        if (choice < 1 || choice > 3)
        {
            printf("Неверный выбор!\n");
            continue;
        }

        printf("-----       ВЫБОР ФУНКЦИИ      -----\n");
        printf("1. f1(x) = 2 * e^(x^2)\n");
        printf("2. f2(x) = sin^2(x)\n");
        printf("3. f3(x) = ln(tg(x^2))\n");
        printf("-------------------------------------\n");
        printf("Выберите функцию: ");
        scanf("%d", &func_choice);

        switch (func_choice)
        {
        case 1:
            selected_func = fun1;
            func_name = "2 * e^(x^2)";
            break;
        case 2:
            selected_func = fun2;
            func_name = "sin^2(x)";
            break;
        case 3:
            selected_func = fun3;
            func_name = "ln(tg(x^2))";
            break;
        default:
            printf("Неверный выбор функции\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("\nВычисление значения функции: %s\n", func_name);
            printf("Введите значение x: ");
            scanf("%lf", &x);

            result = calculate_at_point(selected_func, x);
            if (result != result)
                printf("f(%.3lf) = не определено\n", x);
            else
                printf("f(%.3lf) = %.6lf\n", x, result);
            break;

        case 2:
            printf("\nТабуляция функции: %s\n", func_name);
            printf("Введите начало интервала (a): ");
            scanf("%lf", &a);
            printf("Введите конец интервала (b): ");
            scanf("%lf", &b);
            printf("Введите шаг табуляции (h): ");
            scanf("%lf", &h);

            if (h <= 0) 
            {
                printf("Ошибка: шаг должен быть больше 0\n");
                break;
            }
            if (a > b) 
            {
                printf("Ошибка: начало должно быть меньше конца\n");
                break;
            }

            printf("\nРезультаты табуляции:\n");
            printf("---------------------\n");
            printf("     x     |     f(x)     \n");
            printf("-----------+-------------\n");

            tabulate_function(selected_func, a, b, h, &count);

            printf("-------------------------\n");
            printf("Вычислено значений: %d\n", count);
            break;

        case 3:
            printf("\nПостроение графика функции: %s\n", func_name);
            printf("Введите начало интервала: ");
            scanf("%lf", &a);
            printf("Введите конец интервала: ");
            scanf("%lf", &b);

            if (a >= b) {
                printf("Ошибка: начало должно быть меньше конца!\n");
                break;
            }

            printf("\nСтроим график...\n\n");
            plot(a, b, selected_func, screen);

            // Вывод графика в main
            for (int j = 0; j < SCREENH; ++j)
            {
                for (int i = 0; i < SCREENW; ++i)
                    putchar(screen[i][j]);
                putchar('\n');
            }
            break;
        }

        getchar();

    } while (choice != 0);

    return 0;
}

// 2 * e^(x^2)
double fun1(double x)
{
    return 2 * exp(x * x);
}

// sin^2(x)
double fun2(double x)
{
    double s = sin(x);
    return s * s;
}

// ln(tg(x^2))
double fun3(double x)
{
    double x2 = x * x;
    double tg_val = tan(x2);
    if (tg_val <= 0) return NAN;
    return log(tg_val);
}

// вычисляет значение в точке
double calculate_at_point(TFun f, double x)
{
    return f(x);
}

void tabulate_function(TFun f, double xn, double xk, double h, int* count)
{
    *count = 0;

    for (double x = xn; x <= xk + 0.000001; x += h, (*count)++)
    {
        double y = f(x);

        if (y != y)
            printf("%9.3lf  |  не определена\n", x);
        else
            printf("%9.3lf  | %12.6lf\n", x, y);

        if (*count >= 15 && x + h <= xk)
        {
            printf("     ...    |     ...     \n");
            printf("(вывод ограничен 15 знач.)\n");
            break;
        }

    }
}

// заполняет массив для графика
void plot(double x0, double x1, TFun f, char screen[SCREENW][SCREENH])
{
    double x, y[SCREENW];
    double ymin = 0, ymax = 0;
    double hx, hy; // шаги по x и y 
    int i, j;
    int xz, yz; // координаты пересечения осей

    // делим интервал на SCREENW-1 частей
    hx = (x1 - x0) / (SCREENW - 1);

    for (i = 0, x = x0; i < SCREENW; ++i, x += hx)
    {
        // функция в точке х
        y[i] = f(x);

        // минимальное и максимальное функции
        if (i == 0)
        {
            // инициализируем min и max
            ymin = y[i];
            ymax = y[i];
        }
        else
        {
            // обновляем min и max
            if (y[i] < ymin) 
            {
                ymin = y[i];
            }
            if (y[i] > ymax) 
            {
                ymax = y[i];
            }
        }
    }

    // если все значения функции одинаковы
    if (ymax == ymin)
    {
        ymin -= 1;  // сдвигаем минимум вниз
        ymax += 1;  // максимум вверх
    }

    // диапазон значений в экранные координаты
    hy = (ymax - ymin) / (SCREENH - 1);
    if (hy == 0) 
    {
        hy = 1;  // от деления на 0
    }

    // yz - экр коор оси X (y=0)
    yz = (int)floor((ymax - 0) / hy + 0.5);
    // xz - экр коор оси Y (x=0)
    xz = (int)floor((0. - x0) / hx + 0.5);

    for (j = 0; j < SCREENH; ++j)
    {
        for (i = 0; i < SCREENW; ++i)
        {
            screen[i][j] = ' ';  // весь экран пробелами
        }
    }

    if (yz >= 0 && yz < SCREENH)  // oX в пределах экрана
    {
        for (i = 0; i < SCREENW; ++i)
            screen[i][yz] = '-';
    }

    if (xz >= 0 && xz < SCREENW)  // oY в пределах экрана
    {
        for (j = 0; j < SCREENH; ++j)
            screen[xz][j] = '|';
    }

    // пересечение
    if (yz >= 0 && yz < SCREENH && xz >= 0 && xz < SCREENW)
    {
        screen[xz][yz] = '+';
    }

    // построение графика
    for (i = 0; i < SCREENW; ++i)
    {
        // значение функции в экр коор
        j = (int)floor((ymax - y[i]) / hy + 0.5);
        // в пределах экрана, есть пробел
        if (j >= 0 && j < SCREENH && screen[i][j] == ' ')
        {
            screen[i][j] = '*';
        }
    }

    // вывод
    for (j = 0; j < SCREENH; ++j)
    {
        // Вывод одной строки экрана
        for (i = 0; i < SCREENW; ++i)
        {
            putchar(screen[i][j]);
        }
        putchar('\n');  // на новую строку
    }
}
