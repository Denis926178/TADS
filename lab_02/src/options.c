#include "../inc/options.h"

int make_table(describtion_t *array, int *counter)
{
    printf("Напишите называние файла, из которого нужно считать данные в таблицу: ");
    char filename[MAX_SIZE_FILENAME];

    if (scanf("%s", filename) != 1)
        return 1;

    printf("\n");

    FILE *f_in = fopen(filename, "r");

    if (f_in == NULL)
        ERROR_NAME_FILE;

    if (fscanf(f_in, "%d", counter) != 1)
        return 1;

    int code_return;
    for (int i = 0; i < *counter; i++)
        if ((code_return = read_one_record(&array[i], f_in, 0)))
            ERROR_STRUCT_FILE;

    printf("%sТаблица из файла успешно считана!%s\n", GREEN, RESET);
    return EXIT_SUCCESS;
}

int add_record(describtion_t *array, int *counter)
{
    if (*counter > MAX_SIZE_ARRAY - 1)
        ERROR_TOO_LARGE_RECORDS;

    int code_return = read_one_record(&array[*counter + 1], stdin, 1);

    if (code_return)
        return code_return;

    (*counter)++;
    printf("%sЗапись успешно добавлена в таблицу!%s\n", GREEN, RESET);
    return EXIT_SUCCESS;
}

int delete_record(describtion_t *array, int *counter)
{
    printf("Введите номер группы для которой надо удалить записи из таблицы: ");

    int number_group;
    if (scanf("%d", &number_group) != READ_NUMBER)
        return 1;

    printf("\n");

    for (int j = 0; j < *counter; j++)
        if (array[j].group == number_group)
        {
            for (int i = j; i < *counter; i++)
                array[i] = array[i + 1];
        j--;
        (*counter)--;
        }

    printf("%sЗаписи успешно удалены из таблицы!%s\n", GREEN, RESET);
    return EXIT_SUCCESS;
}

int compare_year(char *date, int input_year)
{
    int table_year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    if (input_year == table_year)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
