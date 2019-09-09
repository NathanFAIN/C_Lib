/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

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

typedef union data_map_s data_map_t;
typedef struct table_s table_t;
typedef struct map_s map_t;

#define MAP_DATA_SIZE 16
#define MAP struct map_s *
#define NEW_MAP struct map_s * __attribute__((__cleanup__(recycle_map)))

union data_map_s
{
    int8_t              i8;
    uint8_t             ui8;
    int16_t             i16;
    uint16_t            ui16;
    int32_t             i32;
    uint32_t            ui32;
    int64_t             i64;
    uint64_t            ui64;
    intptr_t            ip;
    uintptr_t           uip;
    char                c;
    unsigned char       uc;
    short               sh;
    unsigned short      ush;
    int                 i;
    unsigned int        ui;
    long                l;
    unsigned long       ul;
    long long           ll;
    unsigned long long  ull;
    void                *p;
    char                *s;
    long double         ld;
    double              d;
    float               f;
    unsigned char       bytes[MAP_DATA_SIZE];
};

struct table_s
{
    void    *id;
    data_map_t  data;
    table_t  *next;
    table_t  *prev;
};

struct map_s
{
    void    (*recycle)(bool);
    void    (*clean)(void);
    void    (*add)(void *, data_map_t data);
    void    (*remove)(void *);
    void    (*destroy)(void);
    size_t  (*size)(void);
    data_map_t  (*get)(void *);
    data_map_t  *(*getall)(void);
    table_t **table;
    size_t  table_size;
    bool    is_recycle;
};

void add_map(MAP vect, void *id, data_map_t data);
bool cmp_map_id(void *id1, void *id2) __attribute__ ((const));
data_map_t unknown_strcut_to_data_map(size_t size, void *ptr);
table_t *create_table(void *id, data_map_t data);
MAP create_map(size_t map_size, bool recycle);
void destroy_map(MAP *map);
size_t size_map(MAP vect);
data_map_t *getall_map(MAP vect);
data_map_t get_map(MAP vect, void *id);
size_t hash_map_id(void *id) __attribute__ ((const));
void recycle_map(MAP *vect);
void set_recycle_map(MAP vect, bool recycle);
void remove_map(MAP vect, void *id);
void unlink_map(MAP map, size_t hash, table_t *table);
void clean_map(MAP map);

#define SET_MAP_CLEAN(name) __attribute__((unused)) \
void MAP_CLEAN_##name(void){clean_map(name);}

#define SET_MAP_RECYCLE(name) __attribute__((unused)) \
void MAP_RECYCLE_##name(bool recycle){set_recycle_map(name, recycle);}

#define SET_MAP_GETALL(name) __attribute__((unused)) \
data_map_t *MAP_GETALL_##name(void){return (getall_map(name));}

#define SET_MAP_DESTROY(name) __attribute__((unused)) \
void MAP_DESTROY_##name(void){destroy_map(&name);}

#define SET_MAP_REMOVE(name) __attribute__((unused)) \
void MAP_REMOVE_##name(void *id){remove_map(name, id);}

#define SET_MAP_GET(name) __attribute__((unused)) \
data_map_t MAP_GET_##name(void *id){return (get_map(name, id));}

#define SET_MAP_SIZE(name) __attribute__((unused)) \
size_t MAP_SIZE_##name(void){return (size_map(name));}

#define SET_MAP_ADD(name) \
void MAP_ADD_##name(void *id, data_map_t data){add_map(name, id, data);}

#define _SET_MAP_CLEAN(name)    SET_MAP_CLEAN(name); \
                                name->clean = &MAP_CLEAN_##name; \

#define _SET_MAP_RECYCLE(name)  SET_MAP_RECYCLE(name); \
                                name->recycle = &MAP_RECYCLE_##name; \

#define _SET_MAP_ADD(name)      SET_MAP_ADD(name); \
                                name->add = &MAP_ADD_##name; \

#define _SET_MAP_SIZE(name)     SET_MAP_SIZE(name); \
                                name->size = &MAP_SIZE_##name; \

#define _SET_MAP_REMOVE(name)   SET_MAP_REMOVE(name); \
                                name->remove = &MAP_REMOVE_##name; \

#define _SET_MAP_GET(name)      SET_MAP_GET(name); \
                                name->get = &MAP_GET_##name; \

#define _SET_MAP_DESTROY(name)  SET_MAP_DESTROY(name); \
                                name->destroy = &MAP_DESTROY_##name; \

#define _SET_MAP_GETALL(name)   SET_MAP_GETALL(name); \
                                name->getall = &MAP_GETALL_##name; \

#define UPDATE_MAP(name)        _SET_MAP_CLEAN(name); \
                                _SET_MAP_RECYCLE(name); \
                                _SET_MAP_ADD(name); \
                                _SET_MAP_SIZE(name); \
                                _SET_MAP_REMOVE(name); \
                                _SET_MAP_GET(name); \
                                _SET_MAP_DESTROY(name); \
                                _SET_MAP_GETALL(name); \

#define CREATE_MAP(name, size, recycle) create_map(size, recycle); \
                                        UPDATE_MAP(name); \

#define add_(id, data) add(((data_map_t)(id)).p, \
unknown_strcut_to_data_map(sizeof(data), &data))
#define add(id, data) add(((data_map_t)(id)).p, (data_map_t)data)
#define remove(id) remove(((data_map_t)(id)).p)
#define get(id) get(((data_map_t)(id)).p)
#define get_data_to_type(x, type) (*(type *)x.bytes)

#endif
