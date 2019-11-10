/*
** EPITECH PROJECT, 2018
** mul_matrix.c
** File description:
** mul matrix
*/

#include "matrix.h"

long double mul_matrix_bis(MATRIX matrix1, MATRIX matrix2, \
size_t index_x, size_t index_y)
{
    long double nb = 0;

    for (size_t index = 0; index != matrix1.size; index++)
        nb += matrix1.value[index][index_x] * matrix2.value[index_y][index];
    return (nb);
}

MATRIX mul_matrix(MATRIX matrix1, MATRIX matrix2)
{
    MATRIX ans = create_matrix(matrix1.size, NULL);

    for (size_t index_y = 0; index_y != matrix1.size; index_y++)
        for (size_t index_x = 0; index_x != matrix1.size; index_x++)
            ans.value[index_y][index_x] = \
            mul_matrix_bis(matrix1, matrix2, index_x, index_y);
    return (ans);
}
