/*
** EPITECH PROJECT, 2018
** empty_string.c
** File description:
** empty string
*/

#include "string.h"

bool empty_string(STRING string)
{
    return (string->string_size == 0 ? true : false);
}
