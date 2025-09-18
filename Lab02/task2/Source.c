#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int N=13, K=49;
	printf("\nСейчас %d часов %d минут 00 секунд\n ", N, K);
	printf("\nИдет %d минута суток\n ", N);
	printf("\nДо полуночи осталось %d часов и %d минут\n ", 23-N, 59-K);
	printf("\nС 8.00 прошло %d секунд\n ", ((N-8)*60*60)+(K*60));
	printf("\nТекущий час  = %1.2f суток  и текущая минута =  %1.2f часа\n ", N / 24.0, K / 60.0);
}