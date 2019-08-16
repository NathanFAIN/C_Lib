/*
** EPITECH PROJECT, 2018
** recycle_garbage_collector.c
** File description:
** choose to destroy or not the linked list struct when you leave the scope.
*/

#include "garbage_collector.h"

void recycle_garbage_collector(GARBAGE_COLLECTOR *garbage_collector)
{
    if (*garbage_collector != NULL && (*garbage_collector)->is_recycle == true)
        destroy_garbage_collector(garbage_collector);
}

void set_recycle_garbage_collector(GARBAGE_COLLECTOR garbage_collector, \
bool recycle)
{
    garbage_collector->is_recycle = recycle;
}
