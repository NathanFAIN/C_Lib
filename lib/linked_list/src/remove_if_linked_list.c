/*
** EPITECH PROJECT, 2018
** remove_if_linked_list.c
** File description:
** remove_if data to the linked list
*/

#include "linked_list.h"

void remove_if_linked_list(LINKED_LIST linked_list, \
bool (*remove_if_func)(data_list_t))
{
    link_t *tmp_link = linked_list->first_link;

    while (tmp_link) {
        if (remove_if_func(tmp_link->data)) {
            remove_linked_list(linked_list, tmp_link);
            linked_list->link_nbr--;
        } else {
            tmp_link = tmp_link->next;
        }
    }
}
