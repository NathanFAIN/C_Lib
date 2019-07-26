/*
** EPITECH PROJECT, 2018
** destroy_map.c
** File description:
** destroy map
*/

#include "map.h"

void destroy_map(MAP *map)
{
    table_t *tmp;

    if ((*map) == NULL)
        return;
    for (size_t index = 0; index != (*map)->table_size; index++) {
        for (tmp = (*map)->table[index]; tmp && tmp->next; tmp = tmp->next);
        for (tmp = tmp ? tmp->prev : tmp; tmp; tmp = tmp->prev)
            free(tmp->next);
        if ((*map)->table[index])
            free((*map)->table[index]);
    }
    free((*map)->table);
    free((*map));
    *map = NULL;
}
