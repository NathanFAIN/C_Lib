/*
** EPITECH PROJECT, 2018
** hash_vector_id.c
** File description:
** hash vector id
*/

#include "vector.h"

__attribute__ ((const)) size_t hash_vector_id(void *id)
{
    size_t hash = 0;

    if ((long)id < INT_MAX && (long)id > INT_MIN)
        return ((long)id);
    for (size_t index = 0; ((unsigned char *)id)[index]; index++)
        hash += (((unsigned char *)id)[index] * (index + 1)) + hash % 2;
    return (hash);
}
