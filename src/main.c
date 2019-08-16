/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "stack.h"
#include "map.h"
#include "garbage_collector.h"
#include "linked_list.h"

int main(void)
{
    NEW_STACK stack = CREATE_STACK(stack, true);
    NEW_LINKED_LIST list = CREATE_LINKED_LIST(list, true);
    NEW_MAP map = CREATE_MAP(map, 100, true);
    NEW_GARBAGE_COLLECTOR garbage_collector = \
    CREATE_GARBAGE_COLLECTOR(garbage_collector, true);

    return (0);
}
