/*
** EPITECH PROJECT, 2018
** get_map.c
** File description:
** get_map Functions
*/

#include "map.h"

data_map_t get_map(MAP map, void *id)
{
    size_t hash;
    table_t *tmp;

    hash = hash_map_id(id) % map->table_size;
    if (map->table[hash] != NULL) {
        for (tmp = map->table[hash]; tmp->next != NULL && \
        !cmp_map_id(tmp->id, id); tmp = tmp->next);
        if (cmp_map_id(tmp->id, id))
            return (tmp->data);
        else
            return ((data_map_t) {0});
    } else
        return ((data_map_t) {0});
}
