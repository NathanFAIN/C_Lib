/*
** EPITECH PROJECT, 2018
** insert_at_string.c
** File description:
** insert at string
*/

#include "string.h"

void insert_at_string(STRING string, size_t index, STRING string_bis)
{
    char *new_string;

    if (string->string_size + string_bis->string_size != 0) {
        new_string = malloc(sizeof(char) * \
        (string->string_size + string_bis->string_size + 1));
        new_string[string->string_size + string_bis->string_size] = '\0';
    }
    (void) index;
}
