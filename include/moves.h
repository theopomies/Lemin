/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** moves
*/

#ifndef MOVES_H_
#define MOVES_H_

typedef struct turn_info_s
{
    int turn;
    int *ants;
    int ant_count;
    int paths_count;
} turn_info_t;
#include "lemin.h"
void print_ants_move(lemin_t *lemin);

#endif /* MOVES_H_ */
