#ifndef _LIST_H
#define _LIST_H

struct listitem 
{
	int number;
	char name[80];
	struct listitem* next;
};

typedef struct listitem* List;

void initlist(List*); /* инициализация списка пустым содержимым */
void insertfront_num(List*, int val);/* вставка в список перед узлом со значением поля number=val */
void insertback_num(List*, int val);/* вставка в список перед узлом со значением поля number=val */
void insertfront_str(List*, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertback_str(List*, char* str);/* вставка в список перед узлом со значением str в поле name */
bool isempty(List*); /* проверяет, является ли список пустым*/
int length(List); /* определение длины списка */
void destroyItem(List*, List node); /* удаление заданного узла node из списка */
struct listitem* getitem(List, int n); /* нахождение узла со значением n в поле number*/
struct listitem* getitem(List, char* str); /* нахождение узла со значением str в поле name*/

#endif /* _LIST_H */
