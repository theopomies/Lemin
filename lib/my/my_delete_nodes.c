/*
** EPITECH PROJECT, 2020
** MY_DELETE_NODES
** File description:
** This file is my task07 for the 11th day
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref,
    int (*cmp)(void *, void const *))
{
    linked_list_t *current = malloc(sizeof(linked_list_t));

    while ((*begin) != NULL && (*cmp)((*begin)->data, data_ref) == 0)
        (*begin) = (*begin)->next;
    current = (*begin);
    while (current != NULL && current->next != NULL) {
        if ((*cmp)((current->next)->data, data_ref) == 0) {
            current->next = (current->next)->next;
        } else
            current = current->next;
    }
    return 0;
}
