/*
** EPITECH PROJECT, 2018
** remove_vector.c
** File description:
** remove_vector Functions
*/

#include "vector.h"

void unlink_vector(VECT vector, size_t hash, table_t *table)
{
    if (table->next)
        table->next->prev = table->prev;
    if (table->prev)
        table->prev->next = table->next;
    else
        vector->table[hash] = NULL;
}

void remove_vector(VECT vector, void *id)
{
    table_t *tmp;
    size_t hash = hash_vector_id(id) % vector->table_size;
    table_t *table = vector->table[hash];

    while (table) {
        if (table && table->id && cmp_vector_id(table->id, id)) {
            unlink_vector(vector, hash, table);
            tmp = table->next;
            free(table);
            table = tmp;
        } else
            table = table->next;
    }
}
