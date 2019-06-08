/*
** EPITECH PROJECT, 2018
** cmp_vector_id.c
** File description:
** cmp vector id
*/

#include "vector.h"

__attribute__ ((const)) inline bool cmp_vector_id(void *id1, void *id2)
{
    bool boolean = true;

    if ((long)id1 < INT_MAX && (long)id2 < INT_MAX \
    && (long)id1 > INT_MIN && (long)id2 > INT_MIN) {
        return ((long)id1 == (long)id2);
    } else if ((long)id1 > INT_MAX && (long)id2 > INT_MAX) {
        for (size_t i = 0; ((unsigned char *)id1)[i] && boolean; i += 1)
            boolean = ((unsigned char *)id1)[i] != \
            ((unsigned char *)id2)[i] ? false : boolean;
        return (boolean);
    } else
        return (false);
}
