/*
** EPITECH PROJECT, 2018
** remove_linked_list.c
** File description:
** remove data to the linked list
*/

#include "linked_list.h"

void remove_linked_list(LINKED_LIST linked_list, link_t *remove_link)
{
    if (remove_link->next)
        remove_link->next->prev = remove_link->prev;
    else
        linked_list->last_link = remove_link->prev;
    if (remove_link->prev)
        remove_link->prev->next = remove_link->next;
    else
        linked_list->first_link = remove_link->next;
    free(remove_link);
}
