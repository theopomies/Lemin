/*
** EPITECH PROJECT, 2020
** MY_LIST_SIZE
** File description:
** This file is my task2 for the 11th day
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    while (begin != NULL) {
        ++i;
        begin = begin->next;
    }
    return i;
}
