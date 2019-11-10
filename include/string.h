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

enum {S_STRING_TYPE, S_CHAR_TYPE};

#define STRING struct string_s *
#define NEW_STRING struct string_s * __attribute__((__cleanup__(recycle_string)))

#ifndef ROTATE_RIGHT
#define ROTATE_RIGHT false
#endif

#ifndef ROTATE_LEFT
#define ROTATE_LEFT true
#endif

/*
String object:
- create
- update
*/

struct string_s
{
    void      (*test)(void *, int);
    void      (*cat_back)(void *, unsigned int);                        //_Generic
    void      (*cat_front)(void *, unsigned int);                       //_Generic
    void      (*clear)(void);
    bool      (*cmp)(void *, unsigned int);                             //_Generic
    void      (*cut_back)(size_t);
    void      (*cut_front)(size_t);
    void      (*destroy)(void);
    STRING    (*dup)(void);
    bool      (*empty)(void);
    void      (*foreach)(void (*)(char *));
    char      (*get_at)(size_t);
    char      (*get_back)(void);
    char      (*get_front)(void);
    void      (*insert_at)(void *, unsigned int, size_t);               //_Generic
    size_t    (*len)(void);
    STRING    *(*parce)(void *, unsigned int);                          //To do & _Generic
    void      (*recycle)(bool);
    void      (*remove_at)(size_t);
    void      (*replace_at)(size_t, char);
    void      (*reverse)(void);
    void      (*rotate)(unsigned char);
    void      (*set)(char *);
    void      (*swap_at)(size_t);
    void      (*swap)(void);
    char      *(*to_char)(void);
    char      *string;
    size_t    string_size;
    bool      is_recycle;
};

void cat_back_string(STRING string, void *ptr, unsigned int type);
void cat_front_string(STRING string, void *ptr, unsigned int type);
void clear_string(STRING string);
STRING create_string(bool recycle);
bool cmp_string(STRING string, void *ptr, unsigned int type);
void cut_back_string(STRING string, size_t index);
void cut_front_string(STRING string, size_t index);
void destroy_string(STRING *string);
STRING dup_string(STRING string);
bool empty_string(STRING string);
void foreach_string(STRING string, void (*foreach_func)(char *));
char get_at_string(STRING string, size_t index);
char get_back_string(STRING string);
char get_front_string(STRING string);
void insert_at_string(STRING string, \
void *ptr, unsigned int type, size_t index);
size_t len_string(STRING string);
STRING *parce_string(STRING string, void *ptr, unsigned int type);
void recycle_string(STRING *string);
void remove_at_string(STRING string, size_t index);
void replace_at_string(STRING string, size_t index, char c);
void rotate_string(STRING string, bool rotate);
void set_recycle_string(STRING string, bool recycle);
void reverse_string(STRING string);
void set_string(STRING string, char *new_string);
void swap_at_string(STRING string, size_t index);
void swap_string(STRING string);
char *to_char_string(STRING string);

#define cat_back(X) cat_back((void *)X, \
                    _Generic((X), STRING : STRING_TYPE, default : CHAR_TYPE))
#define cat_front(X) cat_front((void *)X, \
                    _Generic((X), STRING : STRING_TYPE, default : CHAR_TYPE))
#define cmp(X) cmp((void *)X, \
                    _Generic((X), STRING : STRING_TYPE, default : CHAR_TYPE))
#define insert_at(SIZE, X) insert_at(SIZE, (void *)X, \
                    _Generic((X), STRING : STRING_TYPE, default : CHAR_TYPE))
#define parce(X) parce((void *)X, \
                    _Generic((X), STRING : STRING_TYPE, default : CHAR_TYPE))

#define CONFIG_CAT_BACK_STRING(name) void CAT_BACK_STRING_ \
##name(void *ptr, unsigned int type){cat_back_string(name, ptr, type);}

#define CONFIG_CAT_FRONT_STRING(name) void CAT_FRONT_STRING_ \
##name(void *ptr, unsigned int type){cat_front_string(name, ptr, type);}

#define CONFIG_CLEAR_STRING(name) void CLEAR_STRING_ \
##name(void){clear_string(name);}

#define CONFIG_CMP_STRING(name) bool CMP_STRING_ \
##name(void *ptr, unsigned int type){return (cmp_string(name, ptr, type));}

