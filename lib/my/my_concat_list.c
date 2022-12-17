/*
** EPITECH PROJECT, 2020
** MY_CONCAT_LIST
** File description:
** MY_CONCAT_LIST
*/

#include <stddef.h>
#include "my.h"
#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *last = (*begin1);

    if (last == NULL) {
        *begin1 = begin2;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = begin2;
}
