/*
** EPITECH PROJECT, 2018
** remove_vector.c
** File description:
** remove_vector Functions
*/

#include "vector.h"

void remove_vector(VECT vector, void *id)
{
    table_t *tmp;

    for (tmp = vector->table[hash_vector_id(id) % vector->table_size]; tmp && \
    !cmp_vector_id(tmp->id, id); tmp = tmp->next);
    if (tmp && cmp_vector_id(tmp->id, id)) {
        if (tmp->next)
            tmp->next->prev = tmp->prev;
        if (tmp->prev)
            tmp->prev->next = tmp->next;
        else
            tmp = tmp->next;
    }
}
