/*
** EPITECH PROJECT, 2018
** hash_map_id.c
** File description:
** hash map id
*/

#include "map.h"

__attribute__ ((const)) size_t hash_map_id(void *id)
{
    size_t hash = 0;

    if ((long)id < INT_MAX && (long)id > INT_MIN)
        return ((long)id);
    for (size_t index = 0; ((unsigned char *)id)[index]; index++)
        hash += (((unsigned char *)id)[index] * (index + 1)) + hash % 2;
    return (hash);
}
