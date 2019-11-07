/*
** EPITECH PROJECT, 2018
** replace_at_string.c
** File description:
** replace_at string
*/

#include "string.h"

void replace_at_string(STRING string, size_t index, char c)
{
    if (string->string_size > index) {
        string->string[index] = c;
    }
}
