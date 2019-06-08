/*
** EPITECH PROJECT, 2018
** create_stack.c
** File description:
** create stack
*/

#include "stack.h"

stack_t create_stack(stack_t new_stack, bool recycle)
{
    new_stack.stack = NULL;
    new_stack.stack_size = 0;
    new_stack.is_recycle = recycle;
    return (new_stack);
}
