/*
** EPITECH PROJECT, 2018
** clean_garbage_collector.c
** File description:
** destroy all ptr in the garbage collector.
*/

#include "garbage_collector.h"

void clean_garbage_collector(GARBAGE_COLLECTOR garbage_collector)
{
    ptr_garbage_collector_t *garbage_tmp;

    while (garbage_collector->list) {
        garbage_collector->list->destroy_ptr(garbage_collector->list->ptr);
        garbage_tmp = garbage_collector->list;
        garbage_collector->list = garbage_collector->list->next;
        free(garbage_tmp);
    }
}
