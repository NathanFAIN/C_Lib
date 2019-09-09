/*
** EPITECH PROJECT, 2018
** stack.h
** File description:
** stack
*/

#ifndef STACK_H_
#define STACK_H_

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

typedef union data_stack_s data_stack_t;
typedef struct stack_s stack_t;

#define STACK_DATA_SIZE 16
#define STACK_PTR struct stack_s *
#define STACK_PTR struct stack_s *
#define NEW_STACK struct stack_s __attribute__((__cleanup__(recycle_stack)))
#define STACK struct stack_s
#define ROTATE_RIGHT 0
#define ROTATE_LEFT 1

union data_stack_s
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
    unsigned char       bytes[STACK_DATA_SIZE];
};

struct stack_s
{
    void            (*push)(data_stack_t);
    data_stack_t    (*pop)(void);
    data_stack_t    (*top)(void);
    void            (*clear)(void);
    void            (*dup)(void);
    void            (*swap)(void);
    void            (*rotate)(unsigned char);
    bool            (*empty)(void);
    size_t          (*size)(void);
    void            (*destroy)(void);
    void            (*recycle)(bool);
    data_stack_t    *stack;
    size_t          stack_size;
    bool            is_recycle;
};

void clear_stack(STACK_PTR stack);
STACK create_stack(STACK new_stack, bool recycle);
void destroy_stack(STACK_PTR stack);
void dup_stack(STACK_PTR stack);
bool empty_stack(STACK_PTR stack);
data_stack_t pop_stack(STACK_PTR stack);
void push_stack(STACK_PTR stack, data_stack_t data);
void recycle_stack(STACK_PTR stack);
void set_recycle_stack(STACK_PTR stack, bool recycle);
size_t size_stack(STACK_PTR stack);
void swap_stack(STACK_PTR stack);
data_stack_t top_stack(STACK_PTR stack);
void rotate_stack(STACK_PTR stack, unsigned char rotate);
data_stack_t unknown_strcut_to_data_stack(size_t size, void *ptr);

#define SET_STACK_RECYCLE(name) __attribute__((unused)) void STACK_RECYCLE_ \
##name(bool recycle){set_recycle_stack(&name, recycle);}

#define SET_STACK_DESTROY(name) __attribute__((unused)) void STACK_DESTROY_ \
##name(void){destroy_stack(&name);}

#define SET_STACK_SIZE(name) __attribute__((unused)) size_t STACK_SIZE_ \
##name(void){return (size_stack(&name));}

#define SET_STACK_EMPTY(name) __attribute__((unused)) bool STACK_EMPTY_ \
##name(void){return (empty_stack(&name));}

#define SET_STACK_SWAP(name) __attribute__((unused)) void STACK_SWAP_ \
##name(void){swap_stack(&name);}

#define SET_STACK_ROTATE(name) __attribute__((unused)) void STACK_ROTATE_ \
##name(unsigned char rotate){rotate_stack(&name, rotate);}

#define SET_STACK_DUP(name) __attribute__((unused)) void STACK_DUP_ \
##name(void){dup_stack(&name);}

#define SET_STACK_CLEAR(name) __attribute__((unused)) void STACK_CLEAR_ \
##name(void){clear_stack(&name);}

#define SET_STACK_TOP(name) __attribute__((unused)) data_stack_t STACK_TOP_ \
##name(void){return (top_stack(&name));}

#define SET_STACK_POP(name) __attribute__((unused)) data_stack_t STACK_POP_ \
##name(void){return (pop_stack(&name));}

#define SET_STACK_PUSH(name) __attribute__((unused)) void STACK_PUSH_ \
##name(data_stack_t data){push_stack(&name, data);}

#define _SET_STACK_RECYCLE(name)    SET_STACK_RECYCLE(name); \
                                    name.recycle = &STACK_RECYCLE_##name; \

#define _SET_STACK_DESTROY(name)    SET_STACK_DESTROY(name); \
                                    name.destroy = &STACK_DESTROY_##name; \

#define _SET_STACK_SIZE(name)       SET_STACK_SIZE(name); \
                                    name.size = &STACK_SIZE_##name; \

#define _SET_STACK_EMPTY(name)      SET_STACK_EMPTY(name); \
                                    name.empty = &STACK_EMPTY_##name; \

#define _SET_STACK_SWAP(name)       SET_STACK_SWAP(name); \
                                    name.swap = &STACK_SWAP_##name; \

#define _SET_STACK_ROTATE(name)     SET_STACK_ROTATE(name); \
                                    name.rotate = &STACK_ROTATE_##name; \

#define _SET_STACK_DUP(name)        SET_STACK_DUP(name); \
                                    name.dup = &STACK_DUP_##name; \

#define _SET_STACK_CLEAR(name)      SET_STACK_CLEAR(name); \
                                    name.clear = &STACK_CLEAR_##name; \

#define _SET_STACK_TOP(name)        SET_STACK_TOP(name); \
                                    name.top = &STACK_TOP_##name; \

#define _SET_STACK_POP(name)        SET_STACK_POP(name); \
                                    name.pop = &STACK_POP_##name; \

#define _SET_STACK_PUSH(name)       SET_STACK_PUSH(name); \
                                    name.push = &STACK_PUSH_##name; \

#define UPDATE_STACK(name)          _SET_STACK_RECYCLE(name); \
                                    _SET_STACK_DESTROY(name); \
                                    _SET_STACK_SIZE(name); \
                                    _SET_STACK_EMPTY(name); \
                                    _SET_STACK_SWAP(name); \
                                    _SET_STACK_ROTATE(name); \
                                    _SET_STACK_DUP(name); \
                                    _SET_STACK_CLEAR(name); \
                                    _SET_STACK_TOP(name); \
                                    _SET_STACK_POP(name); \
                                    _SET_STACK_PUSH(name); \

#define CREATE_STACK(name, recycle) create_stack(name, recycle); \
                                    UPDATE_STACK(name); \

#define push(data) push((data_stack_t)data)
#define push_(data) push(unknown_strcut_to_data_stack(sizeof(data), &data))
#endif
