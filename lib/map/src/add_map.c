/*
** EPITECH PROJECT, 2018
** add_map.c
** File description:
** add_map Functions
*/

#include "map.h"

void add_map(MAP map, void *id, data_map_t data)
{
    table_t *table;
    size_t hash = hash_map_id(id) % map->table_size;

    table = map->table[hash];
    map->table[hash] = create_table(id, data);
    map->table[hash]->next = table;
    if (table)
        table->prev = map->table[hash];
}
