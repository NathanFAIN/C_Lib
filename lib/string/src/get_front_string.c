/*
** EPITECH PROJECT, 2018
** get_front_string.c
** File description:
** get front string
*/

#include "string.h"

char get_front_string(STRING string)
{
    if (string->string_size != 0) {
        return (string->string[0]);
    } else {
        return (0);
    }
}
