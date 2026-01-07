#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define SIZE 5
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

void fill_array(Flight flights[], int size);
void print_flight(const Flight* flight);
void print_array(const Flight flights[], int size);

Flight* search_direction(Flight flights[], int size, char* direction);
void sort_flights(Flight flights[], int size, int criteria);

int output_file(const char* filename, Flight flights[], int n);
int input_file(const char* filename, Flight flights[]);

Flight* get_flight(Flight flights[], int index);
void edit_flight(Flight* flight);

int main() 
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    Flight flights[SIZE];
    int count = SIZE;
    int choice; int criteria;
    char search_dir[50]; int index;

    Flight init_flights[SIZE] = // конст знач
    {
        {101, "Moscow-SPb", "Boeing-737", 650, {10, 30}, {12, 0}},
        {202, "Moscow-Sochi", "Airbus-A320", 1200, {8, 45}, {12, 15}},
        {303, "SPb-Kazan", "Boeing-737", 800, {14, 20}, {16, 10}},
        {404, "Moscow-Ekaterinburg", "Airbus-A350", 1500, {9, 0}, {13, 30}},
        {505, "Kazan-Sochi", "Boeing-777", 950, {16, 45}, {20, 15}}
    };

    for (int i = 0; i < SIZE; i++) 
    {
        flights[i] = init_flights[i];  // копирование структур
    }

    do 
    {
        printf("\n--- МЕНЮ РАБОТЫ С РЕЙСАМИ ---\n");
        printf("1. Заполнить массив случайными значениями\n");
        printf("2. Вывести все рейсы\n");
        printf("3. Поиск рейса по направлению\n");
        printf("4. Сортировка рейсов\n");
        printf("5. Записать данные в файл\n");
        printf("6. Загрузить данные из файла\n");
        printf("7. Редактировать рейс\n");
        printf("8. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            fill_array(flights, SIZE);
            printf("Массив заполнен случайными значениями\n");
            break;

        case 2:
            print_array(flights, SIZE);
            break;

        case 3:
            printf("Введите направление для поиска: ");
            scanf("%s", search_dir);

            Flight* found = search_direction(flights, SIZE, search_dir);
            if (found != NULL) 
            {
                printf("\nНайден рейс:\n");
                print_flight(found);  // передаем указатель
            }
            else 
            {
                printf("Рейс с направлением '%s' не найден\n", search_dir);
            }
            break;

        case 4:
            printf("Сортировать по:\n");
            printf("1. Номеру рейса\n");
            printf("2. Расстоянию\n");
            printf("3. Времени вылета\n");
            printf("Выберите критерий: ");
            scanf("%d", &criteria);
            if (criteria >= 1 && criteria <= 3) 
            {
                sort_flights(flights, SIZE, criteria);
                print_array(flights, SIZE);
            }
            else {
                printf("Неверный критерий\n");
            }
            break;

        case 5:
            if (output_file(FILENAME, flights, SIZE)) 
            {
                printf("Данные записаны в файл '%s'\n", FILENAME);
            }
            else 
            {
                printf("Ошибка записи в файл\n");
            }
            break;

        case 6:
            if (input_file(FILENAME, flights)) 
            {
                printf("Данные загружены из файла '%s'\n", FILENAME);
            }
            else 
            {
                printf("Ошибка чтения из файла\n");
            }
            break;

        case 7: 
        {
            print_array(flights, SIZE);
            printf("\nВведите номер рейса для редактирования (1-%d): ", SIZE);
            scanf("%d", &index);

            if (index < 1 || index > SIZE) 
            {
                printf("Неверный номер\n");
                break;
            }

            Flight* flight_ptr = get_flight(flights, index - 1);
            printf("Редактирование рейса %d...\n", flight_ptr->number);

            edit_flight(flight_ptr);
            printf("Рейс отредактирован!\n");
            break;
        }

        case 8:
            printf("Выход из программы\n");
            break;

        default:
            printf("Неверный выбор\n");
        }

        printf("\n");
    } while (choice != 8);

    return 0;
}

