/*
** EPITECH PROJECT, 2018
** get_back_string.c
** File description:
** get back string
*/

#include "string.h"

char get_back_string(STRING string)
{
    if (string->string_size != 0) {
        return (string->string[string->string_size - 1]);
    } else {
        return (0);
    }
}
