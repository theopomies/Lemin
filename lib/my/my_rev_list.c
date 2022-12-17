/*
** EPITECH PROJECT, 2020
** MY_REV_LIST
** File description:
** This file is my task3 for the 11th day
*/

#include <stddef.h>
#include "my.h"
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *next = (*begin)->next;
    (*begin)->next = NULL;
    linked_list_t *to_be_next = (*begin);

    while (next != NULL) {
        (*begin) = next;
        next = (*begin)->next;
        (*begin)->next = to_be_next;
        to_be_next = (*begin);
    }
}
