#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX_FLIGHTS 5
#define FILENAME "flights.dat"

typedef struct 
{
    int number;          // номер рейса
    char direction[50];  // направление
    char aircraft[30];   // марка самолета
    int distance;        // расстояние (км)
    struct 
    {
        int hours;
        int minutes;
    } departure;         // время вылета
    struct 
    {
        int hours;
        int minutes;
    } arrival;           // время прилета
} Flight;

void displayMenu();
void fillArray(Flight flights[], int* count);
void printFlight(Flight flight);
void printArray(Flight flights[], int size);
void loadFromFile(Flight flights[], int* count);
void saveToFile(Flight flights[], int count);
void addFlight(Flight flights[], int* count);
void editFlight(Flight flights[], int count);
Flight* searchFlight(Flight flights[], int count);
void sortFlights(Flight flights[], int count);
int compareByNumber(const void* a, const void* b);
int compareByDistance(const void* a, const void* b);
int compareByDeparture(const void* a, const void* b);
int getRandomNumber(int min, int max);

int main() 
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    Flight flights[MAX_FLIGHTS];
    int count = 0;
    int choice;

    do 
    {
        displayMenu();
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            loadFromFile(flights, &count);
            break;
        case 2:
            saveToFile(flights, count);
            break;
        case 3:
            fillArray(flights, &count);
            break;
        case 4:
            if (count == 0) 
            {
                printf("Нет данных\n");
            }
            else 
            {
                printArray(flights, count);
            }
            break;
        case 5:
            addFlight(flights, &count);
            break;
        case 6:
            if (count == 0) 
            {
                printf("Нет данных\n");
            }
            else 
            {
                editFlight(flights, count);
            }
            break;
        case 7:
            if (count == 0) 
            {
                printf("Нет данных\n");
            }
            else 
            {
                Flight* found = searchFlight(flights, count);
                if (found != NULL) 
                {
                    printf("\nНайден рейс:\n");
                    printFlight(*found);
                }
                else 
                {
                    printf("Рейс не найден!\n");
                }
            }
            break;
        case 8:
            if (count == 0) 
            {
                printf("Нет данных\n");
            }
            else 
            {
                sortFlights(flights, count);
            }
            break;
        case 9:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор\n");
        }

        printf("\n");

    } while (choice != 9);

    return 0;
}

// Функция отображения меню
void displayMenu() 
{
    printf("\n--- МЕНЮ УПРАВЛЕНИЯ АВИАРЕЙСАМИ ---\n");
    printf("1. Загрузить данные из файла\n");
    printf("2. Сохранить данные в файл\n");
    printf("3. Заполнить массив случайными данными\n");
    printf("4. Показать все рейсы\n");
    printf("5. Добавить новый рейс\n");
    printf("6. Редактировать рейс\n");
    printf("7. Поиск рейса\n");
    printf("8. Сортировка рейсов\n");
    printf("9. Выход\n");
    printf("--------------------------------------\n");
}

