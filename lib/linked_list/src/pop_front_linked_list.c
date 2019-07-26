/*
** EPITECH PROJECT, 2018
** pop_front_linked_list.c
** File description:
** pop_front data to the linked list
*/

#include "linked_list.h"

data_list_t pop_front_linked_list(LINKED_LIST linked_list)
{
    data_list_t data;
    link_t *tmp_link = linked_list->first_link;

    data = linked_list->first_link ? \
    linked_list->first_link->data : (data_list_t) {0};
    if (linked_list->first_link) {
        linked_list->first_link = linked_list->first_link->next;
        linked_list->link_nbr--;
    }
    if (linked_list->last_link == linked_list->first_link)
        linked_list->last_link = NULL;
    free(tmp_link);
    return (data);
}
