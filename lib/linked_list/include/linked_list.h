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
#define LINKED_LIST_DATA_SIZE 16

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
    void        (*cat_back)(LINKED_LIST);
    void        (*cat_front)(LINKED_LIST);
    void        (*clear)(void);
    void        (*destroy)(void);
    void        (*foreach)(void (*)(data_list_t *));
    data_list_t *(*get_array)(void);
    data_list_t (*get_at)(size_t);
    void        (*insert_at)(data_list_t, size_t);
    data_list_t (*pop_back)(void);
    data_list_t (*pop_front)(void);
    void        (*push_back)(data_list_t);
    void        (*push_front)(data_list_t);
    void        (*remove_at)(size_t);
    void        (*remove_if)(bool (*)(data_list_t));
    void        (*reverse)(void);
    size_t      (*size)(void);
    void        (*sort)(int (*)(data_list_t, data_list_t));
    void        (*dup)(LINKED_LIST);
    data_list_t (*top_back)(void);
    data_list_t (*top_front)(void);
    link_t      *first_link;
    link_t      *last_link;
    size_t      link_nbr;
};

void cat_back_linked_list(LINKED_LIST linked_list, LINKED_LIST linked_list_bis);
void cat_front_linked_list(LINKED_LIST linked_list, LINKED_LIST linked_list_bis);
void clear_linked_list(LINKED_LIST linked_list);
link_t *create_link(data_list_t data);
LINKED_LIST create_linked_list(void);
void destroy_linked_list(LINKED_LIST linked_list);
void dup_linked_list(LINKED_LIST linked_list, LINKED_LIST new_linked_list);
void foreach_linked_list(LINKED_LIST linked_list, void (*foreach_func)(data_list_t *));
data_list_t *get_array_linked_list(LINKED_LIST linked_list);
data_list_t get_at_linked_list(LINKED_LIST linked_list, size_t index);
void insert_at_linked_list(LINKED_LIST linked_list, data_list_t data, size_t index);
data_list_t pop_back_linked_list(LINKED_LIST linked_list);
data_list_t pop_front_linked_list(LINKED_LIST linked_list);
void push_back_linked_list(LINKED_LIST linked_list, data_list_t data);
void push_front_linked_list(LINKED_LIST linked_list, data_list_t data);
void remove_at_linked_list(LINKED_LIST linked_list, size_t index);
void remove_if_linked_list(LINKED_LIST linked_list, bool (*remove_if_func)(data_list_t));
void remove_linked_list(LINKED_LIST linked_list, link_t *remove_link);
void reverse_linked_list(LINKED_LIST linked_list);
size_t size_linked_list(LINKED_LIST linked_list);
void sort_linked_list(LINKED_LIST linked_list, int (*cmp_func)(data_list_t, data_list_t));
data_list_t top_back_linked_list(LINKED_LIST linked_list);
data_list_t top_front_linked_list(LINKED_LIST linked_list);


#define CONFIG_CAT_BACK_LINKED_LIST(name) __attribute__((unused)) void CAT_BACK_LINKED_LIST_ \
##name(LINKED_LIST list){cat_back_linked_list(name, list);}

#define CONFIG_CAT_FRONT_LINKED_LIST(name) __attribute__((unused)) void CAT_FRONT_LINKED_LIST_ \
##name(LINKED_LIST list){cat_front_linked_list(name, list);}

#define CONFIG_CLEAR_LINKED_LIST(name) __attribute__((unused)) void CLEAR_LINKED_LIST_ \
##name(void){clear_linked_list(name);}

#define CONFIG_DESTROY_LINKED_LIST(name) __attribute__((unused)) void DESTROY_LINKED_LIST_ \
##name(void){destroy_linked_list(name);}

#define CONFIG_DUP_LINKED_LIST(name) __attribute__((unused)) void DUP_LINKED_LIST_ \
##name(LINKED_LIST new_linked_list){dup_linked_list(name, new_linked_list);}

#define CONFIG_FOREACH_LINKED_LIST(name) __attribute__((unused)) void FOREACH_LINKED_LIST_ \
##name(void (*foreach_func)(data_list_t *)){foreach_linked_list(name, foreach_func);}