// генерации случайного числа
int getRandomNumber(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

// заполнение случайными значениями
void fillArray(Flight flights[], int* count)
{
    int num;
    printf("Сколько рейсов создать? ");
    scanf("%d", &num);
    while (getchar() != '\n');

    if (num <= 0)
    {
        printf("Неверное количество!\n");
        return;
    }

    if (num > MAX_FLIGHTS - *count)
    {
        printf("Недостаточно места! Можно добавить только %d рейсов.\n", MAX_FLIGHTS - *count);
        return;
    }

    char* cities[] = { "Moscow", "SPb", "Sochi", "Kazan", "Ekaterinburg", "Novosibirsk", "Krasnodar" };
    char* aircrafts[] = { "Boeing-737", "Airbus-A320", "Boeing-777", "Airbus-A350", "Airbus-A100" };

    printf("Создание %d рейсов...\n", num);

    for (int i = 0; i < num; i++)
    {
        int idx = *count + i;

        flights[idx].number = 100 + rand() % 900;

        int city1 = rand() % 7;
        int city2;
        do 
        {
            city2 = rand() % 7;
        } while (city2 == city1);

        char temp_dir[50];
        sprintf(temp_dir, "%s-%s", cities[city1], cities[city2]);
        strncpy(flights[idx].direction, temp_dir, sizeof(flights[idx].direction) - 1);
        flights[idx].direction[sizeof(flights[idx].direction) - 1] = '\0';

        strncpy(flights[idx].aircraft, aircrafts[rand() % 5], sizeof(flights[idx].aircraft) - 1);
        flights[idx].aircraft[sizeof(flights[idx].aircraft) - 1] = '\0';

        flights[idx].distance = 500 + rand() % 4501;
        flights[idx].departure.hours = 6 + rand() % 18;
        flights[idx].departure.minutes = rand() % 60;

        int flight_time = 1 + rand() % 6;
        flights[idx].arrival.hours = (flights[idx].departure.hours + flight_time) % 24;
        flights[idx].arrival.minutes = rand() % 60;

        printf("  Создан рейс %d\n", flights[idx].number);
    }

    *count += num;
    printf("Готово! Создано %d рейсов. Всего: %d\n", num, *count);
}

// вывод 1 рейса
void printFlight(Flight flight) 
{
    printf("Рейс %d: %s\n", flight.number, flight.direction);
    printf("  Самолет: %s\n", flight.aircraft);
    printf("  Расстояние: %d км\n", flight.distance);
    printf("  Вылет: %02d:%02d, Прилет: %02d:%02d\n",
        flight.departure.hours, flight.departure.minutes,
        flight.arrival.hours, flight.arrival.minutes);
}

// всего массива
void printArray(Flight flights[], int size) 
{
    printf("\n--- СПИСОК АВИАРЕЙСОВ ---\n");
    printf("Всего рейсов: %d\n\n", size);

    for (int i = 0; i < size; i++) 
    {
        printf("%d. ", i + 1);
        printFlight(flights[i]);
        printf("\n");
    }
}

// загрузка из файла
void loadFromFile(Flight flights[], int* count) 
{
    FILE* file = fopen(FILENAME, "rb");

    if (file == NULL) 
    {
        printf("Файл не найден\n");
        *count = 0;
        return;
    }

    // количество рейсов
    fread(count, sizeof(int), 1, file);

    if (*count > MAX_FLIGHTS) 
    {
        printf("Ошибка, много записей!\n");
        fclose(file);
        *count = 0;
        return;
    }

    // массив структур
    fread(flights, sizeof(Flight), *count, file);

    fclose(file);
    printf("Загружено %d рейсов из файла %s\n", *count, FILENAME);
}

// в файл
void saveToFile(Flight flights[], int count) 
{
    FILE* file = fopen(FILENAME, "wb");

    if (file == NULL) 
    {
        printf("Ошибка\n");
        return;
    }

    // количество рейсов
    fwrite(&count, sizeof(int), 1, file);

    // массив структур
    fwrite(flights, sizeof(Flight), count, file);

    fclose(file);
    printf("Сохранено %d рейсов в файл %s\n", count, FILENAME);
}

// добавление нового
void addFlight(Flight flights[], int* count) 
{
    if (*count >= MAX_FLIGHTS) 
    {
        printf("Максимальный размер массива!\n");
        return;
    }

    Flight newFlight;

    printf("\n--- ДОБАВЛЕНИЕ НОВОГО РЕЙСА ---\n");

    printf("Номер рейса: ");
    scanf("%d", &newFlight.number);

    printf("Направление: ");
    scanf("%s", newFlight.direction);

    printf("Марка самолета: ");
    scanf("%s", newFlight.aircraft);

    printf("Расстояние (км): ");
    scanf("%d", &newFlight.distance);

    printf("Время вылета (часы минуты): ");
    scanf("%d %d", &newFlight.departure.hours, &newFlight.departure.minutes);

    printf("Время прилета (часы минуты): ");
    scanf("%d %d", &newFlight.arrival.hours, &newFlight.arrival.minutes);

    flights[*count] = newFlight;
    (*count)++;

    printf("Рейс успешно добавлен!\n");
}

// редактирование рейса
void editFlight(Flight flights[], int count) 
{
    int index;

    printArray(flights, count);

    printf("\nВведите номер рейса для редактирования (1-%d): ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) 
    {
        printf("Неверный номер\n");
        return;
    }

    index--; // перевод в 0 инд

    printf("\nРедактирование рейса %d:\n", flights[index].number);

    printf("Новый номер рейса [%d]: ", flights[index].number);
    int temp;
    if (scanf("%d", &temp) == 1) 
    {
        flights[index].number = temp;
    }

    printf("Новое направление [%s]: ", flights[index].direction);
    char buf[50];
    getchar(); 
    if (fgets(buf, sizeof(buf), stdin) != NULL && buf[0] != '\n') 
    {
        buf[strcspn(buf, "\n")] = '\0';
        strcpy(flights[index].direction, buf);
    }

    printf("Рейс успешно отредактирован!\n");
}

// поиск рейса
Flight* searchFlight(Flight flights[], int count) 
{
    int choice;
    printf("\n--- ПОИСК РЕЙСА ---\n");
    printf("Поиск по:\n");
    printf("1. Номеру рейса\n");
    printf("2. Направлению\n");
    printf("3. Марке самолета\n");
    printf("Выберите поле для поиска: ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
        int number;
        printf("Введите номер рейса: ");
        scanf("%d", &number);

        for (int i = 0; i < count; i++) 
        {
            if (flights[i].number == number) 
            {
                return &flights[i];
            }
        }
    }
    else if (choice == 2) 
    {
        char direction[50];
        printf("Введите направление: ");
        scanf("%s", direction);

        for (int i = 0; i < count; i++) 
        {
            if (strcmp(flights[i].direction, direction) == 0) 
            {
                return &flights[i];
            }
        }
    }
    else if (choice == 3) 
    {
        char aircraft[30];
        printf("Введите марку самолета: ");
        scanf("%s", aircraft);

        for (int i = 0; i < count; i++) 
        {
            if (strcmp(flights[i].aircraft, aircraft) == 0) 
            {
                return &flights[i];
            }
        }
    }

    return NULL;
}

// сортировка
void sortFlights(Flight flights[], int count) 
{
    int choice;

    printf("\n--- СОРТИРОВКА РЕЙСОВ ---\n");
    printf("Сортировать по:\n");
    printf("1. Номеру рейса\n");
    printf("2. Расстоянию\n");
    printf("3. Времени вылета\n");
    printf("Выберите поле для сортировки: ");
    scanf("%d", &choice);

    switch (choice) 
    {
    case 1:
        qsort(flights, count, sizeof(Flight), compareByNumber);
        printf("Отсортировано по номеру рейса.\n");
        break;
    case 2:
        qsort(flights, count, sizeof(Flight), compareByDistance);
        printf("Отсортировано по расстоянию.\n");
        break;
    case 3:
        qsort(flights, count, sizeof(Flight), compareByDeparture);
        printf("Отсортировано по времени вылета.\n");
        break;
    default:
        printf("Неверный выбор!\n");
        return;
    }

    printArray(flights, count);
}

// сравнение
int compareByNumber(const void* a, const void* b) 
{
    const Flight* flightA = (const Flight*)a;
    const Flight* flightB = (const Flight*)b;

    if (flightA->number < flightB->number) return -1;
    if (flightA->number > flightB->number) return 1;
    return 0;
}

int compareByDistance(const void* a, const void* b) 
{
    const Flight* flightA = (const Flight*)a;
    const Flight* flightB = (const Flight*)b;

    if (flightA->distance < flightB->distance) return -1;
    if (flightA->distance > flightB->distance) return 1;
    return 0;
}

int compareByDeparture(const void* a, const void* b) 
{
    const Flight* flightA = (const Flight*)a;
    const Flight* flightB = (const Flight*)b;

    // часы
    if (flightA->departure.hours < flightB->departure.hours) return -1;
    if (flightA->departure.hours > flightB->departure.hours) return 1;

    // минуты
    if (flightA->departure.minutes < flightB->departure.minutes) return -1;
    if (flightA->departure.minutes > flightB->departure.minutes) return 1;

    return 0;
}