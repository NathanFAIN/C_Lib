/*
** EPITECH PROJECT, 2018
** swap_at_string.c
** File description:
** swap at string
*/

#include "string.h"

void swap_at_string(STRING string, size_t index)
{
    char swap;

    if (string->string_size > index + 1) {
        swap = string->string[index];
        string->string[index] = string->string[index + 1];
        string->string[index + 1] = swap;
    }
}
