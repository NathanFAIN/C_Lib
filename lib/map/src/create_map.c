/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** create map
*/

#include "map.h"

MAP create_map(size_t map_size, bool recycle)
{
    MAP new_map = malloc(sizeof(map_t));

    new_map->table_size = map_size;
    new_map->is_recycle = recycle;
    new_map->table = calloc(map_size, sizeof(table_t *));
    return (new_map);
}
