/*
** EPITECH PROJECT, 2018
** create_matrix.c
** File description:
** create matrix
*/

#include "matrix.h"

MATRIX create_matrix(size_t size, long double *value)
{
    MATRIX matrix;

    matrix.size = size;
    matrix.value = malloc(sizeof(long double *) * size);
    for (size_t index_y = 0; index_y != matrix.size; index_y++) {
        matrix.value[index_y] = calloc(0, sizeof(long double) * size);
        for (size_t index_x = 0; index_x != matrix.size; index_x++) {
            matrix.value[index_y][index_x] = \
            value[index_y * matrix.size + index_x];
        }
    }
    return (matrix);
}
