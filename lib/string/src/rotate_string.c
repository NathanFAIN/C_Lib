/*
** EPITECH PROJECT, 2018
** rotate_string.c
** File description:
** rotate string
*/

#include "string.h"

void rotate_string(STRING string, bool rotate)
{
    char tmp;

    if (string->string_size != 0 && rotate == ROTATE_RIGHT) {
        tmp = string->string[0];
        for (size_t index = 1; index != string->string_size; index++) {
            string->string[index - 1] = string->string[index];
        }
        string->string[string->string_size] = tmp;
    } else if (string->string_size != 0 && rotate == ROTATE_LEFT){
        tmp = string->string[string->string_size];
        for (size_t index = string->string_size; index != 1; index--) {
            string->string[index] = string->string[index - 1];
        }
        string->string[0] = tmp;
    }
}
