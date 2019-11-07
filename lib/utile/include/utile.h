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
#include <string.h>

#define DEBUG_MODE true

#define MALLOC(SIZE)    gc_alloc_ptr_list(SIZE)

#define SW(C) write(1, C, sizeof(C))

#define MAX(...) utile_max(ARGS_NBR(__VA_ARGS__), __VA_ARGS__)
#define MIN(...) utile_min(ARGS_NBR(__VA_ARGS__), __VA_ARGS__)

#define ARGS_NBR(N, ...) \
(sizeof((__typeof__(N)[]){N, ##__VA_ARGS__}) / sizeof(__typeof__(N)))

#define DENED __attribute__ ((error ("error")))
#define WARNING __attribute__ ((warning ("warning")))
#define USELESS __attribute__ ((deprecated("Useless function")))
#define UNUSED __attribute__((unused))
#define CONST __attribute__((const))
#define VOID __attribute__((noreturn))

#define SWAP(A, B)  a = a ^ b; \
                    b = a ^ b; \
                    a = a ^ b; \

#define IS_IN(X, X1, X2, E) (X > X1 && X < X2)

#define LAMBDA(code) ({code func;})

#define DEBUG() print_debug(__LINE__, __FILE__ " : ", __FUNCTION__, \
(const int []){DEBUG_MODE, sizeof(__FILE__), sizeof(__FUNCTION__)})

#define BINARY(var) print_binary((long long)var, sizeof(var))

typedef union bit_fields_s bit_fields_t;

int utile_min(size_t arg_counter, ...);
int utile_max(size_t arg_counter, ...);
void print_debug_number(unsigned int number);
void print_debug(const unsigned int line, char *file, \
const char *func, const int *arg);
void print_binary(long long value, size_t size);
extern void *gc_alloc_ptr_list(size_t alloc_size) \
__attribute__ ((returns_nonnull, alloc_size (1)));
void gc_destroy_ptr_list() __attribute__ ((destructor));

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
