/*
** EPITECH PROJECT, 2018
** foreach_linked_list.c
** File description:
** foreach data to the linked list
*/

#include "linked_list.h"

void foreach_linked_list(LINKED_LIST linked_list, \
void (*foreach_func)(data_list_t *))
{
    for (link_t *tmp_link = linked_list->first_link; \
    tmp_link; tmp_link = tmp_link->next) {
        foreach_func(&tmp_link->data);
    }
}
