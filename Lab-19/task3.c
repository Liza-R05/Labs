#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// для хранения времени
struct Time
{
    int hours;
    int minutes;
};

// для авиарейса
struct Flight
{
    int number;
    struct Time departure;
    struct Time arrival;
    char direction[50];
    char aircraft[30];
    int distance;
};

// для вычисления длительности полета в минутах
int flight_duration(struct Time dep, struct Time arr)
{
    int dep_minutes = dep.hours * 60 + dep.minutes;
    int arr_minutes = arr.hours * 60 + arr.minutes;

    // случай, когда прилет на следующий день
    if (arr_minutes < dep_minutes)
    {
        arr_minutes += 24 * 60;
    }

    return arr_minutes - dep_minutes;
}

// для ввода времени
void input_time(struct Time* t, const char* prompt)
{
    printf("%s (часы минуты): ", prompt);
    scanf("%d %d", &t->hours, &t->minutes);
}

void input_flight(struct Flight* f)
{
    printf("\n--Ввод данных о рейсе--\n");
    printf("Номер рейса: ");
    scanf("%d", &f->number);

    input_time(&f->departure, "Время вылета");
    input_time(&f->arrival, "Время прилета");

    printf("Направление: ");
    scanf("%s", f->direction);

    printf("Марка самолета: ");
    scanf("%s", f->aircraft);

    printf("Расстояние (км): ");
    scanf("%d", &f->distance);
}

// для вывода данных о рейсе
void print_flight(struct Flight f)
{
    printf("Рейс %d: %s - %s\n", f.number, f.direction, f.aircraft);
    printf("  Вылет: %02d:%02d, Прилет: %02d:%02d\n",
        f.departure.hours, f.departure.minutes,
        f.arrival.hours, f.arrival.minutes);
    printf("  Расстояние: %d км\n", f.distance);
    printf("  Длительность: %d ч %d мин\n",
        flight_duration(f.departure, f.arrival) / 60,
        flight_duration(f.departure, f.arrival) % 60);
}

// Функция записи массива структур в файл
int writefile(char* filename, struct Flight* flights, int size)
{
    FILE* out;
    if ((out = fopen(filename, "wt")) == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        {
            fprintf(out, "Номер рейса: %d ; Вылет: %d %d ; Прилет: %d %d ; Направление: %s ; Марка самолета: %s ; Расстояние (км): %d\n", flights[i].number, flights[i].departure.hours, 
                flights[i].departure.minutes, flights[i].arrival.hours, flights[i].arrival.minutes, flights[i].direction, flights[i].aircraft, flights[i].distance);
        }
    }

    fclose(out);
    return 1;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    struct Flight flights[3];
    int max_duration = 0;
    int max_index = 0;

    printf("Введите данные о 3 авиарейсах:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n=== Рейс %d ===\n", i + 1);
        input_flight(&flights[i]);
    }

    // поиск рейса с максимальной длительностью
    for (int i = 0; i < 3; i++)
    {
        int duration = flight_duration(flights[i].departure, flights[i].arrival);
        if (duration > max_duration)
        {
            max_duration = duration;
            max_index = i;
        }
    }

    // в консоль
    printf("\n--Рейс с МАКС длительностью--\n");
    print_flight(flights[max_index]);

    // в файл
    writefile("flights.txt", flights, 3);

    printf("\n");
    system("pause");
    return 0;
}