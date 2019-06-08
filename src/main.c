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

    for (int i = 0; i != 10; i++)
        stack.push(i);
    while (!stack.empty())
        printf("%i\n", stack.pop().i);
    return (0);
}
