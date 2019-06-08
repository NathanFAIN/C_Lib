/*
** EPITECH PROJECT, 2018
** clear_stack.c
** File description:
** clear stack
*/

#include "stack.h"

void clear_stack(STACK_PTR stack)
{
    free(stack->stack);
    stack->stack = NULL;
    stack->stack_size = 0;
}
