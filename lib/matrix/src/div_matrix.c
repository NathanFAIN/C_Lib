/*
** EPITECH PROJECT, 2018
** div_matrix.c
** File description:
** div matrix
*/

#include "matrix.h"

MATRIX div_matrix(MATRIX mat, long double nb)
{
    MATRIX ans = create_matrix(mat.size, NULL);

    for (size_t index_y = 0; index_y != ans.size; index_y++)
        for (size_t index_x = 0; index_x != ans.size; index_x++)
            ans.tab[index_y][index_x] = mat.tab[index_y][index_x] / nb;
    return (ans);
}
