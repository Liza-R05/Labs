#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "RUS");
    char tim[100];
    char date[100];
    char N[81];

    struct tm* mytime; // указатель на структуру tm
    time_t t;
    t = time(NULL);
    // трансформация его в структуру tm
    mytime = localtime(&t);
    
    // отступы для центрирования
    sprintf(tim, "Текущее время: %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    sprintf(date, "Сегодня %d-й день %d года", mytime->tm_yday + 1, mytime->tm_year + 1900);

    int time_padding = (80 - strlen(tim)) / 2;
    int date_padding = (80 - strlen(date)) / 2;

    for (int i = 0; i < 80; i++) 
    {
        N[i] = '*';
    }
    N[80] = '\0';

    printf("%s\n", N);
    printf("*%*s%s%*s*\n", time_padding - 1, "", tim, time_padding - 1, "");
    printf("*%*s%s%*s*\n", date_padding - 1, "", date, date_padding - 1, "");
    printf("%s\n", N);
    system("pause");
}
