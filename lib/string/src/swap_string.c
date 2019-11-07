/*
** EPITECH PROJECT, 2018
** swap_string.c
** File description:
** swap string
*/

#include "string.h"

void swap_string(STRING string)
{
    char swap;

    if (string->string_size > 2) {
        swap = string->string[0];
        string->string[0] = string->string[1];
        string->string[1] = swap;
    }
}
