#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#define MENU_EXIT 0
#define MENU_CALCULATE 1
#define MENU_TABULATE 2
#define MENU_OPERATION 3
#define SCREENW 60
#define SCREENH 40

// тип указателя на функцию
typedef double (*TFun)(double);
// прототипы
double fun1(double);
double fun2(double);
double fun3(double);
void t_rez(TFun, double, double, double);
void plot(double, double, TFun);
void tabulate_function(TFun);
void calculate_value(TFun);
void plot_function(TFun);

int main() 
{
    setlocale(LC_ALL, "RUS");
    int choice, func_choice;
    TFun selected_func = NULL;
    char func_name[50];
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
        if (choice == MENU_EXIT) 
        {
            printf("Выход из программы...\n");
            break;
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
            strcpy(func_name, "f1(x) = 2 * e^(x^2)");
            break;
        case 2:
            selected_func = fun2;
            strcpy(func_name, "f2(x) = sin^2(x)");
            break;
        case 3:
            selected_func = fun3;
            strcpy(func_name, "f3(x) = ln(tg(x^2))");
            break;
        default:
            printf("Неверный выбор\n");
            system("pause");
            break;
        }

        switch (choice) 
        {
        case MENU_CALCULATE:
            calculate_value(selected_func);
            break;
        case MENU_TABULATE:
            tabulate_function(selected_func);
            break;
        case MENU_OPERATION:
            plot_function(selected_func);
            break;
        default:
            printf("Неверный выбор\n");
        }
        getchar();
    } while (choice != MENU_EXIT);

    system("pause");
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
    return log(tg_val);
}

void calculate_value(TFun f)
{
    double x, result;
    printf("---   ВЫЧИСЛЕНИЕ ЗНАЧЕНИЯ ФУНКЦИИ   ---\n");
    printf("---------------------------------------\n");
    printf("Введите значение x: ");
    scanf("%lf", &x);

    result = f(x);
    printf("f(%.3lf) = %.6lf\n", x, result);
}

void tabulate_function(TFun f)
{
    double a, b, h;
    printf("Табуляция функций\n");
    printf("-----------------\n\n");

    printf("Введите начало интервала (a): ");
    scanf("%lf", &a);
    printf("Введите конец интервала (b): ");
    scanf("%lf", &b);
    printf("Введите шаг табуляции (h): ");
    scanf("%lf", &h);

    printf("\n");
    printf("Результаты табуляции:\n");
    printf("---------------------\n\n");
    t_rez(f, a, b, h);
}

void plot(double x0, double x1, TFun f)
{
    char screen[SCREENW][SCREENH];
    double x, y[SCREENW];
    double ymin = 0, ymax = 0;
    double hx, hy;
    int i, j;
    int xz, yz;

    hx = (x1 - x0) / (SCREENW - 1);

    for (i = 0, x = x0; i < SCREENW; ++i, x += hx) 
    {
        y[i] = f(x); //расчет значений функции для каждой точки поля вывода графика
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }

    hy = (ymax - ymin) / (SCREENH - 1);
    yz = (int)floor(ymax / hy + 0.5);
    xz = (int)floor((0. - x0) / hx + 0.5);

    //построение осей и заполнение массива отображения пробелами
    for (j = 0; j < SCREENH; ++j)
        for (i = 0; i < SCREENW; ++i) 
        {
            if (j == yz && i == xz) screen[i][j] = '+';
            else if (j == yz) screen[i][j] = '-';
            else if (i == xz) screen[i][j] = '|';
            else screen[i][j] = ' ';
        }

    //определение положения значения функции на поле вывода
    for (i = 0; i < SCREENW; ++i) 
    {
        j = (int)floor((ymax - y[i]) / hy + 0.5);
        screen[i][j] = '*';
    }

    //печать массива символов
    for (j = 0; j < SCREENH; ++j) 
    {
        for (i = 0; i < SCREENW; ++i)  putchar(screen[i][j]);
        putchar('\n');
    }
}

void plot_function(TFun f)
{
    double a, b;

    printf("\n-----  ПОСТРОЕНИЕ ГРАФИКА ФУНКЦИИ  -----\n");
    printf("Введите начало интервала: ");
    scanf("%lf", &a);
    printf("Введите конец интервала: ");
    scanf("%lf", &b);

    if (a >= b) {
        printf("Ошибка: начало должно быть меньше конца!\n");
        return;
    }

    printf("\nСтроим график...\n\n");
    plot(a, b, f);
}

void t_rez(TFun f, double xn, double xk, double h) 
{
    int count = 0;  // счетчик

    if (h <= 0) 
    {
        printf("Ошибка, шаг не больше 0\n");
        return;
    }

    if (xn > xk) 
    {
        printf("Ошибка, начало конца\n");
        return;
    }

    printf("     x     |     f(x)     \n");
    printf("-----------+-------------\n");

    for (double x = xn; x <= xk + 0.000001; x += h) 
    {
        double y;
        // проверки для третьей функции
        if (f == fun3) 
        {
            double x2 = x * x;
            // tg(x^2) не определен при cos(x^2) = 0
            // ln не определен для отрицательных чисел
            if (cos(x2) == 0 || tan(x2) <= 0) 
            {
                printf("%9.3lf  |  не определена\n", x);
                count++;
                continue;
            }
        }

        y = f(x);

        printf("%9.3lf  | %12.6lf\n", x, y);
        count++;

        if (count >= 15 && x + h <= xk) 
        {
            printf("     ...    |     ...     \n");
            printf("(вывод ограничен 15 знач.)\n");
            break;
        }
    }

    printf("-------------------------\n");
    printf("Вычислено значений: %d\n", count);
}
