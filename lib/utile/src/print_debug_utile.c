/*
** EPITECH PROJECT, 2018
** print_debug_utile.c
** File description:
** function for help dev in debug mode...
*/

#include "utile.h"

void print_debug(const unsigned int line, char *file, \
const char *func, const int *arg)
{
    if (arg[0] == true) {
        write(2, "[DEBUG]\t("__DATE__ " " __TIME__ ") ", 32);
        write(2, file, arg[1]);
        print_debug_number(line);
        write(2, " ", 1);
        write(2, func, arg[2]);
        write(2, "\n", 1);
    }
}
