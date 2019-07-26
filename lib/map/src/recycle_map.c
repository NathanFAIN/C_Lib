/*
** EPITECH PROJECT, 2018
** recycle_map.c
** File description:
** recycle map
*/

#include "map.h"

void recycle_map(MAP *map)
{
    if (*map != NULL && (*map)->is_recycle == true)
        destroy_map(map);
}

void set_recycle_map(MAP map, bool recycle)
{
    map->is_recycle = recycle;
}
