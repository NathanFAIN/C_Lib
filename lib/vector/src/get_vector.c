/*
** EPITECH PROJECT, 2018
** get_vector.c
** File description:
** get_vector Functions
*/

#include "vector.h"

data_vector_t get_vector(VECT vector, void *id)
{
    size_t hash;
    table_t *tmp;

    hash = hash_vector_id(id) % vector->table_size;
    if (vector->table[hash] != NULL) {
        for (tmp = vector->table[hash]; tmp->next != NULL && \
        !cmp_vector_id(tmp->id, id); tmp = tmp->next);
        if (cmp_vector_id(tmp->id, id))
            return (tmp->data);
        else
            return ((data_vector_t) {0});
    } else
        return ((data_vector_t) {0});
}
