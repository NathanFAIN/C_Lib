/*
** EPITECH PROJECT, 2018
** top_stack.c
** File description:
** top stack
*/

#include "stack.h"

data_stack_t top_stack(STACK_PTR stack)
{
    return (stack->stack_size != 0 ? stack->stack[0] : (data_stack_t) {0});
}
