/*
** EPITECH PROJECT, 2018
** remove_map.c
** File description:
** remove_map Functions
*/

#include "map.h"

void unlink_map(MAP map, size_t hash, table_t *table)
{
    if (table->next)
        table->next->prev = table->prev;
    if (table->prev)
        table->prev->next = table->next;
    else
        map->table[hash] = NULL;
}

void remove_map(MAP map, void *id)
{
    table_t *tmp;
    size_t hash = hash_map_id(id) % map->table_size;
    table_t *table = map->table[hash];

    while (table) {
        if (table && table->id && cmp_map_id(table->id, id)) {
            unlink_map(map, hash, table);
            tmp = table->next;
            free(table);
            table = tmp;
        } else
            table = table->next;
    }
}
