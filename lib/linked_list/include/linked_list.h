/*
** EPITECH PROJECT, 2018
** linked_list.h
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

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

typedef union data_list_s data_list_t;
typedef struct link_s link_t;
typedef struct linked_list_s linked_list_t;

#define LINKED_LIST struct linked_list_s *
#define LINKED_LIST_DATA_SIZE 1024

union data_list_s
{
    char            c;
    unsigned char   uc;
    short           sh;
    unsigned short  ush;
    int             i;
    unsigned int    ui;
    long            l;
    unsigned long   ul;
    long long       ll;
    void            *p;
    char            *s;
    long double     ld;
    double          d;
    float           f;
    unsigned char   bytes[LINKED_LIST_DATA_SIZE];
};

struct link_s
{
    data_list_t data;
    link_t      *next;
    link_t      *prev;
};

struct linked_list_s
{
    size_t (*size)(void);
    void   (*add_list)(data_list_t);
    void   (*destroy)(void);
    link_t *linked_list;
};

LINKED_LIST create_linked_list(void);
void add_linked_list(LINKED_LIST linked_list, data_list_t data);
void destroy_linked_list(LINKED_LIST linked_list);
size_t size_linked_list(LINKED_LIST linked_list);

#define SET_DESTROY_LINKED_LIST(name) __attribute__((unused)) void DESTROY_LINKED_LIST_ \
##name(void){destroy_linked_list(name);}

#define SET_ADD_LINKED_LIST(name) __attribute__((unused)) void ADD_LINKED_LIST_ \
##name(data_list_t data){add_linked_list(name, data);}

#define SET_SIZE_LINKED_LIST(name) __attribute__((unused)) size_t SIZE_LINKED_LIST_ \
##name(void){return (size_linked_list(name));}

#define _SET_DESTROY_LINKED_LIST(name)  SET_DESTROY_LINKED_LIST(name); \
                                        name->destroy = &DESTROY_LINKED_LIST_##name; \

#define _SET_ADD_LINKED_LIST(name)  SET_ADD_LINKED_LIST(name); \
                                    name->add_list = &ADD_LINKED_LIST_##name; \

#define _SET_SIZE_LINKED_LIST(name) SET_SIZE_LINKED_LIST(name); \
                                    name->size = &SIZE_LINKED_LIST_##name; \

#define CREATE_LINKED_LIST(name)  create_linked_list(); \
                                        _SET_DESTROY_LINKED_LIST(name); \
                                        _SET_ADD_LINKED_LIST(name); \
                                        _SET_SIZE_LINKED_LIST(name); \

#define add_list(data) add_list((data_list_t)data)

#endif
