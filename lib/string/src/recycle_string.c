/*
** EPITECH PROJECT, 2018
** recycle_string.c
** File description:
** recycle string
*/

#include "string.h"

void recycle_string(STRING *string)
{
    if (*string != NULL && (*string)->is_recycle == true)
        destroy_string(string);
}

void set_recycle_string(STRING string, bool recycle)
{
    string->is_recycle = recycle;
}
