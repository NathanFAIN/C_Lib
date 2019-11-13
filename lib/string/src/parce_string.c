/*
** EPITECH PROJECT, 2018
** parce_string.c
** File description:
** parce string
*/

#include "string.h"

STRING *_parce_string(STRING string, char *string_bis, size_t size)
{
    (void) string;
    (void) size;
    (void) string_bis;
    return (NULL);
}

STRING *parce_string(STRING string, void *ptr, unsigned int type)
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
    return (_parce_string(string, string_bis, size));
}
