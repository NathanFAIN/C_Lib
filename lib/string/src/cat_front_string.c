/*
** EPITECH PROJECT, 2018
** cat_front_string.c
** File description:
** cat front string
*/

#include "string.h"

void cat_back_string(STRING string, STRING string_bis)
{
    size_t index = 0;
    char *new_string = NULL;

    if (string->string_size + string_bis->string_size != 0) {
        new_string = malloc(sizeof(char) * \
        (string->string_size + string_bis->string_size + 1));
        new_string[string->string_size + string_bis->string_size] = '\0';
        for (; index != string_bis->string_size; index++) {
            new_string[index] = string_bis->string[index];
        }
        for (; index != string->string_size + \
        string_bis->string_size; index++) {
            new_string[index] = string->string[index - string->string_size];
        }
    }
    if (string->string_size != 0) {
        free (string->string);
    }
    string->string_size = index;
    string->string = new_string;
}
