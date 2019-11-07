/*
** EPITECH PROJECT, 2018
** create_matrix.c
** File description:
** create matrix
*/

#include "matrix.h"

MATRIX copy_matrix(MATRIX matrix)
{
    MATRIX new_matrix = create_matrix(matrix.size, NULL);

    for (size_t index_y = 0; index_y != matrix.size; index_y++)
        for (size_t index_x = 0; index_x != matrix.size; index_x++)
            new_matrix.tab[index_y][index_x] = matrix.tab[index_y][index_x];
    return (new_matrix);
}
