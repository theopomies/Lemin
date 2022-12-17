/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** main
*/

#include "lemin.h"
#include "moves.h"
#include "my.h"
#include "parsing.h"
#include "path_finding.h"
#include <stdio.h>
#include <stdlib.h>

static void destroy_lemin(lemin_t *lemin)
{
    destroy_room_names(lemin->room_names, lemin->vertices);
    destroy_paths(lemin->paths);
    destroy_matrix(lemin->adjacency_matrix, lemin->vertices);
}

void print_summary(input_t *input)
{
    my_printf(
        "#number_of_ants\n%s%c", input ? input->line : "", input ? '\n' : '\0');
    input = input ? input->next : NULL;
    my_printf("#rooms\n");
    while (input && input->type == ROOMS) {
        my_printf("%s\n", input->line);
        input = input->next;
    }
    my_printf("#tunnels\n");
    while (input && input->type == PIPES) {
        my_printf("%s\n", input->line);
        input = input->next;
    }
    my_printf("#moves\n");
}

static int start_filling(lemin_t *lemin, input_t *input)
{
    int ret = 0;

    fill_types(input);
    ret += fill_lemin(lemin, input);
    if (!ret)
        ret += fill_matrix(lemin, input);
    return (ret);
}

int main(void)
{
    input_t *input = NULL;
    lemin_t lemin;
    int ret = 0;

    lemin.paths = NULL;
    get_input(&input);
    remove_comments(&input);
    if (!input) {
        print_summary(NULL);
        return (84);
    }
    ret += start_filling(&lemin, input);
    lemin.paths = ret ? NULL : get_paths(&lemin);
    print_summary(input);
    if (input && lemin.paths && !ret) {
        print_ants_move(&lemin);
        destroy_lemin(&lemin);
    }
    destroy_input(input);
    return (ret ? 84 : 0);
}
