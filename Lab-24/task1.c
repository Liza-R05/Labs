#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct Stack 
{
    int top;
    TYPE data[NMAX];
} stack;

// пуст ли стек {top==0}
int isempty(stack* s) 
{
    return s->top == 0;
}

// полон ли стек {top==NMAX-1}
int isfull(stack* s) 
{
    return s->top == NMAX - 1;
}

// элемент а в стек {top=top+1, data[top]=a}
int push(stack* s, TYPE a) 
{
    if (isfull(s)) 
    {
        return 0;  // стек полон
    }
    s->top = s->top + 1;
    s->data[s->top] = a;
    return 1;
}

// вернуть элемент {data[top]}, удалив его из стека {top=top-1}, если стек не пуст
TYPE pop(stack* s) 
{
    if (isempty(s)) 
    {
        return '\0';  // если стек пуст
    }
    TYPE value = s->data[s->top];
    s->top = s->top - 1;
    return value;
}

// вернуть значение элемента в вершине стека {return data[top]}
TYPE top(stack* s)
{
    if (isempty(s)) 
    {
        return '\0';
    }
    return s->data[s->top];
}

// вывод содержимого
void display(stack* s) 
{
    int i = s->top;
    while (i > 0) 
    {
        printf(FTYPE, s->data[i--]);
    }
    printf("\n");
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    stack s;
    char input[NMAX];
    // инициализация стека
    s.top = 0;

    printf("Введите строку: ");
    fgets(input, NMAX, stdin);

    // убрать символ новой строки из ввода
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') 
    {
        input[len - 1] = '\0';
        len--;
    }

    // заполн стек симв строки
    for (int i = 0; input[i] != '\0'; i++) 
    {
        if (!push(&s, input[i]))
        {
            printf("Стек переполнен! Можно добавить максимум %d символов.\n", NMAX - 1);
            break;
        }
    }

    printf("\nСодержимое стека: ");
    display(&s);

    return 0;
}