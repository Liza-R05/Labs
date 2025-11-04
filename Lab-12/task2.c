#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float PI = 3.14159, * p1, * p2;
	p1 = p2 = &PI; // p1 и p1 содержат оба одинаковый адрес переменной PI
	// адреса одинаковые -- вывод покажет один адрес дл€ p1 и p2
	// %p - выводит адрес
	printf("ѕо адресу p1=%p хранитс€ *p1=%g\n", p1, *p1);
	printf("ѕо адресу p2=%p хранитс€ *p2=%g\n", p2, *p2);
	// %x - выводит адрес в шестнадцатеричном виде
	printf("\n¬ шестнадцатеричном формате:\n");
	printf("ѕо адресу p1=0x%x хранитс€ *p1=%g\n", p1, *p1);
	printf("ѕо адресу p2=0x%x хранитс€ *p2=%g\n", p2, *p2);
	system("pause");
}