/*
** EPITECH PROJECT, 2018
** clear_string.c
** File description:
** clear string
*/

#include "string.h"

void clear_string(STRING string)
{
    if (string != NULL) {
        free(string->string);
        string->string = NULL;
        string->string_size = 0;
    }
}
