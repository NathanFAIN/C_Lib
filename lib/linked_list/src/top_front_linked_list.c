/*
** EPITECH PROJECT, 2018
** top_front_linked_list.c
** File description:
** top_front data to the linked list
*/

#include "linked_list.h"

data_list_t top_front_linked_list(LINKED_LIST linked_list)
{
    return (linked_list->first_link ? \
    linked_list->first_link->data : (data_list_t) {0});
}
