/*
** EPITECH PROJECT, 2018
** add_vector.c
** File description:
** add_vector Functions
*/

#include "vector.h"

void add_vector(VECT vector, void *id, data_vector_t data)
{
    table_t *table;
    size_t hash = hash_vector_id(id) % vector->table_size;

    table = vector->table[hash];
    vector->table[hash] = create_table(id, data);
    vector->table[hash]->next = table;
    if (table)
        table->prev = vector->table[hash];
}
