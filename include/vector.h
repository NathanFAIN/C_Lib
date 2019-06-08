/*
** EPITECH PROJECT, 2018
** vector.h
** File description:
** vector
*/

#ifndef VECTOR_H_
#define VECTOR_H_

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


typedef union data_vector_s data_vector_t;
typedef struct table_s table_t;
typedef struct vector_s vector_t;

#define VECTOR_DATA_SIZE 1024
#define VECTOR_DEFAULT_SIZE 1024
#define VECT struct vector_s *

union data_vector_s
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
    unsigned char   bytes[VECTOR_DATA_SIZE];
};

struct table_s
{
    void    *id;
    data_vector_t  data;
    table_t  *next;
    table_t  *prev;
};

struct vector_s
{
    void    (*recycle)(bool);
    void    (*add)(void *, data_vector_t data);
    void    (*remove)(void *);
    void    (*destroy)(void);
    size_t  (*size)(void);
    data_vector_t  (*get)(void *);
    data_vector_t  *(*getall)(void);
    table_t **table;
    size_t  table_size;
    bool    is_recycle;
};

void add_vector(VECT vect, void *id, data_vector_t data);
bool cmp_vector_id(void *id1, void *id2) __attribute__ ((const));
data_vector_t unknown_strcut_to_data_vector(size_t size, void *ptr);
table_t *create_table(void *id, data_vector_t data);
VECT create_vector(size_t vector_size);
void destroy_vector(VECT vector);
size_t size_vector(VECT vect);
data_vector_t *getall_vector(VECT vect);
data_vector_t get_vector(VECT vect, void *id);
size_t hash_vector_id(void *id) __attribute__ ((const));
void recycle_vector(VECT *vect);
void set_recycle_vector(VECT vect, bool recycle);
void remove_vector(VECT vect, void *id);

#define SET_VECT_RECYCLE(name) __attribute__((unused)) \
void VECT_RECYCLE_##name(bool recycle){set_recycle_vector(name, recycle);}

#define SET_VECT_GETALL(name) __attribute__((unused)) \
data_vector_t *VECT_GETALL_##name(void){return (getall_vector(name));}

#define SET_VECT_DESTROY(name) __attribute__((unused)) \
void VECT_DESTROY_##name(void){destroy_vector(name);}

#define SET_VECT_REMOVE(name) __attribute__((unused)) \
void VECT_REMOVE_##name(void *id){remove_vector(name, id);}

#define SET_VECT_GET(name) __attribute__((unused)) \
data_vector_t VECT_GET_##name(void *id){return (get_vector(name, id));}

#define SET_VECT_SIZE(name) __attribute__((unused)) \
size_t VECT_SIZE_##name(void){return (size_vector(name));}

#define SET_VECT_ADD(name) \
void VECT_ADD_##name(void *id, data_vector_t data){add_vector(name, id, data);}

#define _SET_VECT_RECYCLE(name) SET_VECT_RECYCLE(name); \
                                name->recycle = &VECT_RECYCLE_##name; \

#define _SET_VECT_ADD(name)     SET_VECT_ADD(name); \
                                name->add = &VECT_ADD_##name; \

#define _SET_VECT_SIZE(name)    SET_VECT_SIZE(name); \
                                name->size = &VECT_SIZE_##name; \

#define _SET_VECT_REMOVE(name)  SET_VECT_REMOVE(name); \
                                name->remove = &VECT_REMOVE_##name; \

#define _SET_VECT_GET(name)     SET_VECT_GET(name); \
                                name->get = &VECT_GET_##name; \

#define _SET_VECT_DESTROY(name) SET_VECT_DESTROY(name); \
                                name->destroy = &VECT_DESTROY_##name; \

#define _SET_VECT_GETALL(name)  SET_VECT_GETALL(name); \
                                name->getall = &VECT_GETALL_##name; \

#define _CREATE_VECTOR(name)    _SET_VECT_RECYCLE(name); \
                                _SET_VECT_ADD(name); \
                                _SET_VECT_SIZE(name); \
                                _SET_VECT_REMOVE(name); \
                                _SET_VECT_GET(name); \
                                _SET_VECT_DESTROY(name); \
                                _SET_VECT_GETALL(name); \

#define CREATE_DEFAULT_VECTOR(name) VECT name __attribute__((__cleanup__( \
                                    recycle_vector))) = \
                                    create_vector(VECTOR_DEFAULT_SIZE); \
                                    _CREATE_VECTOR(name); \

#define CREATE_VECTOR(name, size)   VECT name __attribute__((__cleanup__( \
                                    recycle_vector))) = create_vector(size); \
                                    _CREATE_VECTOR(name); \

#define add_(id, data) add(((data_vector_t)id).p, \
unknown_strcut_to_data_vector(sizeof(data), &data))
#define add(id, data) add(((data_vector_t)id).p, (data_vector_t)data)
#define remove(id) remove(((data_vector_t)id).p)
#define get(id) get(((data_vector_t)id).p)
#define get_data_to_type(x, type) (*(type *)x.bytes)

#endif
