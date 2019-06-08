/*
** EPITECH PROJECT, 2018
** rotate_stack.c
** File description:
** rotate stack
*/

#include "stack.h"

void rotate_stack(STACK_PTR stack, unsigned char rotate)
{
    data_stack_t *new_data_stack;
    data_stack_t data_tmp;

    if (stack->stack_size == 0 || (rotate != ROTATE_RIGHT \
    && rotate != ROTATE_LEFT))
        return;
    data_tmp = stack->stack[rotate == ROTATE_RIGHT ? 0 : stack->stack_size - 1];
    new_data_stack = malloc(sizeof(data_stack_t) * (stack->stack_size));
    if (rotate == ROTATE_RIGHT)
        for (size_t index = 0; index != stack->stack_size - 1; index++)
            new_data_stack[index] = stack->stack[index + 1];
    else
        for (size_t index = 1; index != stack->stack_size; index++)
            new_data_stack[index] = stack->stack[index - 1];
    free(stack->stack);
    stack->stack = new_data_stack;
    new_data_stack[rotate == ROTATE_LEFT ? \
    0 : stack->stack_size - 1] = data_tmp;
}
