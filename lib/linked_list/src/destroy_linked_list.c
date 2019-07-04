/*
** EPITECH PROJECT, 2018
** destroy_linked_list.c
** File description:
** destroy the linked list struct
*/

#include "linked_list.h"

void destroy_linked_list(LINKED_LIST linked_list)
{
    link_t *tmp_linked_list;

    while (linked_list->linked_list) {
        tmp_linked_list = linked_list->linked_list;
        linked_list->linked_list = linked_list->linked_list->next;
        free(tmp_linked_list);
    }
    free(linked_list);
}
