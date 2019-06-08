/*
** EPITECH PROJECT, 2018
** create_table.c
** File description:
** create table
*/

#include "vector.h"

table_t *create_table(void *id, data_vector_t data)
{
    table_t *new = malloc(sizeof(table_t));

    new->id = id;
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}
