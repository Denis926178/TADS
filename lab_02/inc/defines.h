#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>

#define RESET                       "\033[0m"
#define RED                         "\033[31m"
#define GREEN                       "\033[32m"

#define GHZ                         3700000000

#define MAX_SIZE_ARRAY              500
#define MAX_SIZE_SURNAME            15
#define MAX_SIZE_NAME               15
#define MAX_SIZE_TYPE_HOUSE         6
#define MAX_SIZE_GENDER             1
#define MAX_SIZE_ENTRY_DAY          10
#define MAX_SIZE_STREET             12
#define MAX_SIZE_FILENAME           30

#define READ_NUMBER 1

#define ERROR_INVALID_TYPE_HOUSE                               \
    {                                                          \
        printf("%sНеверно введен тип жилья!%s\n", RED, RESET); \
        return 101;                                            \
    }
#define ERROR_INVALID_SURNAME                                 \
    {                                                         \
        printf("%sНеверно введена фамилия!%s\n", RED, RESET); \
        return 102;                                           \
    }
#define ERROR_INVALID_NAME                                \
    {                                                     \
        printf("%sНеверно введено имя!%s\n", RED, RESET); \
        return 103;                                       \
    }
#define ERROR_INVALID_GROUP                                  \
    {                                                        \
        printf("%sНеверно введена группа!%s\n", RED, RESET); \
        return 104;                                          \
    }
#define ERROR_INVALID_GENDER                             \
    {                                                    \
        printf("%sНеверно введен пол!%s\n", RED, RESET); \
        return 105;                                      \
    }
#define ERROR_INVALID_AGE                                    \
    {                                                        \
        printf("%sНеверно введен возраст!%s\n", RED, RESET); \
        return 106;                                          \
    }
#define ERROR_INVALID_ARITHMETIC_MEAN                                       \
    {                                                                       \
        printf("%sНеверно введен средний балл за сессию!%s\n", RED, RESET); \
        return 107;                                                         \
    }
#define ERROR_INVALID_ENTRY_DAY                                        \
    {                                                                  \
        printf("%sНеверно введена дата поступления!%s\n", RED, RESET); \
        return 108;                                                    \
    }
#define ERROR_INVALID_STREET                                          \
    {                                                                 \
        printf("%sНеверно введено называние улицы!%s\n", RED, RESET); \
        return 109;                                                   \
    }
#define ERROR_INVALID_NUMBER_HOUSE                              \
    {                                                           \
        printf("%sНеверно введен номер дома!%s\n", RED, RESET); \
        return 110;                                             \
    }
#define ERROR_INVALID_NUMBER_FLAT                                   \
    {                                                               \
        printf("%sНеверно введен номер квартиры!%s\n", RED, RESET); \
        return 111;                                                 \
    }
#define ERROR_INVALID_NUMBER_DORM                                    \
    {                                                                \
        printf("%sНеверно введен номер общежития!%s\n", RED, RESET); \
        return 112;                                                  \
    }
#define ERROR_INVALID_NUMBER_ROOM                                  \
    {                                                              \
        printf("%sНеверно введен номер комнаты!%s\n", RED, RESET); \
        return 113;                                                \
    }
#define ERROR_INVALID_INPUT_YEAR                                     \
    {                                                                \
        printf("%sНеверно введен год поступления!%s\n", RED, RESET); \
        return 114;                                                  \
    }
#define ERROR_TOO_LARGE_RECORDS                                                              \
    {                                                                                        \
        printf("%sВ таблице содержится максимальное количество записей!!!%s\n", RED, RESET); \
        return 115;                                                                          \
    }

#define ERROR_NAME_FILE                                          \
    {                                                            \
        printf("%sВведено неверное имя файла!%s\n", RED, RESET); \
        return 1;                                                \
    }
#define ERROR_STRUCT_FILE                                              \
    {                                                                  \
        printf("%sПри чтении файла возникла ошибка!%s\n", RED, RESET); \
        fclose(f_in);                                                  \
        return code_return;                                            \
    }
#define ERROR_INPUT_NUMBER_STRING                                      \
    {                                                                  \
        printf("%sБыл введен неверный номер строки!%s\n", RED, RESET); \
        return 3;                                                      \
    }
#define ERROR_EMPTY_TABLE                                                                                      \
    {                                                                                                          \
        printf("%sТаблица не заполнена, чтобы вывести таблицу, выгрузите данные из файла!!!%s\n", RED, RESET); \
        return 200;                                                                                            \
    }

#endif
