#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_SIZE_ARRAY                  500
#define MAX_SIZE_SURNAME                15
#define MAX_SIZE_NAME                   15
#define MAX_SIZE_TYPE_HOUSE             6
#define MAX_SIZE_GENDER                 1
#define MAX_SIZE_ENTRY_DAY              10
#define MAX_SIZE_STREET                 12
#define MAX_SIZE_FILENAME               30

#define READ_NUMBER                     1

#define ERROR_INVALID_TYPE_HOUSE        101
#define ERROR_INVALID_SURNAME           102
#define ERROR_INVALID_NAME              103
#define ERROR_INVALID_GROUP             104
#define ERROR_INVALID_GENDER            105
#define ERROR_INVALID_AGE               106
#define ERROR_INVALID_ARITHMETIC_MEAN   107
#define ERROR_INVALID_ENTRY_DAY         108
#define ERROR_INVALID_STREET            109
#define ERROR_INVALID_NUMBER_HOUSE      110
#define ERROR_INVALID_NUMBER_FLAT       111
#define ERROR_INVALID_NUMBER_DORM       112
#define ERROR_INVALID_NUMBER_ROOM       113
#define ERROR_INVALID_INPUT_YEAR        114

#define ERROR_NAME_FILE                 { printf("Введено неверное имя файла!\n"); return 1; }
#define ERROR_STRUCT_FILE               { printf("При чтении файла возникла ошибка\n"); fclose(f_in); return code_return; }
#define ERROR_INPUT_NUMBER_STRING       { printf("Был введен неверный номер строки.\n"); return 3; }

typedef struct house_t
{
    char street[12];
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
    char type_house[MAX_SIZE_TYPE_HOUSE];
    char surname[MAX_SIZE_SURNAME];
    char name[MAX_SIZE_NAME];
    int group;
    char gender[MAX_SIZE_GENDER];
    int age;
    double arithmetic_mean;
    char entry_day[MAX_SIZE_ENTRY_DAY];
    choose_type_t home;
} describtion_t;

void print_options();
int select_option(int *mode);
int read_one_record(describtion_t *array, FILE *f_in, int flag);
void print_header();
void print_footer();
void print_table(describtion_t *array, int counter);
void print_one_record(describtion_t array, int i);
int make_table(describtion_t *array, int *counter);
int add_record(describtion_t *array, int *counter);
int delete_record(describtion_t *array, int *counter);
int compare_year(char *date, int input_year);

void print_options()
{
    printf("1 - Загрузить таблицу из файла\n");
    printf("2 - Вывести текущую таблицу на экран\n");
    printf("3 - Добавить запись в конец таблицы\n");
    printf("4 - Удалить запись из таблицы по номеру строки\n");
    printf("5 - Вывести студентов, живующих в общежитии с годом, поступления, который укажете вы\n");
    printf("6 - отсортировать таблицу по возрасту\n");
    printf("7 - вывести сравнение времени сортировок\n");
    printf("0 - завершить работу программы\n\n");
}

int select_mode(int *mode)
{
    printf("Введите номер действия: ");

    if (scanf("%d", mode) != READ_NUMBER)
        return 1;

    if (*mode < 0 || *mode > 7)
        return 2;

    printf("\n");
    return EXIT_SUCCESS;
}

int valid_date(char *date)
{
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '\0') * 10 + (date[9] - '\0');

    int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int legit = 0;

    if (year % 4 == 0)
        daysinmonth[1] = 29;
   
    if (month < 13)
    {
        if( day <= daysinmonth[month - 1] )
            legit = 1;
    }

    if (legit == 1)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int read_one_record(describtion_t *array, FILE *f_in, int flag)
{
    char *mask = "^[0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9]$";

    if (flag) printf("\nВведите тип жилья (латинскими буквами house - дом, dorm - общежитиие): ");
    if (fscanf(f_in, "%s", array->type_house) != READ_NUMBER && (strcmp(array->type_house, "house") == 0 || strcmp(array->type_house, "dorm")) == 0)
        return ERROR_INVALID_TYPE_HOUSE;
    if (flag) printf("\nВведите фамилию (латинскими буквами): ");
    if (fscanf(f_in, "%s", array->surname) != READ_NUMBER)
        return ERROR_INVALID_SURNAME;
    if (flag) printf("\nВведите имя (латинсиким буквами): ");
    if (fscanf(f_in, "%s", array->name) != READ_NUMBER)
        return ERROR_INVALID_NAME;
    if (flag) printf("\nВведите группу (натуральное число): ");
    if (fscanf(f_in, "%d", &array->group) != READ_NUMBER)
        return ERROR_INVALID_GROUP;
    if (flag) printf("\nВведите пол (латинскими буквами, m - мужской пол, f - женский пол): ");
    if (fscanf(f_in, "%s", array->gender) != READ_NUMBER && (strcmp(array->gender, "m") == 0 || strcmp(array->gender, "f") == 0))
        return ERROR_INVALID_GENDER;
    if (flag) printf("\nВведите возвраст (натуральное число): ");
    if (fscanf(f_in, "%d", &array->age) != READ_NUMBER)
        return ERROR_INVALID_AGE;
    if (flag) printf("\nВведите средний балл за сессию (неотрицательное вещественное число): ");
    if (fscanf(f_in, "%lf", &array->arithmetic_mean) != READ_NUMBER)
        return ERROR_INVALID_ARITHMETIC_MEAN;
    if (flag) printf("\nВведите дату поступления (в формате dd.mm.yyyy, каждая буква - цифра от 0 до 9): ");
    if (fscanf(f_in, "%s", array->entry_day) != READ_NUMBER)
    {
        return ERROR_INVALID_ENTRY_DAY;
    }
    else
    {
        regex_t regex;
        int code_return = regcomp(&regex, mask, REG_EXTENDED);

        if (code_return)
            return ERROR_INVALID_ENTRY_DAY;
        if (code_return = regexec(&regex, array->entry_day, 0, NULL, 0))
            return ERROR_INVALID_ENTRY_DAY;
        if (code_return = valid_date(array->entry_day))
            return ERROR_INVALID_ENTRY_DAY;
    }
        
    if (strcmp(array->type_house, "house") == 0)
    {
        if (flag) printf("\nВведите улицу: ");
        if (fscanf(f_in, "%s", array->home.house.street) != READ_NUMBER)
            return ERROR_INVALID_STREET;
        if (flag) printf("\nВведите номер дома: ");
        if (fscanf(f_in, "%d", &array->home.house.number_house) != READ_NUMBER)
            return ERROR_INVALID_NUMBER_HOUSE;
        if (flag) printf("\nВведите номер квартиры: ");
        if (fscanf(f_in, "%d", &array->home.house.number_flat) != READ_NUMBER)
            return ERROR_INVALID_NUMBER_FLAT;
    }
    else
    {
        if (flag) printf("\nВведите номер общежития: ");
        if (fscanf(f_in, "%d", &array->home.dorm.number_dorm) != READ_NUMBER)
            return ERROR_INVALID_NUMBER_DORM;
        if (flag) printf("\nВведите номер комнаты: ");
        if (fscanf(f_in, "%d", &array->home.dorm.number_room) != READ_NUMBER)
            return ERROR_INVALID_NUMBER_ROOM;
    }
    
    return EXIT_SUCCESS;
}

