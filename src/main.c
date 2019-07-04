/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "stack.h"
#include "vector.h"
#include "garbage_collector.h"
#include "linked_list.h"

int main(void)
{
    /*  Linked list :    */
    LINKED_LIST list = CREATE_LINKED_LIST(list);
    list->add_list(42);
    printf("%i\n", list->linked_list->data.i);
    list->destroy();

    /*  Garbage collector :    */
    CREATE_GARBAGE_COLLECTOR(garbage);
    garbage->add_ptr(malloc(1), free);
    garbage->destroy();

    /*  Stack :    */
    NEW_STACK stack = CREATE_STACK(stack, true);
    for (int i = 0; i != 10; i++)
        stack.push(i);
    while (!stack.empty())
        printf("%i\n", stack.pop().i);

    /*  Vector :    */
    CREATE_DEFAULT_VECTOR(vect);
    vect->recycle(true);
    vect->add(1, 21);
    printf("%i\n", vect->get(1).i);
    return (0);
}
