#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI 3.14159265358979323846
void main()
{
	setlocale(LC_ALL, "RUS");
	float gr;
	printf("¬ведите градус: ");
	scanf("%f", &gr);
	printf("–езультат: синус %.1f градусов = %1.20f\n\n", gr, sin(gr*M_PI/180));
	getchar();
}