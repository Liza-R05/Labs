#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int L = 1323, n = 2;
	printf("����:\n \t%d\n \t%4.0d\n ", L, n);
	printf("\t_______");
	printf("\n�����:\n \t+%011.7f\n ", 2.0 / 1323);
}