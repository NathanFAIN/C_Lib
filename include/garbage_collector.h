/*
** EPITECH PROJECT, 2018
** garbage_collector.h
** File description:
** garbage_collector
*/

#ifndef GARBAGE_COLLECTOR_H_
#define GARBAGE_COLLECTOR_H_

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

typedef struct ptr_garbage_collector_s ptr_garbage_collector_t;
typedef struct garbage_collector_s garbage_collector_t;

#define GARBAGE_COLLECTOR struct garbage_collector_s *

struct ptr_garbage_collector_s
{
    void                    *ptr;
    void                    (*destroy_ptr)(void *);
    ptr_garbage_collector_t *next;
};

struct garbage_collector_s
{
    void                    (*add_ptr)(void *, void (*destroy_ptr)(void *));
    void                    (*destroy)(void);
    void                    (*clean)(void);
    ptr_garbage_collector_t *list;
};

void add_garbage_collector(GARBAGE_COLLECTOR garbage_collector, void *ptr, void (*destroy_ptr)(void *));
GARBAGE_COLLECTOR create_garbage_collector(void);
void destroy_garbage_collector(GARBAGE_COLLECTOR garbage_collector);
void clean_garbage_collector(GARBAGE_COLLECTOR garbage_collector);

#define SET_GARBAGE_COLLECTOR(name) __attribute__((unused)) void GARBAGE_COLLECTOR_ \
##name(void *ptr, void (*destroy_ptr)(void *)){add_garbage_collector(name, ptr, destroy_ptr);}

#define SET_DESTROY_GARBAGE_COLLECTOR(name) __attribute__((unused)) void DESTROY_GARBAGE_COLLECTOR_ \
##name(void){destroy_garbage_collector(name);}

#define SET_CLEAN_GARBAGE_COLLECTOR(name) __attribute__((unused)) void CLEAN_GARBAGE_COLLECTOR_ \
##name(void){clean_garbage_collector(name);}

#define _SET_GARBAGE_COLLECTOR(name)    SET_GARBAGE_COLLECTOR(name); \
                                        name->add_ptr = &GARBAGE_COLLECTOR_##name; \

#define _SET_DESTROY_GARBAGE_COLLECTOR(name)    SET_DESTROY_GARBAGE_COLLECTOR(name); \
                                        name->destroy = &DESTROY_GARBAGE_COLLECTOR_##name; \

#define _SET_CLEAN_GARBAGE_COLLECTOR(name)  SET_CLEAN_GARBAGE_COLLECTOR(name); \
                                            name->clean = &CLEAN_GARBAGE_COLLECTOR_##name; \

#define CREATE_GARBAGE_COLLECTOR(name)  GARBAGE_COLLECTOR name = create_garbage_collector(); \
                                        _SET_CLEAN_GARBAGE_COLLECTOR(name); \
                                        _SET_DESTROY_GARBAGE_COLLECTOR(name); \
                                        _SET_GARBAGE_COLLECTOR(name); \

#endif
