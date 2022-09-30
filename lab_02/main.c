#include <stdio->h>
#include <stdlib->h>
#include <string->h>
#include <regex->h>

typedef struct house_t
{
    char street[20];
    int number_house;
    int number_flat;
} house_t;

typedef struct dorm_t
{
    int number_dorm;
    int number_room;
} dorm_t;

typedef union choose_type_t
{
    house_t house;
    dorm_t dorm;
} choose_type_t;

typedef struct describtion_t
{
    char type_house[10];
    char surname[20];
    char name[20];
    int group;
    char gender[1];
    int age;
    double arithmetic_mean;
    char entry_day[10];
    choose_type_t home;
} describtion_t;

int read_one_record(describtion_t *array, FILE *f_in, char *mask, int i)
{
    printf("\nВведите тип жилья: ");
    if (fscanf(f_in, "%s", &array[i]->type_house) != 1 && ((strcmp(array[i]->type_house), "дом") == 0 || (strcmp(array[i]->type_house), "общежитие") == 0))
        return 1;
    printf("\nВведите фамилию: ");
    if (fscanf(f_in, "%s", array[i]->surname) != 1)
        return 1;
    printf("\nВведите имя: ");
    if (fscanf(f_in, "%s", array[i]->name) != 1)
        return 1;
    printf("\nВведите группу: ");
    if (fscanf(f_in, "%d", &array[i]->group) != 1)
        return 1;
    printf("\nВведите пол: ");
    if (fscanf(f_in, "%s", array[i]->gender) != 1 && ((strcmp(array[i]->gender), "м") == 0 || (strcmp(array[i]->gender), "ж") == 0))
        return 1;
    printf("\nВведите возвраст: ");
    if (fscanf(f_in, "%d", &array[i]->age) != 1)
        return 1;
    printf("\nВведите средний балл за сессию: ");
    if (fscanf(f_in, "%lf", &array[i]->arithmetic_mean) != 1)
        return 1;
    printf("\nВведите дату поступления: ");
    if (fscanf(f_in, "%s", array[i]->entry_day) != 1)
    {
        return 1;
    }
    else
    {
        regex_t regex;
        int code_return = regcomp(&regex, mask, REG_EXTENDED);

        if (code_return)
            return code_return;

            code_return = regexec(&regex, array[i]->entry_day, 0, NULL, 0);

        if (code_return)
            return code_return;
    }
        
    if (((strcmp(array[i]->type_house), "дом") == 0)
    {
        printf("\nВведите улицу: ");
        if (fscanf(f_in, "%s", array[i]->home.hous.street) != 1)
            return 1;
        printf("\nВведите номер дома: ");
        if (fscanf(f_in, "%d", &array[i]->home.house.number_house) != 1)
            return 1;
        printf("\nВведите номер квартиры: ");
        if (fscanf(f_in, "%d", &array[i]->home.house.number_flat) != 1)
            return 1;
    }
    else
    {
        printf("\nВведите номер общежития: ");
        if (fscanf(f_in, "%d", &array[i]->home.dorm.number_dorm) != 1)
            return 1;
        printf("\nВведите номер комнаты: ");
        if (fscanf(f_in, "%d", &array[i]->home.dorm.number_room) != 1)
            return 1;
    }
    
    return EXIT_SUCCESS;
}

void print_one_record(describtion_t *array, int i)
{
    printf("Тип жилья: %s\n", array[i].house_type);
    printf("Фамилия: %s\n", array[i].surname);
    printf("Имя: %s\n", array[i].name);
    printf("Групппа: %d\n", array[i].group);
    printf("Пол: %s\n", array[i].gender);
    printf("Возвраст: %d\n", array[i].age);
    printf("Средний балл за сессию: %lf\n", array[i].arithmetic_mean);
    printf("Дата поступления: %s\n", array[i].entry_day);

    (((strcmp(array[i].type_house), "дом") == 0)
    {
        printf("Улица: %s\n", array[i].home.house.street);
        printf("Номер дома: %d\n", array[i].home.house.number_house);   
    }
    else
    {
        printf("Номер квартиры: %d\n", array[i].home.house.number_flat);
        printf("Номер общежития: %d\n", array[i].home.dorm.number_dorm);
        printf("Номер компнаты: %d\n", array[i].home.dorm.number_room);
    }
}

int main(int argc, char **argv)
{
    char *mask = "^[0-9][0-9]->[0-9][0-9]->[0-9][0-9][0-9][0-9]$";
    FILE *f_in = fopen(argv[1], "r");
    printf("Введите количество студентов: ");
    int counter;
    int code_return;

    if (scanf("%d", &counter) != 1)
        return 1;

    describtion_t array[40];
    
    for (int i = 0; i < counter; i++)
        if ((code_return = read_one_record(array, f_in, mask, i)))
            return code_return;

    for (int i = 0; i < counter; i++)
        print_one_record(array, i);

    return EXIT_SUCCESS;
}
