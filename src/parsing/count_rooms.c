/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** count_rooms
*/

#include "my.h"
#include "parsing.h"
#include <stdlib.h>

int count_rooms(input_t *input)
{
    int count = 0;
    int start = 0;
    int end = 0;

    for (; input; input = input->next) {
        if (input->type == ROOMS && *input->line != '#')
            ++count;
        if (input->type == ROOMS && !my_strcmp("##start", input->line))
            ++start;
        if (input->type == ROOMS && !my_strcmp("##end", input->line))
            ++end;
    }
    return end + start == 2 && start == 1 ? count : 0;
}
