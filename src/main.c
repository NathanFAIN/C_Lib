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
#include "utile.h"

int main(void)
{
    NEW_STACK stack = CREATE_STACK(stack, true);
    NEW_MAP map = CREATE_MAP(map, 100, true);
    NEW_GARBAGE_COLLECTOR garbage_collector = \
    CREATE_GARBAGE_COLLECTOR(garbage_collector, true);
    NEW_LINKED_LIST list = CREATE_LINKED_LIST(list, true);

    // bit_fields_t test = {0};
    // test.value[0] = 255;
    // printf("%i%i%i%i%i%i%i%i\n", test.bytes[0].bit1, test.bytes[0].bit2, test.bytes[0].bit3, test.bytes[0].bit4, test.bytes[0].bit5, test.bytes[0].bit6, test.bytes[0].bit7, test.bytes[0].bit8);
    return (0);
}
