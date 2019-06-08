/*
** EPITECH PROJECT, 2018
** swap_stack.c
** File description:
** swap stack
*/

#include "stack.h"

void swap_stack(STACK_PTR stack)
{
    data_stack_t data_tmp;

    if (stack->stack_size > 1) {
        data_tmp = stack->stack[0];
        stack->stack[0] = stack->stack[1];
        stack->stack[1] = data_tmp;
    }
}
