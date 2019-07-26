/*
** EPITECH PROJECT, 2018
** dup_linked_list.c
** File description:
** dup_linked_list at data to the linked list
*/

#include "linked_list.h"

void dup_linked_list(LINKED_LIST linked_list, LINKED_LIST new_linked_list)
{
    link_t *tmp_link = linked_list->first_link;
    link_t *new_tmp_link;

    new_linked_list->link_nbr = linked_list->link_nbr;
    if (tmp_link)
        new_linked_list->first_link = create_link(tmp_link->data);
    if (linked_list->last_link && linked_list->last_link != tmp_link)
        new_linked_list->last_link = create_link(linked_list->last_link->data);
    else if (linked_list->last_link == tmp_link)
        linked_list->last_link = new_linked_list->first_link;
    new_tmp_link = new_linked_list->first_link;
    tmp_link = tmp_link->next;
    while (tmp_link) {
        new_tmp_link->next = create_link(tmp_link->data);
        new_tmp_link = new_tmp_link->next;
        tmp_link = tmp_link->next;
    }
}
