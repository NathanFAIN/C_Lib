/*
** EPITECH PROJECT, 2018
** utile.h
** File description:
** my personal and utile include file
*/

#ifndef UTILE_H_
#define UTILE_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

#define UNUSED __attribute__((unused))
#define CONST __attribute__((const))
#define VOID __attribute__((noreturn))

#define SWAP(A, B)  a = a ^ b; \
                    b = a ^ b; \
                    a = a ^ b; \

#define IS_IN(X, X1, X2, E) (X > X1 && X < X2)

typedef union bit_fields_s bit_fields_t;

union bit_fields_s
{
    uint8_t value[1024];
    struct
    {
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t bit3 : 1;
        uint8_t bit4 : 1;
        uint8_t bit5 : 1;
        uint8_t bit6 : 1;
        uint8_t bit7 : 1;
        uint8_t bit8 : 1;
    } bytes[1024];
};

#endif
