/*
** EPITECH PROJECT, 2018
** cat_front_string.c
** File description:
** cat front string
*/

#include "string.h"

void _cat_front_string(STRING string, char *string_bis, size_t size)
{
    size_t index = 0;
    char *new_string = NULL;

    if (string->string_size + size != 0) {
        new_string = malloc(sizeof(char) * \
        (string->string_size + size + 1));
        new_string[string->string_size + size] = '\0';
        for (; index != size; index++) {
            new_string[index] = string_bis[index];
        }
        for (; index != string->string_size + size; index++) {
            new_string[index] = string->string[index - string->string_size];
        }
    }
    if (string->string_size != 0) {
        free(string->string);
    }
    string->string_size = index;
    string->string = new_string;
}

void cat_front_string(STRING string, void *ptr, unsigned int type)
{
    size_t size = 0;
    char *string_bis = NULL;

    if (type == STRING_S_TYPE) {
        size = ((STRING)ptr)->string_size;
        string_bis = ((STRING)ptr)->string;
    } else if (type == STRING_C_TYPE) {
        string_bis = (char *)&ptr;
        size = 1;
    } else {
        string_bis = ptr;
        for (; string_bis[size]; size++);
    }
    _cat_front_string(string, string_bis, size);
}
