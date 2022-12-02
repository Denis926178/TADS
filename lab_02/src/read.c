#include "../inc/read.h"

int read_one_record(describtion_t *array, FILE *f_in, int flag)
{
    char *mask = "^[0-9][0-9].[0-9][0-9].[0-9][0-9][0-9][0-9]$";

    if (flag)
        printf("\nВведите тип жилья (латинскими буквами house - дом, dorm - общежитиие): ");
    if (fscanf(f_in, "%s", array->type_house) != READ_NUMBER && (strcmp(array->type_house, "house") == 0 || strcmp(array->type_house, "dorm")) == 0)
        ERROR_INVALID_TYPE_HOUSE;
    if (flag)
        printf("\nВведите фамилию (латинскими буквами, максимальная длина фамилии - 15 символов): ");
    if (fscanf(f_in, "%s", array->surname) != READ_NUMBER)
        ERROR_INVALID_SURNAME;
    if (flag)
        printf("\nВведите имя (латинсиким буквами, максимальная длина имени - 15 символов): ");
    if (fscanf(f_in, "%s", array->name) != READ_NUMBER)
        ERROR_INVALID_NAME;
    if (flag)
        printf("\nВведите группу (натуральное число от 1 до 100): ");
    if (fscanf(f_in, "%d", &array->group) != READ_NUMBER || (array->group < 1 || array->group > 100))
        ERROR_INVALID_GROUP;
    if (flag)
        printf("\nВведите пол (латинскими буквами, m - мужской пол, f - женский пол): ");
    if (fscanf(f_in, "%s", array->gender) != READ_NUMBER && (strcmp(array->gender, "m") == 0 || strcmp(array->gender, "f") == 0))
        ERROR_INVALID_GENDER;
    if (flag)
        printf("\nВведите возвраст (натуральное число от 1 до 100): ");
    if (fscanf(f_in, "%d", &array->age) != READ_NUMBER || (array->age < 1 || array->age > 100))
        ERROR_INVALID_AGE;
    if (flag)
        printf("\nВведите средний балл за сессию (неотрицательное вещественное число не большее 100): ");
    if (fscanf(f_in, "%lf", &array->arithmetic_mean) != READ_NUMBER || (array->arithmetic_mean < 0 || array->arithmetic_mean > 100))
        ERROR_INVALID_ARITHMETIC_MEAN;
    if (flag)
        printf("\nВведите дату поступления (в формате dd.mm.yyyy, каждая буква - цифра от 0 до 9): ");
    if (fscanf(f_in, "%s", array->entry_day) != READ_NUMBER)
    {
        ERROR_INVALID_ENTRY_DAY;
    }
    else
    {
        regex_t regex;
        int code_return = regcomp(&regex, mask, REG_EXTENDED);

        if (code_return)
            ERROR_INVALID_ENTRY_DAY;
        if ((code_return = regexec(&regex, array->entry_day, 0, NULL, 0)))
            ERROR_INVALID_ENTRY_DAY;
        if ((code_return = valid_date(array->entry_day)))
            ERROR_INVALID_ENTRY_DAY;
    }

    if (strcmp(array->type_house, "house") == 0)
    {
        if (flag)
            printf("\nВведите улицу (максимальная длина улицы - 12 символов): ");
        if (fscanf(f_in, "%s", array->home.house.street) != READ_NUMBER)
            ERROR_INVALID_STREET;
        if (flag)
            printf("\nВведите номер дома (натуральное число): ");
        if (fscanf(f_in, "%d", &array->home.house.number_house) != READ_NUMBER)
            ERROR_INVALID_NUMBER_HOUSE;
        if (flag)
            printf("\nВведите номер квартиры (натуральное число): ");
        if (fscanf(f_in, "%d", &array->home.house.number_flat) != READ_NUMBER)
            ERROR_INVALID_NUMBER_FLAT;
    }
    else
    {
        if (flag)
            printf("\nВведите номер общежития (натуральное число): ");
        if (fscanf(f_in, "%d", &array->home.dorm.number_dorm) != READ_NUMBER)
            ERROR_INVALID_NUMBER_DORM;
        if (flag)
            printf("\nВведите номер комнаты (натуральное число): ");
        if (fscanf(f_in, "%d", &array->home.dorm.number_room) != READ_NUMBER)
            ERROR_INVALID_NUMBER_ROOM;
    }

    return EXIT_SUCCESS;
}

int select_mode(int *mode)
{
    printf("%sВведите номер действия:%s ", GREEN, RESET);

    if (scanf("%d", mode) != READ_NUMBER)
        return 1;

    if (*mode < 0 || *mode >= 13)
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
        if (day <= daysinmonth[month - 1])
            legit = 1;
    }

    if (legit == 1)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
