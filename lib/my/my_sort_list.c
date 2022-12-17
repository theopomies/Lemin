/*
** EPITECH PROJECT, 2020
** MY_SORT_LIST
** File description:
** This file is my task09 for the 11th day
*/

#include <stddef.h>
#include "my.h"
#include "mylist.h"

static void check_swap(void **data1, void **data2, int (*cmp)(void *, void *))
{
    void *tmp;

    if ((*cmp)(*data1, *data2) > 0) {
        tmp = *data1;
        *data1 = *data2;
        *data2 = tmp;
    }
}

void my_sort_list(linked_list_t **begin, int (*cmp)(void *, void *))
{
    int size = my_list_size(*begin);
    linked_list_t *current = *begin;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            check_swap(&(current->data), &((current->next)->data), cmp);
            current = current->next;
        }
        current = *begin;
    }
}
