#include "menu.h"

int main(void)
{
    setbuf(stdout, NULL);
    print_rules();

    int key, flag = 1, return_code = 0;
    matrix_full_t mtr;
    sparse_matrix_t mtr_spr, res_spr, str_spr;
    str_matrix_t str, res;

    int flag_matrix = 0;
    int flag_str = 0;
    int flag_mult = 0;
    int flag_mult_spr = 0;
    int flag_compare = 0;

    clock_t res_time = 0;
    clock_t res_time_spr = 0;


    while(flag)
    {
        print_menu();
        printf("Выберите пункт меню: ");
        if(scanf("%d", &key) != 1 || key > 9 || key < 0) 
        {   
            printf("Неверный параметр меню.\n");
            return ERROR_KEY;
        }

        if (key == 0)
        {
            if (flag_str)
            {
                free_arr(mtr_spr.IA);
                free_arr(mtr_spr.JA);
                free_arr(mtr_spr.A);
            }
            if (flag_matrix)
            {
                free_matrix(mtr.mtr);
            }
            printf("Программма успешно завершена по вашему желанию.\n");
            return EXIT_SUCCESS;
        }

        if(key == 9)
        {
            flag_compare = 1;
            return_code = do_actions(7, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, 
        &flag_matrix, &flag_str, &flag_mult, &flag_mult_spr, &res_time, &res_time_spr, flag_compare);
            if(!return_code)
                return_code = do_actions(8, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, 
        &flag_matrix, &flag_str, &flag_mult, &flag_mult_spr, &res_time, &res_time_spr, flag_compare);
            flag_compare = 0;
        }
                
        return_code = do_actions(key, &mtr, &mtr_spr, &str, &str_spr, &res, &res_spr, 
        &flag_matrix, &flag_str, &flag_mult, &flag_mult_spr, &res_time, &res_time_spr, flag_compare);

    }
 
    return return_code;
}
