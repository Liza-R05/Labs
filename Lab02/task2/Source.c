#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int N=13, K=49;
	printf("\n������ %d ����� %d ����� 00 ������\n ", N, K);
	printf("\n���� %d ������ �����\n ", N);
	printf("\n�� �������� �������� %d ����� � %d �����\n ", 23-N, 59-K);
	printf("\n� 8.00 ������ %d ������\n ", ((N-8)*60*60)+(K*60));
	printf("\n������� ���  = %1.2f �����  � ������� ������ =  %1.2f ����\n ", N / 24.0, K / 60.0);
}