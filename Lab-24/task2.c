#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TYPE char

struct Node
{
    TYPE data;
    struct Node* next;
};

typedef struct 
{
    struct Node* queue;
    struct Node* front;
    struct Node* back;
} queue_list;

// добавить элемент в очередь
void enQueue(queue_list* que, TYPE element) 
{
    // создаем новый узел
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    // если очередь пуста
    if (que->back == NULL)
    {
        que->front = newNode;
        que->back = newNode;
        que->queue = newNode;
    }
    else
    {
        que->back->next = newNode;
        que->back = newNode;
    }
}

// извлечь элемент из очереди
TYPE deQueue(queue_list* que) 
{
    // проверка на пустую очередь
    if (que->front == NULL) 
    {
        return '\0';  // если очередь пуста
    }

    // сохраняем данные из начала
    TYPE element = que->front->data;

    // сохраняем указатель на удаляемый узел
    struct Node* temp = que->front;

    // перемещаем начало
    que->front = que->front->next;

    // если очередь стала пустой
    if (que->front == NULL) 
    {
        que->back = NULL;
        que->queue = NULL;
    }
    else
    {
        que->queue = que->front; // обновляем queue
    }

    free(temp);
    return element;
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    queue_list q;
    char input[100];

    q.queue = NULL;
    q.front = NULL;
    q.back = NULL;

    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    // убираем символ новой строки
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') 
    {
        input[len - 1] = '\0';
    }

    // заполняем очередь символами строки
    for (int i = 0; input[i] != '\0'; i++) 
    {
        enQueue(&q, input[i]);
    }

    printf("\nСодержимое очереди: ");
    while (q.front != NULL) 
    {
        printf("%c", deQueue(&q));
    }
    printf("\n");

    return 0;
}
