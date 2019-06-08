/*
** EPITECH PROJECT, 2018
** empty_stack.c
** File description:
** empty stack
*/

#include "stack.h"

bool empty_stack(STACK_PTR stack)
{
    return (stack->stack_size == 0 ? true : false);
}
