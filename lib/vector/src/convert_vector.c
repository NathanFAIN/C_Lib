/*
** EPITECH PROJECT, 2018
** vector_convert.c
** File description:
** vector convert
*/

#include "vector.h"

data_vector_t unknown_strcut_to_data_vector(size_t size, void *ptr)
{
    data_vector_t data = {0};

    memset(data.bytes + size, 0, sizeof(data.bytes) - size);
    memcpy(data.bytes, ptr, size);
    return (data);
}
