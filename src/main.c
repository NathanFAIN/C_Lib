/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "stack.h"
#include "vector.h"

int main(void)
{
    NEW_STACK stack = CREATE_STACK(stack, true);
    CREATE_DEFAULT_VECTOR(vect);

    vect->recycle(true);
    return (0);
}
