/*
** EPITECH PROJECT, 2018
** push_stack.c
** File description:
** push stack
*/

#include "stack.h"

void push_stack(STACK_PTR stack, data_stack_t data)
{
    data_stack_t *new_data_stack;
    size_t index = 0;

    new_data_stack = malloc(sizeof(data_stack_t) * (stack->stack_size + 1));
    new_data_stack[0] = data;
    for (; index != stack->stack_size; index++)
        new_data_stack[index + 1] = stack->stack[index];
    stack->stack_size += 1;
    free(stack->stack);
    stack->stack = new_data_stack;
}
