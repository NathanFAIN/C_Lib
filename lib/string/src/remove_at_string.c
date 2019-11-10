/*
** EPITECH PROJECT, 2018
** remove_at_string.c
** File description:
** remove at string
*/

#include "string.h"

void remove_at_string(STRING string, size_t index)
{
    if (index < string->string_size) {
        for (size_t index_bis = index + 1; \
        index_bis != string->string_size; index_bis++) {
            string->string[index_bis - 1] = string->string[index_bis];
        }
        string->string_size--;
    }
}
