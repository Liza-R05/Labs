#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int c;
	printf("Введите степень '10' от -12 до 12: ");
	scanf("%d", &c);
	switch (c)
	{
	case '-12':
		printf("10 в %d степени -- пико", c);
		break;
    case -9:
        printf("10 в %d степени -- нано", c);
        break;
    case -6:
        printf("10 в %d степени -- микро", c);
        break;
    case -3:
        printf("10 в %d степени -- милли", c);
        break;
    case -2:
        printf("10 в %d степени -- санти", c);
        break;
    case -1:
        printf("10 в %d степени -- деци", c);
        break;
    case 0:
        printf("без приставки");
        break;
    case 1:
        printf("10 в %d степени -- дека", c);
        break;
    case 2:
        printf("10 в %d степени -- гекто", c);
        break;
    case 3:
        printf("10 в %d степени -- кило", c);
        break;
    case 6:
        printf("10 в %d степени -- мега", c);
        break;
    case 9:
        printf("10 в %d степени -- гига", c);
        break;
    case 12:
        printf("10 в %d степени -- тера", c);
        break;
    default:
        printf("Названия приставки нет", c);
	}
}