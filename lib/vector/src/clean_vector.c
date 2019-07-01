/*
** EPITECH PROJECT, 2018
** clean_vector.c
** File description:
** clean_vector Functions
*/

#include "vector.h"

bool check_table_doublon(table_t *table)
{
    void *id = table->id;

    table = table->prev;
    while (table) {
        if (table && cmp_vector_id(table->id, id))
            return (true);
        table = table->prev;
    }
    return (false);
}

void clean_table_line(VECT vector, size_t line, table_t *table)
{
    void *table_tmp;

    while (table) {
        if (check_table_doublon(table) == true) {
            unlink_vector(vector, line, table);
            table_tmp = table->next;
            free(table);
            table = table_tmp;
        } else
            table = table->next;
    }
}

void clean_vector(VECT vector)
{
    size_t line = 0;

    while (++line != vector->table_size) {
        clean_table_line(vector, line, vector->table[line]);
    }
}
