/*
** EPITECH PROJECT, 2018
** sub_matrix.c
** File description:
** sub matrix
*/

#include "matrix.h"

MATRIX matrix_sub(MATRIX matrix1, MATRIX matrix2)
{
    MATRIX ans = create_matrix(matrix1.size, NULL);

    for (size_t index_y = 0; index_y < ans.size; index_y++)
        for (size_t index_x = 0; index_x < ans.size; index_x++)
            ans.tab[index_y][index_x] = matrix1.tab[index_y][index_x] \
            - matrix2.tab[index_y][index_x];
    return (ans);
}
