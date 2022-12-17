/*
** EPITECH PROJECT, 2020
** MY_PARAMS_TO_LIST
** File description:
** This file is my task01 for the 11th day
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mylist.h"

int my_add_to_list(linked_list_t **list, void *data)
{
    linked_list_t *new_param = malloc(sizeof(linked_list_t));

    new_param->data = my_strdup(data);
    new_param->next = *list;
    *list = new_param;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *new_list = NULL;

    for (int i = 0; i < ac; i++)
        my_add_to_list(&new_list, av[i]);
    return new_list;
}
