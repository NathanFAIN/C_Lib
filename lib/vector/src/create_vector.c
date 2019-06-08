/*
** EPITECH PROJECT, 2018
** create_vector.c
** File description:
** create vector
*/

#include "vector.h"

VECT create_vector(size_t vector_size)
{
    VECT new_vector = malloc(sizeof(vector_t));

    new_vector->table_size = vector_size;
    new_vector->is_recycle = false;
    new_vector->table = calloc(vector_size, sizeof(table_t *));
    return (new_vector);
}
