/*
** EPITECH PROJECT, 2018
** map_convert.c
** File description:
** map convert
*/

#include "map.h"

data_map_t unknown_strcut_to_data_map(size_t size, void *ptr)
{
    data_map_t data = {0};

    memset(data.bytes + size, 0, sizeof(data.bytes) - size);
    memcpy(data.bytes, ptr, size);
    return (data);
}
