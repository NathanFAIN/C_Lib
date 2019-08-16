/*
** EPITECH PROJECT, 2018
** insert_at_linked_list.c
** File description:
** insert_at the linked list
*/

#include "linked_list.h"

void insert_at_linked_list(LINKED_LIST linked_list, data_list_t data, \
size_t index)
{
    link_t *new_link;
    link_t *tmp_link = linked_list->first_link;

    if (index <= 0)
        return (push_front_linked_list(linked_list, data));
    if (index >= linked_list->link_nbr)
        return (push_back_linked_list(linked_list, data));
    new_link = create_link(data);
    linked_list->link_nbr++;
    for (;tmp_link->next && index; index--, tmp_link = tmp_link->next);
    new_link->next = tmp_link;
    new_link->prev = tmp_link->prev;
    if (tmp_link->prev)
        tmp_link->prev->next = new_link;
    else
        linked_list->first_link = new_link;
    if (tmp_link->next)
        tmp_link->next->prev = new_link;
    else
        linked_list->last_link = new_link;
}
