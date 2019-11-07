/*
** EPITECH PROJECT, 2018
** reverse_string.c
** File description:
** reverse string
*/

#include "string.h"

void reverse_string(STRING string)
{
    size_t index = 0;
    size_t index_bis = string->string_size - 1;
    char tmp;

    if (string->string_size != 0) {
        for (; index < index_bis; index++, index_bis--) {
            tmp = string->string[index];
            string->string[index] = string->string[index_bis];
            string->string[index_bis] = tmp;
        }
    }
}
