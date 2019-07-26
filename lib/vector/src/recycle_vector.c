/*
** EPITECH PROJECT, 2018
** recycle_vector.c
** File description:
** recycle vector
*/

#include "vector.h"

void recycle_vector(VECT *vector)
{
    if (*vector != NULL && (*vector)->is_recycle == true)
        destroy_vector(vector);
}

void set_recycle_vector(VECT vector, bool recycle)
{
    vector->is_recycle = recycle;
}
