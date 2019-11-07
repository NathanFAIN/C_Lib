/*
** EPITECH PROJECT, 2018
** compare_string.c
** File description:
** compare string
*/

#include "string.h"

bool cmp_string(STRING string1, STRING string2)
{
    size_t index = 0;

    if (string1->string_size != 0 && string2->string_size != 0 && \
    string1->string_size == string2->string_size) {
        for (; string1->string[index] != '\0' && \
        string1->string[index] == string2->string[index]; index++);
        return (string1->string[index] == string2->string[index] ? \
        true : false);
    } else {
        return (false);
    }
}
