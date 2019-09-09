/*
** EPITECH PROJECT, 2018
** empty_linked_list.c
** File description:
** get the the linked list empty
*/

#include "linked_list.h"

bool empty_linked_list(LINKED_LIST linked_list)
{
    return ((linked_list->link_nbr == 0) ? true : false);
}
