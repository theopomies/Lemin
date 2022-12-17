/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** fill_lemin
*/

#include "lemin.h"
#include "my.h"
#include "parsing.h"
#include <stdlib.h>

static void get_coordinates(int coordinates[2], char const *line)
{
    while (*line != ' ')
        ++line;
    ++line;
    coordinates[0] = number(&line);
    ++line;
    coordinates[1] = number(&line);
}

static int find_double_coord(int i, int size, int coordinates[size][2])
{
    for (int j = i + 1; j < size; ++j)
        if (coordinates[i][0] == coordinates[j][0] &&
                coordinates[i][1] == coordinates[j][1])
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int find_double_room(int i, int size, char **room_names)
{
    for (int j = i + 1; j < size; ++j)
        if (!my_strcmp(room_names[i], room_names[j]))
                return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int invalid_rooms(char **room_names, input_t *input, int size)
{
    int coordinates[size][2];

    for (int i = 0; i < size - 1; ++i)
        if (find_double_room(i, size, room_names)) {
            destroy_room_names(room_names, size);
            return (EXIT_FAILURE);
        }
    for (int i = 0; i < size && input; input = input->next) {
        if (*input->line != '#') {
            get_coordinates(coordinates[i], input->line);
            ++i;
        }
    }
    for (int i = 0; i < size - 1; ++i)
        if (find_double_coord(i, size, coordinates)) {
            destroy_room_names(room_names, size);
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}

int fill_lemin(lemin_t *lemin, input_t *input)
{
    if (!input)
        return (EXIT_FAILURE);
    lemin->ants = my_getnbr(input->line);
    if (lemin->ants < 1)
        return (EXIT_FAILURE);
    lemin->vertices = count_rooms(input);
    if (lemin->vertices < 2)
        return (EXIT_FAILURE);
    if (!(lemin->room_names = malloc(sizeof(char *) * lemin->vertices)))
        return (EXIT_FAILURE);
    if (fill_rooms(lemin->room_names, input->next, lemin->vertices) ||
        invalid_rooms(lemin->room_names, input->next, lemin->vertices))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
