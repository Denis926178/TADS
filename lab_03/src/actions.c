#include "actions.h"

void multiplicate_matrix(str_matrix_t str, matrix_full_t mtr, str_matrix_t *res, clock_t *res_time)
{
    clock_t start, end;
    start = clock();
    for (int k = 0; k < mtr.m; k++)
    {
        int el = 0;
        for (int j = 0; j < str.n; j++)
            el += str.mtr[j] * mtr.mtr[j][k];
        res->mtr[k] = el;
    }
    end = clock();
    *res_time = (end - start);
}

void multiplicate_sparse(sparse_matrix_t str, sparse_matrix_t mtr, sparse_matrix_t *res_sparse, clock_t *res_time)
{
    if (!str.n_zero)
        return;
    
    res_sparse->col = 0;
    int k = 0;
    int h = 1;
    int flag = 0;

    clock_t start, end;

    start = clock();

    for(int i = 0; i < mtr.col; i++)
    {
        flag = 0;
        for(int j = mtr.JA[i]; j < mtr.JA[i + 1]; j++)
        {
            if(str.JA[mtr.IA[j] + 1] - str.JA[mtr.IA[j]] != 0)
            {
                res_sparse->A[res_sparse->col] += str.A[str.JA[mtr.IA[j]]] * mtr.A[j];
                flag = 1;
                res_sparse->n_zero++;
            }
        }
        if (flag)
        {
            res_sparse->col++;
            res_sparse->JA[h] = res_sparse->JA[h - 1] + 1;
        }
        else
            res_sparse->JA[h] = res_sparse->JA[h- 1];
        k++;
        h++;
    }
    end = clock();
    *res_time = (end - start);
}

