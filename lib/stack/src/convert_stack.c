/*
** EPITECH PROJECT, 2018
** stack_convert.c
** File description:
** stack convert
*/

#include "stack.h"

data_stack_t unknown_strcut_to_data_stack(size_t size, void *ptr)
{
    data_stack_t data = {0};

    memset(data.bytes + size, 0, sizeof(data.bytes) - size);
    memcpy(data.bytes, ptr, size);
    return (data);
}
