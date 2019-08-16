/*
** EPITECH PROJECT, 2018
** destroy_stack.c
** File description:
** destroy stack
*/

#include "stack.h"

void destroy_stack(STACK_PTR stack)
{
    if (stack->stack != NULL) {
        free(stack->stack);
        stack->stack = NULL;
    }
}
