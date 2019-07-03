/*
** EPITECH PROJECT, 2018
** size_linked_list.c
** File description:
** get the the linked list size
*/

#include "linked_list.h"

size_t size_linked_list(LINKED_LIST linked_list)
{
    size_t linked_list_size = 0;

    while (linked_list->linked_list) {
        linked_list->linked_list = linked_list->linked_list->next;
        linked_list_size++;
    }
    return (linked_list_size);
}