#define CONFIG_GET_ARRAY_LINKED_LIST(name) __attribute__((unused)) data_list_t *GET_ARRAY_LINKED_LIST_ \
##name(void){return (get_array_linked_list(name));}

#define CONFIG_GET_AT_LINKED_LIST(name) __attribute__((unused)) data_list_t GET_AT_LINKED_LIST_ \
##name(size_t index){return (get_at_linked_list(name, index));}

#define CONFIG_INSERT_AT_LINKED_LIST(name) __attribute__((unused)) void INSERT_AT_LINKED_LIST_ \
##name(data_list_t data, size_t index){insert_at_linked_list(name, data, index);}

#define CONFIG_POP_BACK_LINKED_LIST(name) __attribute__((unused)) data_list_t POP_BACK_LINKED_LIST_ \
##name(void){return (pop_back_linked_list(name));}

#define CONFIG_POP_FRONT_LINKED_LIST(name) __attribute__((unused)) data_list_t POP_FRONT_LINKED_LIST_ \
##name(void){return (pop_front_linked_list(name));}

#define CONFIG_PUSH_BACK_LINKED_LIST(name) __attribute__((unused)) void PUSH_BACK_LINKED_LIST_ \
##name(data_list_t data){push_back_linked_list(name, data);}

#define CONFIG_PUSH_FRONT_LINKED_LIST(name) __attribute__((unused)) void PUSH_FRONT_LINKED_LIST_ \
##name(data_list_t data){push_front_linked_list(name, data);}

#define CONFIG_REMOVE_AT_LINKED_LIST(name) __attribute__((unused)) void REMOVE_AT_LINKED_LIST_ \
##name(size_t index){remove_at_linked_list(name, index);}

#define CONFIG_REMOVE_IF_LINKED_LIST(name) __attribute__((unused)) void REMOVE_IF_LINKED_LIST_ \
##name(bool (*remove_if_func)(data_list_t)){remove_if_linked_list(name, remove_if_func);}

#define CONFIG_REVERSE_LINKED_LIST(name) __attribute__((unused)) void REVERSE_LINKED_LIST_ \
##name(void){reverse_linked_list(name);}

#define CONFIG_SIZE_LINKED_LIST(name) __attribute__((unused)) size_t SIZE_LINKED_LIST_ \
##name(void){return (size_linked_list(name));}

#define CONFIG_SORT_LINKED_LIST(name) __attribute__((unused)) void SORT_LINKED_LIST_ \
##name(int (*cmp_func)(data_list_t, data_list_t)){sort_linked_list(name, cmp_func);}

#define CONFIG_TOP_BACK_LINKED_LIST(name) __attribute__((unused)) data_list_t TOP_BACK_LINKED_LIST_ \
##name(void){return (top_back_linked_list(name));}

#define CONFIG_TOP_FRONT_LINKED_LIST(name) __attribute__((unused)) data_list_t TOP_FRONT_LINKED_LIST_ \
##name(void){return (top_front_linked_list(name));}

#define SET_CAT_BACK_LINKED_LIST(name)     CONFIG_CAT_BACK_LINKED_LIST(name); \
                                            name->cat_back = &CAT_BACK_LINKED_LIST_##name; \

#define SET_CAT_FRONT_LINKED_LIST(name)    CONFIG_CAT_FRONT_LINKED_LIST(name); \
                                            name->cat_front = &CAT_FRONT_LINKED_LIST_##name; \

#define SET_CLEAR_LINKED_LIST(name)        CONFIG_CLEAR_LINKED_LIST(name); \
                                            name->clear = &CLEAR_LINKED_LIST_##name; \

#define SET_DESTROY_LINKED_LIST(name)      CONFIG_DESTROY_LINKED_LIST(name); \
                                            name->destroy = &DESTROY_LINKED_LIST_##name; \

#define SET_DUP_LINKED_LIST(name)           CONFIG_DUP_LINKED_LIST(name); \
                                            name->dup = &DUP_LINKED_LIST_##name; \

#define SET_FOREACH_LINKED_LIST(name)      CONFIG_FOREACH_LINKED_LIST(name); \
                                            name->foreach = &FOREACH_LINKED_LIST_##name; \

#define SET_GET_ARRAY_LINKED_LIST(name)    CONFIG_GET_ARRAY_LINKED_LIST(name); \
                                            name->get_array = &GET_ARRAY_LINKED_LIST_##name; \

