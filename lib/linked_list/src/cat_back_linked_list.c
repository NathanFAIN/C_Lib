/*
** EPITECH PROJECT, 2018
** cat_back_linked_list.c
** File description:
** foreach data to the linked list
*/

#include "linked_list.h"

void cat_back_linked_list(LINKED_LIST linked_list, LINKED_LIST linked_list_bis)
{
    for (link_t *tmp_link = linked_list_bis->first_link; \
    tmp_link; tmp_link = tmp_link->next) {
        push_back_linked_list(linked_list, tmp_link->data);
    }
}