#define CONFIG_CUT_BACK_STRING(name) void CUT_BACK_STRING_ \
##name(size_t index){cut_back_string(name, index);}

#define CONFIG_CUT_FRONT_STRING(name) void CUT_FRONT_STRING_ \
##name(size_t index){cut_front_string(name, index);}

#define CONFIG_DESTROY_STRING(name) void DESTROY_STRING_ \
##name(void){destroy_string(&name);}

#define CONFIG_DUP_STRING(name) STRING DUP_STRING_ \
##name(void){return (dup_string(name));}

#define CONFIG_EMPTY_STRING(name) bool EMPTY_STRING_ \
##name(void){return (empty_string(name));}

#define CONFIG_FOREACH_STRING(name) void FOREACH_STRING_ \
##name(void (*foreach_func)(char *)){foreach_string(name, foreach_func);}

#define CONFIG_GET_AT_STRING(name) char GET_AT_STRING_ \
##name(size_t index){return (get_at_string(name, index));}

#define CONFIG_GET_BACK_STRING(name) char GET_BACK_STRING_ \
##name(void){return (get_back_string(name));}

#define CONFIG_GET_FRONT_STRING(name) char GET_FRONT_STRING_ \
##name(void){return (get_front_string(name));}

#define CONFIG_INSERT_AT_STRING(name) void INSERT_AT_STRING_ \
##name(void *ptr, unsigned int type, size_t index){insert_at_string(name, ptr, type, index);}

#define CONFIG_LEN_STRING(name) size_t LEN_STRING_ \
##name(void){return (len_string(name));}

#define CONFIG_PARCE_STRING(name) STRING *PARCE_STRING_ \
##name(void *ptr, unsigned int type){return (parce_string(name, ptr, type));}

#define CONFIG_RECYCLE_STRING(name) void RECYCLE_STRING_ \
##name(bool recycle){set_recycle_string(name, recycle);}

#define CONFIG_REMOVE_AT_STRING(name) void REMOVE_AT_STRING_ \
##name(size_t index){remove_at_string(name, index);}

#define CONFIG_REPLACE_AT_STRING(name) void REPLACE_AT_STRING_ \
##name(size_t index, char c){replace_at_string(name, index, c);}

#define CONFIG_REVERSE_STRING(name) void REVERSE_STRING_ \
##name(void){reverse_string(name);}

#define CONFIG_ROTATE_STRING(name) void ROTATE_STRING_ \
##name(unsigned char rotate){rotate_string(name, rotate);}

#define CONFIG_SET_STRING(name) void SET_STRING_ \
##name(char *new_string){set_string(name, new_string);}

#define CONFIG_SWAP_AT_STRING(name) void SWAP_AT_STRING_ \
##name(size_t index){swap_at_string(name, index);}

#define CONFIG_SWAP_STRING(name) void SWAP_STRING_ \
##name(void){swap_string(name);}

#define CONFIG_TO_CHAR_STRING(name) char *TO_CHAR_STRING_ \
##name(void){return (to_char_string(name));}

#define SET_CAT_BACK_STRING(name)     CONFIG_CAT_BACK_STRING(name); \
                                            name->cat_back = &CAT_BACK_STRING_##name; \

#define SET_CAT_FRONT_STRING(name)    CONFIG_CAT_FRONT_STRING(name); \
                                            name->cat_front = &CAT_FRONT_STRING_##name; \

#define SET_CLEAR_STRING(name)        CONFIG_CLEAR_STRING(name); \
                                            name->clear = &CLEAR_STRING_##name; \

#define SET_CMP_STRING(name)          CONFIG_CMP_STRING(name); \
                                            name->cmp = &CMP_STRING_##name; \

#define SET_CUT_BACK_STRING(name)     CONFIG_CUT_BACK_STRING(name); \
                                            name->cut_back = &CUT_BACK_STRING_##name; \

#define SET_CUT_FRONT_STRING(name)    CONFIG_CUT_FRONT_STRING(name); \
                                            name->cut_front = &CUT_FRONT_STRING_##name; \

#define SET_DESTROY_STRING(name)      CONFIG_DESTROY_STRING(name); \
                                            name->destroy = &DESTROY_STRING_##name; \