void fill_array(Flight flights[], int size) 
{
    char* directions[] = { "Moscow-SPb", "Moscow-Sochi", "SPb-Kazan", "Moscow-Ekaterinburg", "Kazan-Sochi" };
    char* aircrafts[] = { "Boeing-737", "Airbus-A320", "Boeing-777", "Airbus-A350", "Boeing-787" };

    for (int i = 0; i < size; i++) 
    {
        flights[i].number = 100 + rand() % 900;
        strcpy(flights[i].direction, directions[rand() % 5]);
        strcpy(flights[i].aircraft, aircrafts[rand() % 5]);
        flights[i].distance = 500 + rand() % 2000;

        flights[i].departure.hours = 6 + rand() % 12;
        flights[i].departure.minutes = rand() % 60;

        int flight_time = 1 + rand() % 6;
        flights[i].arrival.hours = (flights[i].departure.hours + flight_time) % 24;
        flights[i].arrival.minutes = rand() % 60;
    }
}

void print_flight(const Flight* flight) 
{
    printf("Рейс %d: %s\n", flight->number, flight->direction);
    printf("  Самолет: %s\n", flight->aircraft);
    printf("  Расстояние: %d км\n", flight->distance);
    printf("  Вылет: %02d:%02d, Прилет: %02d:%02d\n",
        flight->departure.hours, flight->departure.minutes,
        flight->arrival.hours, flight->arrival.minutes);
}

void print_array(const Flight flights[], int size) 
{
    printf("\n=== СПИСОК РЕЙСОВ (всего: %d) ===\n", size);
    for (int i = 0; i < size; i++) 
    {
        printf("%d. ", i + 1);

        print_flight(&flights[i]);  // & - получаем адрес элемента
        printf("\n");
    }
}

Flight* search_direction(Flight flights[], int size, char* direction) 
{
    for (int i = 0; i < size; i++) 
    {
        if (strcmp(flights[i].direction, direction) == 0) 
        {
            return &flights[i];
        }
    }
    return NULL;
}

int compare_by_departure(const void* a, const void* b) 
{
    const Flight* flightA = (const Flight*)a;
    const Flight* flightB = (const Flight*)b;

    // сначала часы, потом минуты 
    if (flightA->departure.hours < flightB->departure.hours) return -1;
    if (flightA->departure.hours > flightB->departure.hours) return 1;

    // если часы равны, сравниваем минуты
    if (flightA->departure.minutes < flightB->departure.minutes) return -1;
    if (flightA->departure.minutes > flightB->departure.minutes) return 1;

    return 0;
}

int compare_by_distance(const void* a, const void* b) 
{
    const Flight* flightA = (const Flight*)a;
    const Flight* flightB = (const Flight*)b;

    return flightA->distance - flightB->distance;
}

int compare_by_number(const void* a, const void* b) 
{
    const Flight* flightA = (const Flight*)a;
    const Flight* flightB = (const Flight*)b;

    return flightA->number - flightB->number;
}

void sort_flights(Flight flights[], int size, int criteria) 
{
    switch (criteria) 
    {
    case 1: // по номеру
        qsort(flights, size, sizeof(Flight), compare_by_number);
        printf("Отсортировано по номеру рейса\n");
        break;
    case 2: // по расстоянию
        qsort(flights, size, sizeof(Flight), compare_by_distance);
        printf("Отсортировано по расстоянию\n");
        break;
    case 3: // по времени вылета
        qsort(flights, size, sizeof(Flight), compare_by_departure);
        printf("Отсортировано по времени вылета\n");
        break;
    }
}

int output_file(const char* filename, Flight flights[], int n) 
{
    FILE* file = fopen(filename, "wb");
    if (file == NULL) return 0;

    fwrite(&n, sizeof(int), 1, file);
    // передается как указатель на начало массива 
    fwrite(flights, sizeof(Flight), n, file);

    fclose(file);
    return 1;
}

int input_file(const char* filename, Flight flights[]) 
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return 0;

    int n;
    fread(&n, sizeof(int), 1, file);

    if (n > SIZE) 
    {
        fclose(file);
        return 0;
    }

    fread(flights, sizeof(Flight), n, file);

    fclose(file);
    return 1;
}

// получить указатель на элемент массива
Flight* get_flight(Flight flights[], int index) 
{
    return &flights[index];
}

void edit_flight(Flight* flight) 
{
    printf("Текущий номер: %d. Новый: ", flight->number);
    scanf("%d", &flight->number);

    printf("Текущее направление: %s. Новое: ", flight->direction);
    char new_dir[50];
    scanf("%s", new_dir);
    strcpy(flight->direction, new_dir);

    flight->departure.hours = (flight->departure.hours + 1) % 24;
    printf("Время вылета сдвинуто на 1 час\n");
}
