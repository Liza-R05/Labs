#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	float x, y;
	char c;
	printf("¬ведите выражение: ");
	scanf("%f%c%f", &x, &c, &y);
	switch (c)
	{
	case '+':
		printf(" = %.1f", x + y);
		break;
	case '-':
		printf(" = %.1f", x - y);
		break;
	case '*':
		printf(" = %.1f", x * y);
		break;
	case '/':
		printf(" = %.1f", x / y);
		break;
	case '^':
		printf(" = %.1f", pow(x,y));
		break;
	default:
		printf("ќшибка");
	}
	return 0;
}