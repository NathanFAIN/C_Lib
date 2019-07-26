/*
** EPITECH PROJECT, 2018
** create_link.c
** File description:
** init the linked list struct
*/

#include "linked_list.h"

link_t *create_link(data_list_t data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->prev = NULL;
    new_link->next = NULL;
    new_link->data = data;
    return (new_link);
}
