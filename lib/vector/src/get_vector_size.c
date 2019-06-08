/*
** EPITECH PROJECT, 2018
** get_vector_size.c
** File description:
** get_vector_size Functions
*/

#include "vector.h"

size_t size_vector(VECT vector)
{
    size_t size = 0;
    table_t *tmp;

    for (size_t index = 0; index != vector->table_size; index++)
        for (tmp = vector->table[index]; tmp; tmp = tmp->next)
            size++;
    return (size);
}
