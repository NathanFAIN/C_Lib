/*
** EPITECH PROJECT, 2018
** get_array_linked_list.c
** File description:
** get at data to the linked list
*/

#include "linked_list.h"

data_list_t *get_array_linked_list(LINKED_LIST linked_list)
{
    data_list_t *data_array;
    link_t *tmp_link;
    size_t index = 0;

    if (link_nbr == 0)
        return;
    data_array = malloc(sizeof(data_list_t) * link_nbr);
    while (tmp_link) {
        data_array[index] = tmp_link->data;
        tmp_link = tmp_link->next;
        index++;
    }
    return (data_array);
}
