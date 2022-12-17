/*
** EPITECH PROJECT, 2020
** MY_APPLY_ON_NODES
** File description:
** This file is my task4 for the 11th day
*/

#include <stddef.h>
#include "my.h"
#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    while (begin != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return 0;
}
