#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// Определение структуры для точки
struct point 
{
    float x;
    float y;
    char name;
};

// Объявление типа Point для структуры
typedef struct point Point;

void put_point(Point z) 
{
    printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}

void input_point(Point* p) 
{
    printf("Введите имя точки: ");
    scanf(" %c", &p->name);
    printf("Введите координату x: ");
    scanf("%f", &p->x);
    printf("Введите координату y: ");
    scanf("%f", &p->y);
}

// вычисления декартова расстояния между двумя точками
float dist(Point z, Point w) 
{
    float dx = w.x - z.x;
    float dy = w.y - z.y;
    return sqrtf(dx * dx + dy * dy);
}

Point midpoint(Point a, Point b) 
{
    Point mid;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    mid.name = 'M'; // M - середина
    return mid;
}

void main()
{
    setlocale(LC_ALL, "RUS");
    Point a, b, middle;

    printf("Ввод точки A: \n");
    input_point(&a);
    printf("\nВвод точки B: \n");
    input_point(&b);

    printf("\nВведенные точки:\n");
    put_point(a);
    printf("\n");
    put_point(b);
    printf("\n");

    printf("\nРасстояние между точками: ");
    float distance = dist(a, b);
    printf(" = %.2f\n", distance);

    printf("\nСередина отрезка:\n");
    middle = midpoint(a, b);
    put_point(middle);
    printf("\n");

    system("pause");
}
