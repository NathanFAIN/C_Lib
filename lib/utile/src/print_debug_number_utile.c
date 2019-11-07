/*
** EPITECH PROJECT, 2018
** print_debug_number_utile.c
** File description:
** function for help dev in debug mode...
*/

#include "utile.h"

void print_debug_number(unsigned int number)
{
    char c;

    if (number >= 10)
        print_debug_number(number / 10);
    c = (number % 10) + 48;
    write(2, &c, 1);
}
