/*
** EPITECH PROJECT, 2018
** clean_map.c
** File description:
** clean_map Functions
*/

#include "map.h"

bool check_table_doublon(table_t *table)
{
    void *id = table->id;

    table = table->prev;
    while (table) {
        if (table && cmp_map_id(table->id, id))
            return (true);
        table = table->prev;
    }
    return (false);
}

void clean_table_line(MAP map, size_t line, table_t *table)
{
    void *table_tmp;

    while (table) {
        if (check_table_doublon(table) == true) {
            unlink_map(map, line, table);
            table_tmp = table->next;
            free(table);
            table = table_tmp;
        } else
            table = table->next;
    }
}

void clean_map(MAP map)
{
    size_t line = 0;

    while (++line != map->table_size) {
        clean_table_line(map, line, map->table[line]);
    }
}
