/*
** EPITECH PROJECT, 2018
** add_linked_list.c
** File description:
** add data to the linked list
*/

#include "linked_list.h"

void add_linked_list(LINKED_LIST linked_list, data_list_t data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->prev = NULL;
    new_link->data = data;
    new_link->next = linked_list->linked_list;
    linked_list->linked_list = new_link;
    if (linked_list->linked_list->next)
        linked_list->linked_list->next->prev = new_link;
}
