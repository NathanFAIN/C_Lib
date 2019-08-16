/*
** EPITECH PROJECT, 2018
** create_linked_list.c
** File description:
** init the linked list struct
*/

#include "linked_list.h"

LINKED_LIST create_linked_list(bool recycle)
{
    LINKED_LIST new_linked_list = malloc(sizeof(linked_list_t));

    new_linked_list->first_link = NULL;
    new_linked_list->last_link = NULL;
    new_linked_list->link_nbr = 0;
    new_linked_list->is_recycle = recycle;
    return (new_linked_list);
}
