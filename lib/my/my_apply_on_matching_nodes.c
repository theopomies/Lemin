/*
** EPITECH PROJECT, 2020
** MY_APPLY_ON_MATCHING_NODES
** File description:
** This file is my task5 for the 11th day
*/

#include <stddef.h>
#include "my.h"
#include "mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin,
    int (*f)(void *), void const *data_ref, int (*cmp)(void *, void const *))
{
    while (begin != NULL) {
        if ((*cmp)(begin->data, data_ref) == 0)
            (*f)(begin->data);
        begin = begin->next;
    }
    return 0;
}
