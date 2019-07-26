/*
** EPITECH PROJECT, 2018
** push_back_linked_list.c
** File description:
** add data to the linked list
*/

#include "linked_list.h"

void push_back_linked_list(LINKED_LIST linked_list, data_list_t data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->next = NULL;
    new_link->data = data;
    new_link->prev = linked_list->last_link;
    linked_list->last_link = new_link;
    if (linked_list->last_link->prev)
        linked_list->last_link->prev->next = new_link;
    if (!linked_list->first_link)
        linked_list->first_link = linked_list->last_link;
    linked_list->link_nbr++;
}
