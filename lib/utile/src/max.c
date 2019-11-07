/*
** EPITECH PROJECT, 2018
** auto_free.c
** File description:
** functions for auto free...
*/

#include "utile.h"

int _utile_max(size_t arg_counter, va_list parameters_infos)
{
    int nb1 = va_arg(parameters_infos, int);
    int nb2;

    arg_counter--;
    if (!arg_counter) {
        return (nb1);
    } else {
        nb2 = _utile_max(arg_counter, parameters_infos);
        return (nb1 > nb2 ? nb1 : nb2);
    }
}

int utile_max(size_t arg_counter, ...)
{
    va_list parameters_infos;

    va_start(parameters_infos, arg_counter);
    return (_utile_max(arg_counter, parameters_infos));
}
