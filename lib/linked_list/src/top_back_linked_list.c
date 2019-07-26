/*
** EPITECH PROJECT, 2018
** top_back_linked_list.c
** File description:
** top_back data to the linked list
*/

#include "linked_list.h"

data_list_t top_back_linked_list(LINKED_LIST linked_list)
{
    return (linked_list->last_link ? \
    linked_list->last_link->data : (data_list_t) {0});
}
