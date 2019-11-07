/*
** EPITECH PROJECT, 2018
** dup_string.c
** File description:
** dup string
*/

#include "string.h"

STRING dup_string(STRING string)
{
    STRING new_string = malloc(sizeof(string_t));

    if (string->string_size != 0) {
        new_string->string = malloc(sizeof(char) * (string->string_size + 1));
        new_string->string[string->string_size] = '\0';
        for (size_t index = 0; string->string[index] != '\0'; index++) {
            new_string->string[index] = string->string[index];
        }
    } else {
        new_string->string = NULL;
    }
    new_string->string_size = string->string_size;
    new_string->is_recycle = string->is_recycle;
    return (new_string);
}
