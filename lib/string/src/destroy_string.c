/*
** EPITECH PROJECT, 2018
** destroy_string.c
** File description:
** destroy string
*/

#include "string.h"

void destroy_string(STRING *string)
{
    if ((*string) != NULL) {
        free((*string)->string);
        free(*string);
        *string = NULL;
    }
}
