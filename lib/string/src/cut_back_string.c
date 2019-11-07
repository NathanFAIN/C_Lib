/*
** EPITECH PROJECT, 2018
** cut_back_string.c
** File description:
** cut back string
*/

#include "string.h"

void cut_back_string(STRING string, size_t index)
{
    char *new_string;

    if (string->string_size != 0) {
        new_string = malloc(sizeof(char) * (string->string_size - index + 1));
        new_string[string->string_size - index] = '\0';
        for (size_t index_bis = 0; index_bis != string->string_size - index; \
        index_bis++) {
            new_string[index_bis] = string->string[index_bis];
        }
        free(string->string);
        string->string = new_string;
        string->string_size = string->string_size - index;
    }
}
