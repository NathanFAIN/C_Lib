/*
** EPITECH PROJECT, 2018
** get_at_linked_list.c
** File description:
** get at data to the linked list
*/

#include "linked_list.h"

data_list_t get_at_linked_list(LINKED_LIST linked_list, size_t index)
{
    link_t *tmp_link = linked_list->first_link;

    while (tmp_link && index--)
        tmp_link = tmp_link->next;
    return (tmp_link ? tmp_link->data : (data_list_t) {0});
}
