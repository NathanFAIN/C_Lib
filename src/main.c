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
    // LINKED_LIST list = CREATE_LINKED_LIST(list);
    //
    // for (unsigned int i = 0; i != 100000; i++)
    //     list->push_front(i);
    // list->destroy();

    // NEW_STACK stack = CREATE_STACK(stack, false);
    // for (unsigned int i = 0; i != 100000; i++)
    //     stack.push(i);
    // stack.destroy();

    CREATE_MAP(map, 100000);
    for (unsigned int i = 0; i != 100000; i++)
        map->add(i, i);
    map->destroy();
    return (0);
}
