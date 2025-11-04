#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
	float* ptr_a;
	printf("array: %p\n", array);
	printf("&array[0]: %p\n", &array[0]);
	printf("&array: %p\n\n", &array);
	ptr_a = array;
	printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	ptr_a++; 
	printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	ptr_a+=4; 
	printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
	ptr_a-=2;
	printf("ptr_a = %p, *ptr_a = %.1f\n\n", ptr_a, *ptr_a);
	ptr_a = array;
	for (int i = 0; i < 10; i += 2) 
	{
		printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
		ptr_a += 2;
	}
	printf("\n");
	ptr_a = &array[9]; // идут с нуля
	for (int i = 9; i >= 0; i--) 
	{
		printf("ptr_a = %p, *ptr_a = %.1f\n", ptr_a, *ptr_a);
		ptr_a--;
	}
	system("pause");
}