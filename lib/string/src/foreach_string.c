/*
** EPITECH PROJECT, 2018
** foreach_string.c
** File description:
** foreach string
*/

#include "string.h"

void foreach_string(STRING string, void (*foreach_func)(char *))
{
    for (size_t index = 0; index != string->string_size; index++) {
        foreach_func(&string->string[index]);
    }
}
