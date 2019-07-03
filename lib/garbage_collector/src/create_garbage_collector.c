/*
** EPITECH PROJECT, 2018
** create_garbage_collector.c
** File description:
** init the garbage collector struct
*/

#include "garbage_collector.h"

GARBAGE_COLLECTOR create_garbage_collector(void)
{
    GARBAGE_COLLECTOR garbage_collector = malloc(sizeof(garbage_collector_t));

    garbage_collector->list = NULL;
    return (garbage_collector);
}
