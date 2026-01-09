#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list.h"

// Вспомогательная функция создания узла
struct listitem* create_node(int num, const char* name_str) 
{
    struct listitem* node = (struct listitem*)malloc(sizeof(struct listitem));
    if (node == NULL) return NULL;

    node->number = num;
    if (name_str != NULL)
    {
        strncpy(node->name, name_str, 79);
        node->name[79] = '\0';
    }
    else
    {
        node->name[0] = '\0';
    }
    node->next = NULL;

    return node;
}

void initlist(List* lst) 
{
    *lst = NULL;
}

bool isempty(List* lst) 
{
    return *lst == NULL;
}

int length(List lst) 
{
    int count = 0;
    if (lst == NULL) 
    {
        return 0; 
    }
    while (lst != NULL) 
        {
            count++;
            lst = lst->next;
        }
    return count;
}

void insertfront_num(List* lst, int val) 
{
    struct listitem* new_node = create_node(val, "");
    if (new_node == NULL) return;

    new_node->next = *lst;
    *lst = new_node;
}

void insertback_num(List* lst, int val) 
{
    struct listitem* new_node = create_node(val, "");
    if (new_node == NULL) return;

    if (*lst == NULL) 
    {
        *lst = new_node;
        return;
    }

    struct listitem* current = *lst;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void insertfront_str(List* lst, char* str) 
{
    struct listitem* new_node = create_node(0, str);
    if (new_node == NULL) return;

    new_node->next = *lst;
    *lst = new_node;
}

void insertback_str(List* lst, char* str)
{
    struct listitem* new_node = create_node(0, str);
    if (new_node == NULL) return;

    if (*lst == NULL)
    {
        *lst = new_node;
        return;
    }

    struct listitem* current = *lst;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = new_node;
}

void destroyItem(List* lst, List node)
{
    if (*lst == NULL || node == NULL) return;

    if (*lst == node)
    {
        *lst = node->next;
        free(node);
        return;
    }

    struct listitem* current = *lst;
    while (current != NULL && current->next != node)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        current->next = node->next;
        free(node);
    }
}

struct listitem* getitem_num(List lst, int n)
{
    while (lst != NULL) 
    {
        if (lst->number == n) 
        {
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}

struct listitem* getitem_str(List lst, char* str) 
{
    while (lst != NULL) 
    {
        if (strcmp(lst->name, str) == 0)
        {
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    List mylist;

    initlist(&mylist);
    printf("Список пуст? %s\n\n", isempty(&mylist) ? "Да" : "Нет");

    printf("Добавляем элементы:\n");
    insertfront_num(&mylist, 10);
    insertback_num(&mylist, 20);
    insertfront_str(&mylist, "первый");
    insertback_str(&mylist, "последний");

    printf("Длина списка: %d\n\n", length(mylist));

    printf("Поиск элементов:\n");
    struct listitem* found = getitem_num(mylist, 10);
    if (found != NULL) 
    {
        printf("\tНайден по номеру 10 \n\tИмя = '%s'\n", found->name);
    }

    found = getitem_str(mylist, "первый");
    if (found != NULL) 
    {
        printf("\tНайден по имени 'первый'\n\tНомер = %d\n", found->number);
    }

    printf("\nУдаление элемента:\n");
    found = getitem_num(mylist, 10);
    if (found != NULL)
    {
        destroyItem(&mylist, found);
        printf("\tУдален элемент с номером 10\n");
    }

    printf("\nНовая длина: %d\n", length(mylist));

    return 0;
}



