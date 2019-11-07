/*
** EPITECH PROJECT, 2018
** get_at_string.c
** File description:
** get at string
*/

#include "string.h"

char get_at_string(STRING string, size_t index)
{
    if (string->string_size > index) {
        return (string->string[index]);
    } else {
        return (0);
    }
}
