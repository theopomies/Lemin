/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** remove_comments
*/

#include "my.h"
#include "parsing.h"
#include <stdlib.h>

void fill_types(input_t *input)
{
    if (!input)
        return;
    input->type = ANTS;
    input = input->next;
    while (input && !my_c_in_str('-', input->line)) {
        input->type = ROOMS;
        input = input->next;
    }
    while (input) {
        input->type = PIPES;
        input = input->next;
    }
}

static void sanitize(char *str)
{
    int i = 0;

    if (!(my_strcmp("##start", str) && my_strcmp("##end", str)))
        return;
    for (; str[i] && str[i] != '#'; ++i);
    if (!str[i])
        return;
    for (; str[i - 1] == ' '; --i);
    str[i] = '\0';
}

static void delete_node(input_t *delete)
{
    free(delete->line);
    free(delete);
}

void remove_first_comments(input_t **input)
{
    input_t *next = (*input)->next;
    input_t *delete = NULL;

    while (*input && *(*input)->line == '#') {
        delete = *input;
        *input = next;
        next = *input ? (*input)->next : NULL;
        delete_node(delete);
    }
}

void remove_comments(input_t **beg)
{
    input_t *next = NULL;
    input_t *delete = NULL;
    input_t *input = NULL;

    if (!*beg)
        return;
    remove_first_comments(beg);
    input = *beg;
    next = input ? input->next : NULL;
    for (; next; input = next, next = input ? input->next : NULL) {
        if (*next->line == '#' && (my_strcmp("##start", next->line) &&
                    my_strcmp("##end", next->line))) {
            delete = next;
            next = next->next;
            input->next = next;
            delete_node(delete);
        } else
            sanitize(input->line);
    }
}
