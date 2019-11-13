/*
** EPITECH PROJECT, 2018
** compare_string.c
** File description:
** compare string
*/

#include "string.h"

bool _cmp_string(STRING string1, char *string2, size_t size)
{
    size_t index = 0;

    if (string1->string_size != 0 && size != 0 && \
    string1->string_size == size) {
        for (; string1->string[index] != '\0' && \
        string1->string[index] == string2[index]; index++);
        return (string1->string[index] == string2[index] ? \
        true : false);
    } else {
        return (false);
    }
}

bool cmp_string(STRING string, void *ptr, unsigned int type)
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
    return (_cmp_string(string, string_bis, size));
}
