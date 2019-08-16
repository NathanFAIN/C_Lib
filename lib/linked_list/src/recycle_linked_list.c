/*
** EPITECH PROJECT, 2018
** recycle_linked_list.c
** File description:
** recycle the linked list struct
*/

#include "linked_list.h"

void recycle_linked_list(LINKED_LIST *linked_list)
{
    if (*linked_list != NULL && (*linked_list)->is_recycle == true)
        destroy_linked_list(linked_list);
}

void set_recycle_linked_list(LINKED_LIST linked_list, bool recycle)
{
    linked_list->is_recycle = recycle;
}
