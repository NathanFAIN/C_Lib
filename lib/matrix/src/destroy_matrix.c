/*
** EPITECH PROJECT, 2018
** create_matrix.c
** File description:
** create matrix
*/

#include "matrix.h"

void destroy_matrix(MATRIX matrix)
{
    for (size_t index = 0; index != matrix.size; index++)
        free(matrix.value[index]);
    free(matrix.value);
}
