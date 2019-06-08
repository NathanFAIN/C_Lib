/*
** EPITECH PROJECT, 2018
** add_vector.c
** File description:
** add_vector Functions
*/

#include "vector.h"

void add_vector(VECT vector, void *id, data_vector_t data)
{
    size_t hash;
    table_t *tmp;

    hash = hash_vector_id(id) % vector->table_size;
    if (vector->table[hash] != NULL) {
        for (tmp = vector->table[hash]; tmp->next && \
        !cmp_vector_id(tmp->id, id); tmp = tmp->next);
        if (cmp_vector_id(tmp->id, id))
            tmp->data = data;
        else {
            tmp->next = create_table(id, data);
            tmp->next->prev = tmp;
        }
    } else
        vector->table[hash] = create_table(id, data);
}
