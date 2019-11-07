/*
** EPITECH PROJECT, 2018
** create_matrix.c
** File description:
** create matrix
*/

#include "matrix.h"

MATRIX create_matrix(size_t size, void *ptr)
{
    MATRIX matrix;

    (void)ptr;
    matrix.size = size;
    matrix.tab = malloc(sizeof(long double *) * size);
    for (size_t index_x = 0; index_x != size; index_x++) {
        matrix.tab[index_x] = calloc(0, sizeof(long double) * size);
    }
    return (matrix);
}
