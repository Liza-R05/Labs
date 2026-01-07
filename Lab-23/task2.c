#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

struct Node 
{
    int value;
    struct Node* next;
};

typedef struct Node* IntList;

void init_list(IntList* lst);
void add_to_end(IntList* lst, int val);
void print_list(IntList lst);
int list_length(IntList lst);
double calculate_average(IntList lst);
void remove_than_average(IntList* lst, double average);
void clear_list(IntList* lst);

int main() 
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    IntList mylist;
    init_list(&mylist);

    printf("Создаём список:\n");

    for (int i = 0; i < 10; i++) 
    {
        int random_num = 1 + rand() % 100;
        add_to_end(&mylist, random_num);
    }

    printf("\nИсходный список:\n");
    print_list(mylist);
    printf("Длина: %d\n\n", list_length(mylist));

    double average = calculate_average(mylist);
    printf("\nСреднее арифметическое: %.2f\n\n", average);

    printf("Удаляем элементы больше %.2f\n", average);
    printf("Числа: ");

    struct Node* current = mylist;
    while (current != NULL)
    {
        if (current->value > average) 
        {
            printf("%d ", current->value);
        }
        current = current->next;
    }
    printf("\n");

    remove_than_average(&mylist, average);

    printf("\nПосле преобразования:\n");
    if (mylist == NULL) 
    {
        printf("Список пуст (элементы были больше среднего).\n");
    }
    else 
    {
        print_list(mylist);
        printf("Длина: %d\n", list_length(mylist));
    }

    clear_list(&mylist);
    return 0;
}


void init_list(IntList* lst) 
{
    *lst = NULL;
}

void add_to_end(IntList* lst, int val)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) return;

    new_node->value = val;
    new_node->next = NULL;

    if (*lst == NULL)
    {
        *lst = new_node;
        return;
    }

    struct Node* current = *lst;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(IntList lst) 
{
    if (lst == NULL) 
    {
        printf("Список пуст.\n");
        return;
    }

    printf("Содержимое списка: ");
    while (lst != NULL)
    {
        printf("%d", lst->value);
        if (lst->next != NULL) 
        {
            printf("  ");
        }
        lst = lst->next;
    }
    printf("\n");
}

int list_length(IntList lst) 
{
    int count = 0;
    while (lst != NULL) 
    {
        count++;
        lst = lst->next;
    }
    return count;
}

double calculate_average(IntList lst)
{
    if (lst == NULL) return 0.0;

    int sum = 0;
    int count = 0;

    while (lst != NULL) 
    {
        sum += lst->value;
        count++;
        lst = lst->next;
    }

    return (double)sum / count;
}

void remove_than_average(IntList* lst, double average)
{
    if (*lst == NULL) return;

    // удаляем элементы из начала списка
    while (*lst != NULL && (*lst)->value > average) 
    {
        struct Node* temp = *lst;
        *lst = (*lst)->next;
        free(temp);
    }

    if (*lst == NULL) return;

    // удаляем элементы из середины/конца списка
    struct Node* current = *lst;
    while (current->next != NULL)
    {
        if (current->next->value > average) 
        {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else 
        {
            current = current->next;
        }
    }
}

void clear_list(IntList* lst) 
{
    struct Node* current = *lst;
    struct Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *lst = NULL;
}