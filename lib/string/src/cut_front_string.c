/*
** EPITECH PROJECT, 2018
** cut_front_string.c
** File description:
** cut front string
*/

#include "string.h"

void cut_front_string(STRING string, size_t index)
{
    char *new_string;

    if (string->string_size != 0) {
        new_string = malloc(sizeof(char) * (index + 1));
        new_string[index] = '\0';
        for (size_t index_bis = 0; index_bis != index; index_bis++) {
            new_string[index_bis] = string->string[index_bis];
        }
        free(string->string);
        string->string = new_string;
        string->string_size = index;
    }
}
