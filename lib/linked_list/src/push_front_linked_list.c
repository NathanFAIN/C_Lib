/*
** EPITECH PROJECT, 2018
** push_front_linked_list.c
** File description:
** add data to the linked list
*/

#include "linked_list.h"

void push_front_linked_list(LINKED_LIST linked_list, data_list_t data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->prev = NULL;
    new_link->data = data;
    new_link->next = linked_list->first_link;
    linked_list->first_link = new_link;
    if (linked_list->first_link->next)
        linked_list->first_link->next->prev = new_link;
    if (!linked_list->last_link)
        linked_list->last_link = linked_list->first_link;
    linked_list->link_nbr++;
}
