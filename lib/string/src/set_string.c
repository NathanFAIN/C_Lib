/*
** EPITECH PROJECT, 2018
** set_string.c
** File description:
** set string
*/

#include "string.h"

void set_string(STRING string, char *new_string)
{
    size_t index = 0;

    if (string->string_size != 0) {
        free(string->string);
    }
    for (; new_string[index] != '\0'; index++);
    string->string_size = index;
    if (string->string_size == 0) {
        string->string = NULL;
    } else {
        string->string = malloc(sizeof(char) * (string->string_size + 1));
        string->string[string->string_size] = 0;
        for (index = 0; new_string[index] != '\0'; index++)
            string->string[index] = new_string[index];
    }
}