#define SET_DUP_STRING(name)           CONFIG_DUP_STRING(name); \
                                            name->dup = &DUP_STRING_##name; \

#define SET_EMPTY_STRING(name)        CONFIG_EMPTY_STRING(name); \
                                            name->empty = &EMPTY_STRING_##name; \

#define SET_FOREACH_STRING(name)      CONFIG_FOREACH_STRING(name); \
                                            name->foreach = &FOREACH_STRING_##name; \

#define SET_GET_AT_STRING(name)       CONFIG_GET_AT_STRING(name); \
                                            name->get_at = &GET_AT_STRING_##name; \

#define SET_GET_BACK_STRING(name)     CONFIG_GET_BACK_STRING(name); \
                                            name->get_back = &GET_BACK_STRING_##name; \

#define SET_GET_FRONT_STRING(name)    CONFIG_GET_FRONT_STRING(name); \
                                            name->get_front = &GET_FRONT_STRING_##name; \

#define SET_INSERT_AT_STRING(name)    CONFIG_INSERT_AT_STRING(name); \
                                            name->insert_at = &INSERT_AT_STRING_##name; \

#define SET_LEN_STRING(name)          CONFIG_LEN_STRING(name); \
                                            name->len = &LEN_STRING_##name; \

#define SET_PARCE_STRING(name)        CONFIG_PARCE_STRING(name); \
                                            name->parce = &PARCE_STRING_##name; \

#define SET_RECYCLE_STRING(name)      CONFIG_RECYCLE_STRING(name); \
                                            name->recycle = &RECYCLE_STRING_##name; \

#define SET_REMOVE_AT_STRING(name)    CONFIG_REMOVE_AT_STRING(name); \
                                            name->remove_at = &REMOVE_AT_STRING_##name; \

#define SET_REPLACE_AT_STRING(name)   CONFIG_REPLACE_AT_STRING(name); \
                                            name->replace_at = &REPLACE_AT_STRING_##name; \

#define SET_REVERSE_STRING(name)      CONFIG_REVERSE_STRING(name); \
                                            name->reverse = &REVERSE_STRING_##name; \

#define SET_ROTATE_STRING(name)       CONFIG_ROTATE_STRING(name); \
                                            name->rotate = &ROTATE_STRING_##name; \

#define SET_SET_STRING(name)          CONFIG_SET_STRING(name); \
                                            name->set = &SET_STRING_##name; \

#define SET_SWAP_AT_STRING(name)      CONFIG_SWAP_AT_STRING(name); \
                                            name->swap_at = &SWAP_AT_STRING_##name; \

#define SET_SWAP_STRING(name)         CONFIG_SWAP_STRING(name); \
                                            name->swap = &SWAP_STRING_##name; \

#define SET_TO_CHAR_STRING(name)      CONFIG_TO_CHAR_STRING(name); \
                                            name->to_char = &TO_CHAR_STRING_##name; \

#define UPDATE_STRING(name)           SET_CAT_BACK_STRING(name); \
                                      SET_CAT_FRONT_STRING(name); \
                                      SET_CLEAR_STRING(name); \
                                      SET_CMP_STRING(name); \
                                      SET_CUT_BACK_STRING(name); \
                                      SET_CUT_FRONT_STRING(name); \
                                      SET_DESTROY_STRING(name); \
                                      SET_DUP_STRING(name); \
                                      SET_EMPTY_STRING(name); \
                                      SET_FOREACH_STRING(name); \
                                      SET_GET_AT_STRING(name); \
                                      SET_GET_BACK_STRING(name); \
                                      SET_GET_FRONT_STRING(name); \
                                      SET_INSERT_AT_STRING(name); \
                                      SET_LEN_STRING(name); \
                                      SET_PARCE_STRING(name); \
                                      SET_RECYCLE_STRING(name); \
                                      SET_REMOVE_AT_STRING(name); \
                                      SET_REPLACE_AT_STRING(name); \
                                      SET_REVERSE_STRING(name); \
                                      SET_ROTATE_STRING(name); \
                                      SET_SET_STRING(name); \
                                      SET_SWAP_AT_STRING(name); \
                                      SET_SWAP_STRING(name); \
                                      SET_TO_CHAR_STRING(name); \

#define CREATE_STRING(name, recycle)  create_string(recycle); \
                                      UPDATE_STRING(name); \

#endif