#define SET_GET_AT_LINKED_LIST(name)       CONFIG_GET_AT_LINKED_LIST(name); \
                                            name->get_at = &GET_AT_LINKED_LIST_##name; \

#define SET_INSERT_AT_LINKED_LIST(name)    CONFIG_INSERT_AT_LINKED_LIST(name); \
                                            name->insert_at = &INSERT_AT_LINKED_LIST_##name; \

#define SET_POP_BACK_LINKED_LIST(name)     CONFIG_POP_BACK_LINKED_LIST(name); \
                                            name->pop_back = &POP_BACK_LINKED_LIST_##name; \

#define SET_POP_FRONT_LINKED_LIST(name)    CONFIG_POP_FRONT_LINKED_LIST(name); \
                                            name->pop_front = &POP_FRONT_LINKED_LIST_##name; \

#define SET_PUSH_BACK_LINKED_LIST(name)    CONFIG_PUSH_BACK_LINKED_LIST(name); \
                                            name->push_back = &PUSH_BACK_LINKED_LIST_##name; \

#define SET_PUSH_FRONT_LINKED_LIST(name)   CONFIG_PUSH_FRONT_LINKED_LIST(name); \
                                            name->push_front = &PUSH_FRONT_LINKED_LIST_##name; \

#define SET_REMOVE_AT_LINKED_LIST(name)    CONFIG_REMOVE_AT_LINKED_LIST(name); \
                                            name->remove_at = &REMOVE_AT_LINKED_LIST_##name; \

#define SET_REMOVE_IF_LINKED_LIST(name)    CONFIG_REMOVE_IF_LINKED_LIST(name); \
                                            name->remove_if = &REMOVE_IF_LINKED_LIST_##name; \

#define SET_REVERSE_LINKED_LIST(name)      CONFIG_REVERSE_LINKED_LIST(name); \
                                            name->reverse = &REVERSE_LINKED_LIST_##name; \

#define SET_SIZE_LINKED_LIST(name)         CONFIG_SIZE_LINKED_LIST(name); \
                                            name->size = &SIZE_LINKED_LIST_##name; \

#define SET_SORT_LINKED_LIST(name)         CONFIG_SORT_LINKED_LIST(name); \
                                            name->sort = &SORT_LINKED_LIST_##name; \

#define SET_TOP_BACK_LINKED_LIST(name)     CONFIG_TOP_BACK_LINKED_LIST(name); \
                                            name->top_back = &TOP_BACK_LINKED_LIST_##name; \

#define SET_TOP_FRONT_LINKED_LIST(name)    CONFIG_TOP_FRONT_LINKED_LIST(name); \
                                            name->top_front = &TOP_FRONT_LINKED_LIST_##name; \

#define CREATE_LINKED_LIST(name)    create_linked_list(); \
                                    SET_CAT_BACK_LINKED_LIST(name); \
                                    SET_CAT_FRONT_LINKED_LIST(name); \
                                    SET_CLEAR_LINKED_LIST(name); \
                                    SET_DESTROY_LINKED_LIST(name); \
                                    SET_DUP_LINKED_LIST(name); \
                                    SET_FOREACH_LINKED_LIST(name); \
                                    SET_GET_ARRAY_LINKED_LIST(name); \
                                    SET_GET_AT_LINKED_LIST(name); \
                                    SET_INSERT_AT_LINKED_LIST(name); \
                                    SET_POP_BACK_LINKED_LIST(name); \
                                    SET_POP_FRONT_LINKED_LIST(name); \
                                    SET_PUSH_BACK_LINKED_LIST(name); \
                                    SET_PUSH_FRONT_LINKED_LIST(name); \
                                    SET_REMOVE_AT_LINKED_LIST(name); \
                                    SET_REMOVE_IF_LINKED_LIST(name); \
                                    SET_REVERSE_LINKED_LIST(name); \
                                    SET_SIZE_LINKED_LIST(name); \
                                    SET_SORT_LINKED_LIST(name); \
                                    SET_TOP_BACK_LINKED_LIST(name); \
                                    SET_TOP_FRONT_LINKED_LIST(name); \

#define push_back(data) push_back((data_list_t)data)
#define push_front(data) push_front((data_list_t)data)

#endif
