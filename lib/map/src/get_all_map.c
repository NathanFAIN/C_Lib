/*
** EPITECH PROJECT, 2018
** get_all_map.c
** File description:
** get_all_map Functions
*/

#include "map.h"

data_map_t *getall_map(MAP map)
{
    data_map_t *data;
    size_t size = 0;
    size_t index = 0;
    table_t *tmp;

    while (index != map->table_size)
        for (tmp = map->table[index++]; tmp; tmp = tmp->next)
            size++;
    data = calloc(size + 1, sizeof(data_map_t));
    size = 0;
    index = 0;
    while (index != map->table_size)
        for (tmp = map->table[index++]; tmp; tmp = tmp->next) {
            data[size] = tmp->data;
            size++;
        }
    return (data);
}
