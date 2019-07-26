/*
** EPITECH PROJECT, 2018
** remove_at_linked_list.c
** File description:
** remove at data to the linked list
*/

#include "linked_list.h"

void remove_at_linked_list(LINKED_LIST linked_list, size_t index)
{
    link_t *tmp_link = linked_list->first_link;

    while (tmp_link && index) {
        tmp_link = tmp_link->next;
        index--;
    }
    if (tmp_link) {
        remove_linked_list(linked_list, tmp_link);
        linked_list->link_nbr--;
    }
}
