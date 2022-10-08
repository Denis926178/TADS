#include "../inc/print.h"

void header_keys()
{
    printf("|---------------|\n");
    printf("| № |  Возраст  |\n");
    printf("|---------------|\n");
}

void footer_keys()
{
    printf("|---------------|\n");
}

void print_record_key(keys_t key)
{
    printf("|%3d|%11d|\n", key.index + 1, key.age);
}

int print_keys(keys_t *array, int counter)
{   
    if (counter == 0)
        ERROR_EMPTY_TABLE;

    header_keys();

    for (int i = 0; i < counter; i++)
        print_record_key(array[i]);

    footer_keys();

    return EXIT_SUCCESS;
}

void print_result(int64_t start, int64_t end)
{
    printf("%10ld тактов | %15.10lf секунд |\n", end - start, (double)(end - start)/GHZ);
}

int print_table_in_keys(describtion_t *array, int counter)
{
    printf("Введите год поступления, для которого нужно вывести информацию о студентах: ");
    int input_year;

    if (scanf("%d", &input_year) != READ_NUMBER)
        ERROR_INVALID_INPUT_YEAR;

    print_header();
    int number_records = 0;

    for (int i = 0; i < counter; i++)
        if (strcmp(array[i].type_house, "dorm") && !compare_year(array[i].entry_day, input_year))
        {
            print_one_record(array[i], i);
            number_records++;
        }

    print_footer();

    if (number_records == 0)
        printf("%sВ таблице нет студентов живущих в общежитии %d года поступления!%s\n", RED, input_year, RESET);

    return EXIT_SUCCESS;
}

void print_one_record(describtion_t array, int i)
{
    printf("|%3d|%12s|%15s|%15s|%7d|%8s|%5d|%17lf|%10s|", i + 1, array.type_house, array.surname, array.name, array.group, array.gender, array.age, array.arithmetic_mean, array.entry_day);

    if (strcmp(array.type_house, "house") == 0)
        printf("%12s|%14d|%13d|      -      |      -      |\n", array.home.house.street, array.home.house.number_house, array.home.house.number_flat);
    else
        printf("     -      |       -      |      -      |%13d|%13d|\n", array.home.dorm.number_dorm, array.home.dorm.number_room);
}

int print_table(describtion_t *array, int counter)
{
    if (counter == 0)
        ERROR_EMPTY_TABLE;

    print_header();

    for (int i = 0; i < counter; i++)
        print_one_record(array[i], i);

    print_footer();

    return EXIT_SUCCESS;
}

void print_header()
{
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| № | TYPE HOUSE |    SURNAME    |      NAME     | GROUP | GENDER | AGE | ARITHMETIC MEAN |   DATE   |   STREET   | NUMBER HOUSE | NUMBER FLAT | NUMBER DORM | NUMBER ROOM |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void print_footer()
{
    printf("|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void print_options()
{
    printf("\n1  - Загрузить таблицу из файла\n");
    printf("2  - Вывести текущую таблицу на экран\n");
    printf("3  - Добавить запись в конец таблицы\n");
    printf("4  - Удалить запись из таблицы по номеру строки\n");
    printf("5  - Вывести студентов, живующих в общежитии с годом, поступления, который укажете вы\n");
    printf("6  - отсортировать таблицу по возрасту сортировкой пузырьком\n");
    printf("7  - отсортировать таблицу по возрасту сортировкой qsort\n");
    printf("8  - отсортировать таблицу по возрасту сортировкой пузырьком с помощью таблицы ключей\n");
    printf("9  - отсортировать таблицу по возрасту сортировкой qsort с помощью таблицы ключей\n");
    printf("10 - вывести таблицу ключей\n");
    printf("11 - вывести сравнение времени сортировок\n");
    printf("0 - завершить работу программы\n\n");
}
