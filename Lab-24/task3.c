#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100

typedef struct 
{
    int data[MAX];  // для хранения элементов
    int top;        // индекс вершины стека
} Stack;

// добавить элемент в стек
void push(Stack* s, int x)
{
    s->data[++s->top] = x;  // ув. top и сохраняем элемент
}

// извлечь элемент из стека
int pop(Stack* s) 
{
    return s->data[s->top--];  // возвращаем элемент и ум. top
}

// пуст ли стек
int empty(Stack* s) 
{
    return s->top == -1;  // если top = -1, стек пуст
}

// текущий размер стека
int stackSize(Stack* s) 
{
    return s->top + 1;
}

// обмен верхней и нижней половин
void swapHalves(Stack* s) 
{
    Stack t1, t2;        // доп стеки
    t1.top = t2.top = -1; // иниц. их как пустые

    int n = stackSize(s); // общее количество элементов
    int half = n / 2;

    // переносим весь стек s в стек t1
    while (!empty(s)) 
    {
        push(&t1, pop(s));
    }

    // первую половину из t1 в t2
    for (int i = 0; i < half; i++)
    {
        push(&t2, pop(&t1));
    }

    // добавляем вторую половину в исходный стек
    while (!empty(&t1)) 
    {
        push(s, pop(&t1));
    }

    // добавляем первую половину
    while (!empty(&t2))
    {
        push(s, pop(&t2));
    }
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    Stack s;
    s.top = -1;  // иниц. стек как пустой
    int n, value;

    printf("Сколько чисел добавить в стек? ");
    scanf("%d", &n);

    if (n > MAX) 
    {
        printf("Слишком много! Максимум %d\n", MAX);
        return 1;
    }

    printf("Введите %d чисел: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        push(&s, value);  // добавляем каждое число в стек
    }

    printf("\nВаш стек: ");
    for (int i = 0; i <= s.top; i++) 
    {
        printf("%d ", s.data[i]);  // исходный стек
    }

    // проверка достаточно ли элементов для обмена
    if (stackSize(&s) >= 2) 
    {
        swapHalves(&s);  // обмен половинами

        printf("\nПосле обмена половин: ");
        for (int i = 0; i <= s.top; i++) 
        {
            printf("%d ", s.data[i]);
        }
    }
    else 
    {
        printf("\nСлишком мало чисел для обмена\n");
    }

    return 0;
}
