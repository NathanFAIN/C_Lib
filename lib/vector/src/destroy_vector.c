/*
** EPITECH PROJECT, 2018
** destroy_vector.c
** File description:
** destroy vector
*/

#include "vector.h"

void destroy_vector(VECT vector)
{
    table_t *tmp;

    for (size_t index = 0; index != vector->table_size; index++) {
        for (tmp = vector->table[index]; tmp && tmp->next; tmp = tmp->next);
        for (tmp = tmp ? tmp->prev : tmp; tmp; tmp = tmp->prev)
            free(tmp->next);
        if (vector->table[index])
            free(vector->table[index]);
    }
    free(vector->table);
    free(vector);
}
