/*
** EPITECH PROJECT, 2020
** MY_MERGE
** File description:
** This file is my task11 for the 11th day
*/

#include "my.h"
#include "mylist.h"

void my_merge(linked_list_t **begin1, linked_list_t *begin2,
    int (*cmp)(void *, void *))
{
    my_concat_list(begin1, begin2);
    my_sort_list(begin1, cmp);
}
