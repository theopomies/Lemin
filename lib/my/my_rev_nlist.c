/*
** EPITECH PROJECT, 2020
** MY_REV_LIST
** File description:
** This file is my task3 for the 11th day
*/

#include <stddef.h>
#include "my.h"
#include "mynlist.h"

void my_rev_nlist(number_list_t **begin)
{
    number_list_t *next = (*begin)->next;
    (*begin)->next = NULL;
    number_list_t *to_be_next = (*begin);

    while (next != NULL) {
        (*begin) = next;
        next = (*begin)->next;
        (*begin)->next = to_be_next;
        to_be_next = (*begin);
    }
}
