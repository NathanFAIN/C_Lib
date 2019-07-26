/*
** EPITECH PROJECT, 2018
** sort_linked_list.c
** File description:
** sort the linked list
*/

#include "linked_list.h"

void sort_linked_list_bis(link_t *linked_list, bool *is_sorted, \
int (*cmp_func)(data_list_t, data_list_t))
{
    data_list_t tmp_swap;

    while (linked_list->next) {
        if (cmp_func(linked_list->data, \
        linked_list->next->data) != 0) {
            tmp_swap = linked_list->data;
            linked_list->data = linked_list->next->data;
            linked_list->next->data = tmp_swap;
            *is_sorted = false;
        }
    }
}

void sort_linked_list(LINKED_LIST linked_list, \
int (*cmp_func)(data_list_t, data_list_t))
{
    link_t *tmp_linked_list;
    bool is_sorted = false;

    while (linked_list->first_link && is_sorted == false) {
        is_sorted = true;
        tmp_linked_list = linked_list->first_link;
        sort_linked_list_bis(tmp_linked_list, &is_sorted, cmp_func);
    }
}
