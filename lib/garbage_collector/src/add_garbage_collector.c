/*
** EPITECH PROJECT, 2018
** add_garbage_collector.c
** File description:
** add ptr to the garbage collector
*/

#include "garbage_collector.h"

void add_garbage_collector(GARBAGE_COLLECTOR garbage_collector, void *ptr, void (*destroy_ptr)(void *))
{
    ptr_garbage_collector_t *garbage = malloc(sizeof(ptr_garbage_collector_t));

    garbage->ptr = ptr;
    garbage->destroy_ptr = destroy_ptr;
    garbage->next = garbage_collector->list;
    garbage_collector->list = garbage;
}
