/*
** EPITECH PROJECT, 2018
** get_map_size.c
** File description:
** get_map_size Functions
*/

#include "map.h"

size_t size_map(MAP map)
{
    size_t size = 0;
    table_t *tmp;

    for (size_t index = 0; index != map->table_size; index++)
        for (tmp = map->table[index]; tmp; tmp = tmp->next)
            size++;
    return (size);
}
