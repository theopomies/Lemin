/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** full_parsing
*/

#include "lemin.h"
#include "my.h"
#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void destroy_input(input_t *input)
{
    input_t *next = NULL;

    if (!input)
        return;
    while (input) {
        next = input->next;
        free(input->line);
        free(input);
        input = next;
    }
}

int get_input(input_t **beg)
{
    char *buf = NULL;
    size_t cap = 0;
    ssize_t len = getline(&buf, &cap, stdin);
    input_t *current = *beg;
    int type = ANTS;
    input_t *elem = NULL;

    for (; len > 1 && valid(buf, &type, len);
        len = getline(&buf, &cap, stdin)) {
        if (!(elem = malloc(sizeof(input_t))))
            return (EXIT_FAILURE);
        elem->line = my_strdup(buf);
        elem->next = NULL;
        if (current)
            current->next = elem;
        *beg = *beg ? *beg : elem;
        current = elem;
    }
    free(buf);
    return (EXIT_SUCCESS);
}
