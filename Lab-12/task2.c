#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float PI = 3.14159, * p1, * p2;
	p1 = p2 = &PI; // p1 и p1 содержат оба одинаковый адрес переменной PI
	// адреса одинаковые -- вывод покажет один адрес для p1 и p2
	// %p - выводит адрес
	printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);
	// %x - выводит адрес в шестнадцатеричном виде
	printf("\nВ шестнадцатеричном формате:\n");
	printf("По адресу p1=0x%x хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=0x%x хранится *p2=%g\n", p2, *p2);
	system("pause");
}
