/*
** EPITECH PROJECT, 2018
** pop_back_linked_list.c
** File description:
** pop_back data to the linked list
*/

#include "linked_list.h"

data_list_t pop_back_linked_list(LINKED_LIST linked_list)
{
    data_list_t data;
    link_t *tmp_link = linked_list->last_link;

    data = linked_list->last_link ? \
    linked_list->last_link->data : (data_list_t) {0};
    if (linked_list->last_link) {
        linked_list->last_link = linked_list->last_link->prev;
        linked_list->link_nbr--;
    }
    if (linked_list->last_link == linked_list->first_link)
        linked_list->first_link = NULL;
    free(tmp_link);
    return (data);
}
