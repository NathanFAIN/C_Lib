/*
** EPITECH PROJECT, 2018
** size_linked_list.c
** File description:
** get the the linked list size
*/

#include "linked_list.h"

size_t size_linked_list(LINKED_LIST linked_list)
{
    return (linked_list->link_nbr);
}