void print_header()
{
    printf("|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| TYPE HOUSE |    SURNAME    |      NAME     | GROUP | GENDER | AGE | ARITHMETIC MEAN |   DATE   |   STREET   | NUMBER HOUSE | NUMBER FLAT | NUMBER DORM | NUMBER ROOM |\n");
    printf("|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void print_footer()
{
    printf("|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}


void print_table(describtion_t *array, int counter)
{
    print_header();

    for (int i = 0; i < counter; i++)
        print_one_record(array[i], i);

    print_footer();
}

void print_one_record(describtion_t array, int i)
{
    printf("|%12s|%15s|%15s|%7d|%8s|%5d|%17lf|%10s|", array.type_house, array.surname, array.name, array.group, array.gender, array.age, array.arithmetic_mean, array.entry_day);

    if (strcmp(array.type_house, "house") == 0)
        printf("%12s|%14d|%13d|      -      |      -      |\n", array.home.house.street, array.home.house.number_house, array.home.house.number_flat);
    else
        printf("     -      |       -      |      -      |%13d|%13d|\n", array.home.dorm.number_dorm, array.home.dorm.number_room);;
}

int make_table(describtion_t *array, int *counter)
{
    printf("Напишите называние файла, из которого нужно считать данные в таблицу.\n");
    char filename[MAX_SIZE_FILENAME];

    if (scanf("%s", filename) != 1)
        return 1;

    FILE *f_in = fopen(filename, "r");

    if (f_in == NULL)
        ERROR_NAME_FILE;

    if (fscanf(f_in, "%d", counter) != 1)
        return 1;

    int code_return;
    for (int i = 0; i < *counter; i++)
        if ((code_return = read_one_record(&array[i], f_in, 0)))
            ERROR_STRUCT_FILE;

    return EXIT_SUCCESS;
}

int add_record(describtion_t *array, int *counter)
{
    int code_return = read_one_record(&array[*counter + 1], stdin, 1);

    if (code_return)
        return code_return;

    (*counter)++;
    return EXIT_SUCCESS;
}

int delete_record(describtion_t *array, int *counter)
{
    printf("Введите номер строчки таблицы, которую нужно удалить.\n");

    int number_string;
    if (scanf("%d", &number_string) != READ_NUMBER)
        return 1;

    number_string--;

    if (number_string > *counter)
        ERROR_INPUT_NUMBER_STRING;

    for (int i = number_string; i < *counter; i++)
        array[i] = array[i + 1];

    (*counter)--;
    return EXIT_SUCCESS;
}

int compare_year(char *date, int input_year)
{
    int table_year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    if (input_year == table_year)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int print_table_in_keys(describtion_t *array, int counter)
{   
    printf("Введите год поступления, для которого нужно вывести информацию о студентах: ");
    int input_year;

    if (scanf("%d", &input_year) != READ_NUMBER)
        return ERROR_INVALID_INPUT_YEAR;

    print_header();

    for (int i = 0; i < counter; i++)
        if (strcmp(array[i].type_house, "dorm") && !compare_year(array[i].entry_day, input_year))
            print_one_record(array[i], i);

    print_footer();

    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    print_options();
    int counter, mode, code_return;
    
    if ((code_return = select_mode(&mode)))
        return code_return;

    describtion_t array[MAX_SIZE_ARRAY];

    while (mode)
    {
        switch (mode)
        {
            case 1:
                code_return = make_table(array, &counter);
                break;
            case 2:
                print_table(array, counter);
                break;
            case 3:
                code_return = add_record(array, &counter);
                break;
            case 4:
                code_return = delete_record(array, &counter);
                break;
            case 5:
                code_return = print_table_in_keys(array, counter);
            //     break;
            // case 6:
            //     sort_table_by_age();
            //     break;
            // case 7:
            //     compare_sorts();
            //    break;
            default:
                printf("Неверно введен номер действия.\n");
                break;
        }
        print_options();
        if ((code_return = select_mode(&mode)))
            return code_return;
    }

    return EXIT_SUCCESS;
}
