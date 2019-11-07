/*
** EPITECH PROJECT, 2018
** create_string.c
** File description:
** create string
*/

#include "string.h"

STRING create_string(bool recycle)
{
    STRING new_string = malloc(sizeof(string_t));

    new_string->string = NULL;
    new_string->string_size = 0;
    new_string->is_recycle = recycle;
    return (new_string);
}
