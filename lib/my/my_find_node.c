/*
** EPITECH PROJECT, 2020
** MY_FIND_NODE
** File description:
** This file is my task6 for the 11th day
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref,
    int (*cmp)(void *, void const *))
{
    while (begin != NULL) {
        if ((*cmp)(begin->data, data_ref) == 0)
            return (linked_list_t *) begin;
        begin = begin->next;
    }
    return NULL;
}
