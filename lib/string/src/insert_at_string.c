/*
** EPITECH PROJECT, 2018
** insert_at_string.c
** File description:
** insert at string
*/

#include "string.h"

void _insert_at_string(STRING string, \
char *string_bis, size_t size, size_t index)
{
    char *new_string;
    size_t index_bis = 0;

    if (string->string_size + size != 0) {
        new_string = malloc(sizeof(char) * \
        (string->string_size + size + 1));
        for (; index_bis != index && index_bis != string->string_size; index_bis++)
            new_string[index_bis] = string->string[index_bis];
        for (size_t index_string = index; index_string != size; index_string++)
            new_string[index_bis + index_string] = string_bis[index_string];
        for (; index_bis != string->string_size; index_bis++)
            new_string[index_bis + size] = string->string[index_bis];
        new_string[string->string_size + size] = '\0';
        free(string->string);
        string->string = new_string;
    }
}

void insert_at_string(STRING string, void *ptr, unsigned int type, size_t index)
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
    _insert_at_string(string, string_bis, size, index);
}
