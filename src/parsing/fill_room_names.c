/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** fill_room_names
*/

#include "lemin.h"
#include "my.h"
#include "parsing.h"
#include <stdlib.h>

void destroy_room_names(char **room_names, int size)
{
    for (int i = 0; i < size && room_names[i]; ++i)
        free(room_names[i]);
    free(room_names);
}

static char *get_room(input_t *input, char const *comment)
{
    int len = 0;
    char *name = NULL;

    while (input && my_strcmp(input->line, comment))
        input = input->next;
    if (!input || !input->next || !is_valid_room(input->next->line) ||
        *input->next->line == '#')
        return (NULL);
    input = input->next;
    for (; input->line[len] != ' '; ++len);
    if (!(name = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    name[0] = '\0';
    return (my_strncat(name, input->line, len));
}

static void skip_special_room(input_t **input)
{
    while (!(my_strcmp("##start", (*input)->line) &&
                my_strcmp("##end", (*input)->line)))
        *input = (*input)->next->next;
}

static char *get_regular_room(input_t *input, int index)
{
    int len = 0;
    char *name = NULL;

    skip_special_room(&input);
    for (int i = 0; input && i < index;) {
        if (!(my_strcmp("##start", input->line) &&
                    my_strcmp("##end", input->line)))
            input = input->next->next;
        else {
            input = input->next;
            ++i;
        }
    }
    skip_special_room(&input);
    if (!input || !is_valid_room(input->line))
        return (NULL);
    for (; input->line[len] != ' '; ++len);
    if (!(name = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    name[0] = '\0';
    return (my_strncat(name, input->line, len));
}

int fill_rooms(char **room_names, input_t *input, int size)
{
    if (!(room_names[0] = get_room(input, "##start"))) {
        destroy_room_names(room_names, size);
        return (EXIT_FAILURE);
    }
    if (!(room_names[1] = get_room(input, "##end"))) {
        destroy_room_names(room_names, size);
        return (EXIT_FAILURE);
    }
    for (int i = 2; i < size; ++i) {
        if (!(room_names[i] = get_regular_room(input, i - 2))) {
            destroy_room_names(room_names, size);
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}
