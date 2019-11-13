/*
** EPITECH PROJECT, 2018
** set_string.c
** File description:
** set string
*/

#include "string.h"

void _set_string(STRING string, char *new_string, size_t size)
{
    if (string->string_size != 0) {
        free(string->string);
    }
    string->string_size = size;
    if (string->string_size == 0) {
        string->string = NULL;
    } else {
        string->string = malloc(sizeof(char) * (string->string_size + 1));
        string->string[string->string_size] = 0;
        for (size_t index = 0; index != string->string_size; index++)
            string->string[index] = new_string[index];
    }
}

void set_string(STRING string, void *ptr, unsigned int type)
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
    _set_string(string, string_bis, size);
}
