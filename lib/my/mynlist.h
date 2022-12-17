/*
** EPITECH PROJECT, 2020
** LINKED_LISTS
** File description:
** mynlist
*/

#ifndef MYNLIST_H_
#define MYNLIST_H_

typedef struct number_list
{
    char data;
    struct number_list *next;
} number_list_t;

int my_nlist_size(number_list_t const *begin);

void my_rev_nlist(number_list_t **);

#endif /* MYNLIST_H_ */
