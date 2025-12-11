#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef double (*TFun)(double);

double calculate(TFun prtf, double* x, int n)
{
    if (n <= 0 || x == NULL || prtf == NULL) 
    {
        printf("Ошибка\n");
        return 0.0;
    }

    // min и max первым вычисленным значением
    double min_val = prtf(x[0]);
    double max_val = min_val;

    // по всем элементам массива
    for (int i = 1; i < n; i++) 
    {
        double current_val = prtf(x[i]);

        if (current_val < min_val) 
        {
            min_val = current_val;
        }
        if (current_val > max_val) 
        {
            max_val = current_val;
        }
    }
    return min_val + max_val;
}

double fun1(double x) 
{
    return 2 * exp(x * x);
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    double x[] = { 0.1, 0.5, 1.0, 1.5, 2.0 };
    int n = 5;

    double result1 = calculate(fun1, x, n);
    printf("Для fun1: min + max = %.6f\n", result1);

    system("pause");
    return 0;
}
