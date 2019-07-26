/*
** EPITECH PROJECT, 2018
** reverse_linked_list.c
** File description:
** reverse the linked list
*/

#include "linked_list.h"

void reverse_linked_list(LINKED_LIST linked_list)
{
    link_t *tmp_linked_list = linked_list->first_link;
    link_t *tmp_linked_list_bis = linked_list->last_link;
    data_list_t tmp_swap;

    if (!tmp_linked_list)
        return;
    while (tmp_linked_list != tmp_linked_list_bis) {
        tmp_swap = tmp_linked_list->data;
        tmp_linked_list->data = tmp_linked_list_bis->data;
        tmp_linked_list_bis->data = tmp_swap;
        tmp_linked_list = tmp_linked_list->next;
        if (tmp_linked_list != tmp_linked_list_bis)
            break;
        tmp_linked_list_bis = tmp_linked_list_bis->prev;
    }
}
