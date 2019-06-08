/*
** EPITECH PROJECT, 2018
** recycle_stack.c
** File description:
** recycle stack
*/

#include "stack.h"

void recycle_stack(STACK_PTR stack)
{

    if (stack->is_recycle == true)
        destroy_stack(stack);
}

void set_recycle_stack(STACK_PTR stack, bool recycle)
{
    stack->is_recycle = recycle;
}
