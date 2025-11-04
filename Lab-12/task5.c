#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void show_bytes(void* var, int size)
{
	unsigned char* bytes = (unsigned char*)var;
	for (int i = 0; i < size; i++)
	{
		printf("%.2x ", bytes[i]);
	}
	printf("\n");
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int x = 0x12345678;
	int* prt;
	unsigned char* a1, * a2, * a3, * a4;
	unsigned char* a;
	prt = &x;
	a = (unsigned char*)prt;
	a1 = a + 3;
	a2 = a + 2;
	a3 = a + 1;
	a4 = a;
	printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);
	if (*a1 == 0x12 && *a4 == 0x78)
	{
		printf("Система использует Big-endian\n");
	}
	else
	{
		printf("Система использует Little-endian\n");
	}
	int i = 12345;
	float f = 12345.0f;
	double d = 12345.0;
	printf("\n\nint:    %d\n", i);
	printf("float:  %.1f\n", f);
	printf("double: %.1f\n\n", d);
	printf("int:    ");
	show_bytes(&i, sizeof(i));
	printf("float:  ");
	show_bytes(&f, sizeof(f));
	printf("double: ");
	show_bytes(&d, sizeof(d));
	printf("\n");
	system("pause");
}
