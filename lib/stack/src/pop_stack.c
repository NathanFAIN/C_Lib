/*
** EPITECH PROJECT, 2018
** pop_stack.c
** File description:
** pop stack
*/

#include "stack.h"

data_stack_t pop_stack(STACK_PTR stack)
{
    data_stack_t *new_data_stack;
    data_stack_t data;
    size_t index = 0;

    if (stack->stack_size == 0)
        return ((data_stack_t) {0});
    data = stack->stack[0];
    stack->stack_size -= 1;
    if (stack->stack_size == 0) {
        free(stack->stack);
        stack->stack = NULL;
    } else {
        new_data_stack = malloc(sizeof(data_stack_t) * (stack->stack_size));
        for (; index != stack->stack_size; index++)
            new_data_stack[index] = stack->stack[index + 1];
        free(stack->stack);
        stack->stack = new_data_stack;
    }
    return (data);
}
