/*
** EPITECH PROJECT, 2018
** create_linked_list.c
** File description:
** init the linked list struct
*/

#include "linked_list.h"

LINKED_LIST create_linked_list(void)
{
    LINKED_LIST new_linked_list = malloc(sizeof(linked_list_t));

    new_linked_list->linked_list = NULL;
    return (new_linked_list);
}
