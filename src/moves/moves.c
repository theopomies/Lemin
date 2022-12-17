/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** moves
*/

#include "moves.h"
#include "my.h"
#include "path_finding.h"
#include <stdlib.h>

static int get_ant_path(int ant_no, int *ants, int path_count)
{
    int k = 0;
    int l = 0;

    if (path_count == 1)
        return (0);
    for (int i = 0, j = 0; i < ant_no; ++j) {
        k = j / path_count + 1;
        l = j % path_count;
        if (k <= ants[l])
            ++i;
    }
    return (l);
}

static int get_ants_first_turn(int ant_no, int *ants, int path_count)
{
    int k = 0;
    int l = 0;

    if (path_count == 1)
        return (ant_no);
    for (int i = 0, j = 0; i < ant_no; ++j) {
        k = j / path_count + 1;
        l = j % path_count;
        if (k <= ants[l])
            ++i;
    }
    return (k);
}

static void print_ant_move(
    int ant_no, turn_info_t *turn_info, lemin_t *lemin, int is_last)
{
    int path_no = get_ant_path(ant_no, turn_info->ants, turn_info->paths_count);
    int path_len = compute_path_len(lemin->paths[path_no]);
    int current_path_pos =
        turn_info->turn -
        get_ants_first_turn(ant_no, turn_info->ants, turn_info->paths_count);
    int has_arrived = current_path_pos >= path_len;
    char *room_name = NULL;

    if (!has_arrived) {
        room_name = lemin->room_names[lemin->paths[path_no][current_path_pos]];
        my_printf("P%d-%s%c", ant_no, room_name, is_last ? '\n' : ' ');
    }
}

static void print_turn(turn_info_t *turn_info, lemin_t *lemin)
{
    int last_ant = 1;

    while (last_ant <= turn_info->ant_count &&
            get_ants_first_turn(last_ant, turn_info->ants,
                turn_info->paths_count) <= turn_info->turn)
        ++last_ant;
    --last_ant;
    for (int i = 1; i <= last_ant; ++i)
        print_ant_move(i, turn_info, lemin, i == last_ant);
}

void print_ants_move(lemin_t *lemin)
{
    turn_info_t turn_info;
    turn_info.ant_count = lemin->ants;
    turn_info.paths_count = count_paths(lemin->paths);
    int ants[turn_info.paths_count];
    int turns = 0;

    for (int i = 0; i < turn_info.paths_count - 1; ++i) {
        ants[i] = ants_in_path(lemin->ants, lemin->paths + i);
        lemin->ants -= ants[i];
    }
    ants[turn_info.paths_count - 1] = lemin->ants;
    turn_info.ants = ants;
    turns = ants[0] + compute_path_len(lemin->paths[0]) - 1;
    for (int t = 1; t <= turns; ++t) {
        turn_info.turn = t;
        print_turn(&turn_info, lemin);
    }
}
