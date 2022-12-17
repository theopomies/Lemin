/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** fill_matrix
*/

#include "lemin.h"
#include "my.h"
#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>

static int second_room(char *pipe, char **room_names, int size)
{
    int i = 0;
    char buff[256];

    buff[0] = '\0';
    for (; *pipe != '-'; ++pipe);
    ++pipe;
    for (; pipe[i]; ++i);
    my_strncat(buff, pipe, i);
    for (int j = 0; j < size; ++j)
        if (!(my_strcmp(buff, room_names[j])))
            return (j);
    return (-1);
}

static int first_room(char *pipe, char **room_names, int size)
{
    int i = 0;
    char buff[256];

    buff[0] = '\0';
    for (; pipe[i] != '-'; ++i);
    my_strncat(buff, pipe, i);
    for (int j = 0; j < size; ++j)
        if (!(my_strcmp(buff, room_names[j])))
            return (j);
    return (-1);
}

static int fill_pipe(lemin_t *lemin, char *pipe)
{
    int from = first_room(pipe, lemin->room_names, lemin->vertices);
    int to = second_room(pipe, lemin->room_names, lemin->vertices);

    if (from == -1 || to == -1) {
        return (EXIT_FAILURE);
    }
    lemin->adjacency_matrix[from][to] = 1;
    lemin->adjacency_matrix[to][from] = 1;
    return (EXIT_SUCCESS);
}

void destroy_matrix(int **matrix, int size)
{
    if (!matrix)
        return;
    for (int i = 0; i < size && matrix[i]; ++i)
        free(matrix[i]);
    free(matrix);
}

int fill_matrix(lemin_t *lemin, input_t *input)
{
    while (input && input->type != PIPES)
        input = input->next;
    if (!input)
        return (EXIT_FAILURE);
    if (!(lemin->adjacency_matrix = malloc(sizeof(int *) * lemin->vertices)))
        return (EXIT_FAILURE);
    for (int i = 0; i < lemin->vertices; ++i) {
        if (!(lemin->adjacency_matrix[i] =
                    malloc(sizeof(int) * lemin->vertices)))
            destroy_matrix(lemin->adjacency_matrix, lemin->vertices);
        for (int j = 0; j < lemin->vertices; ++j)
            lemin->adjacency_matrix[i][j] = 0;
    }
    for (; input; input = input->next)
        if (fill_pipe(lemin, input->line)) {
            destroy_room_names(lemin->room_names, lemin->vertices);
            destroy_matrix(lemin->adjacency_matrix, lemin->vertices);
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
