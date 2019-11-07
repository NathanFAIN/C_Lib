/*
** EPITECH PROJECT, 2018
** string.h
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

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

typedef struct string_s string_t;

#define STRING struct string_s *
#define ROTATE_RIGHT false
#define ROTATE_LEFT true

/*
String object:
- create
- update
*/

STRING create_string(bool recycle);
void destroy_string(STRING *string);
size_t len_string(STRING string);
bool empty_string(STRING string);
char get_at_string(STRING string, size_t index);
char get_back_string(STRING string);
char get_front_string(STRING string);
void recycle_string(STRING *string);
void set_recycle_string(STRING string, bool recycle);
void clear_string(STRING string);
bool cmp_string(STRING string1, STRING string2);
void set_string(STRING string, char *new_string);
char *to_char_string(STRING string);
void swap_string(STRING string);
void swap_at_string(STRING string, size_t index);
STRING dup_string(STRING string);
void cut_back_string(STRING string, size_t index);
void cut_front_string(STRING string, size_t index);
void replace_at_string(STRING string, size_t index, char c);
void rotate_string(STRING string, bool rotate);
void reverse_string(STRING string);
void insert_at_string(STRING string, size_t index, STRING string_bis);

struct string_s
{
    void      (*cat_back)(STRING);
    void      (*cat_front)(STRING);
    void      (*clear)(void);
    bool      (*cmp)(STRING);
    void      (*cut_back)(size_t);
    void      (*cut_front)(size_t);
    void      (*destroy)(void);
    STRING    (*dup)(void);
    bool      (*empty)(void);
    char      (*get_at)(size_t);
    char      (*get_back)(void);
    char      (*get_front)(void);
    void      (*insert_at)(size_t, STRING);
    size_t    (*len)(void);
    STRING    *(*parce)(STRING);
    void      (*recycle)(bool);
    void      (*replace_at)(size_t, char);
    void      (*reverse)(void);
    void      (*rotate)(bool);
    void      (*set)(char *);
    void      (*swap_at)(size_t);
    void      (*swap)(void);
    char      *(*to_char)(void);
    char      *string;
    size_t    string_size;
    bool      is_recycle;
};

#endif
