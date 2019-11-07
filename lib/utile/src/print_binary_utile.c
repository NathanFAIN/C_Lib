/*
** EPITECH PROJECT, 2018
** print_binary_utile.c
** File description:
** function for help dev in debug mode...
*/

#include "utile.h"

void print_binary(long long value, size_t size)
{
	for (size_t index = 1 << (size - 1) * 4; index > 0; index = index / 2) {
        if (value & index) {
            write(2, "1", 1);
        } else {
            write(2, "0", 1);
        }
    }
    write(2, "\n", 1);
}
