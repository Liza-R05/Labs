#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int *pi, i = 5;
	float *pf, f = 2.1f;
	char* pp;
	double* pk;
	printf("%lu\n", sizeof(pi));
	printf("%lu\n", sizeof(pf));
	printf("%lu\n", sizeof(pp));
	printf("%lu\n", sizeof(pk));
	system("pause");
}
