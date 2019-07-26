/*
** EPITECH PROJECT, 2018
** clear_linked_list.c
** File description:
** clear the linked list struct
*/

#include "linked_list.h"

void clear_linked_list(LINKED_LIST linked_list)
{
    link_t *tmp_linked_list;

    while (linked_list->first_link) {
        tmp_linked_list = linked_list->first_link;
        linked_list->first_link = linked_list->first_link->next;
        free(tmp_linked_list);
    }
    linked_list->link_nbr = 0;
    linked_list->first_link = NULL;
    linked_list->last_link = NULL;
}
