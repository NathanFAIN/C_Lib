/*
** EPITECH PROJECT, 2018
** dup_stack.c
** File description:
** dup stack
*/

#include "stack.h"

void dup_stack(STACK_PTR stack)
{
    data_stack_t *new_data_stack;
    size_t index = 0;

    if (stack->stack_size == 0)
        return;
    new_data_stack = malloc(sizeof(data_stack_t) * (stack->stack_size + 1));
    new_data_stack[0] = stack->stack[0];
    for (; index != stack->stack_size; index++)
        new_data_stack[index + 1] = stack->stack[index];
    stack->stack_size += 1;
    free(stack->stack);
    stack->stack = new_data_stack;
}
