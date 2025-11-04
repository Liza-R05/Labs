#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int *pa, x = 5;
	double d = 3.14;
	char c = 'A';
	long double ld = 3.14L;
	short s = 100;
	unsigned int ui = 200;
	_Bool b = 1;

	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	// увеличиваем на 1
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	// вычисляем разницу адресов, используя char для вычисления в байтах (в int будет равно 1)
	printf("Увеличение адреса: %ld байт\n", (char*)pa - (char*)(pa - 1));
	// возвращаем обратно
	pa--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", pa, *pa);
	
	// 1. double
	double *pd = &d;
	printf("По адресу %p хранится *ptr=%g\n", pd, *pd);
	pd++;
	printf("По адресу %p хранится *ptr=%g\n", pd, *pd);
	printf("Увеличение адреса: %ld байт\n", (char*)pd - (char*)(pd - 1));
	pd--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", pd, *pd);
	
	// 2. char   всегда занимает 1 байт
	char *pc = &c;
	printf("По адресу %p хранится *ptr=%g\n", pc, *pc);
	pc++;
	printf("По адресу %p хранится *ptr=%g\n", pc, *pc);
	printf("Увеличение адреса: %ld байт\n", (char*)pc - (char*)(pc - 1));
	pc--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", pc, *pc);

	// 3. long double  смещение на 8 байт
	long double* pld = &ld;
	printf("По адресу %p хранится *ptr=%g\n", pld, *pld);
	pld++;
	printf("По адресу %p хранится *ptr=%g\n", pld, *pld);
	printf("Увеличение адреса: %ld байт\n", (char*)pld - (char*)(pld - 1));
	pld--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", pld, *pld);

	// 4. short смещение на 2 байта, короткий
	short* ps = &s;
	printf("По адресу %p хранится *ptr=%g\n", ps, *ps);
	ps++;
	printf("По адресу %p хранится *ptr=%g\n", ps, *ps);
	printf("Увеличение адреса: %ld байт\n", (char*)ps - (char*)(ps - 1));
	ps--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", ps, *ps);

	// 5. unsigned int   размер такой же как у обычного int -- смещение на 4 байта
	unsigned int* pui = &ui;
	printf("По адресу %p хранится *ptr=%g\n", pui, *pui);
	pui++;
	printf("По адресу %p хранится *ptr=%g\n", pui, *pui);
	printf("Увеличение адреса: %ld байт\n", (char*)pui - (char*)(pui - 1));
	pui--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", pui, *pui);

	// 6. _Bool  занимает целый байт
	_Bool* pb = &b;
	printf("По адресу %p хранится *ptr=%g\n", pb, *pb);
	pb++;
	printf("По адресу %p хранится *ptr=%g\n", pb, *pb);
	printf("Увеличение адреса: %ld байт\n", (char*)pb - (char*)(pb - 1));
	pb--;
	printf("По адресу %p хранится *ptr=%g\n\n\n", pb, *pb);
	system("pause");
}
