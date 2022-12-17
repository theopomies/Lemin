/*
** EPITECH PROJECT, 2020
** MY_ADD_IN_SORTED_LIST
** File description:
** This file is my task10 for the 11th day
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mylist.h"

void my_add_in_sorted_list(linked_list_t **begin, void *data,
    int (*cmp)(void *, void *))
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    new_element->data = my_strdup(data);
    new_element->next = *begin;
    *begin = new_element;
    my_sort_list(begin, cmp);
}
