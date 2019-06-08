/*
** EPITECH PROJECT, 2018
** get_all_vector.c
** File description:
** get_all_vector Functions
*/

#include "vector.h"

data_vector_t *getall_vector(VECT vector)
{
    data_vector_t *data;
    size_t size = 0;
    size_t index = 0;
    table_t *tmp;

    while (index != vector->table_size)
        for (tmp = vector->table[index++]; tmp; tmp = tmp->next)
            size++;
    data = calloc(size + 1, sizeof(data_vector_t));
    size = 0;
    index = 0;
    while (index != vector->table_size)
        for (tmp = vector->table[index++]; tmp; tmp = tmp->next) {
            data[size] = tmp->data;
            size++;
        }
    return (data);
}
