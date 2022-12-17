/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

typedef struct lemin_s
{
    int ants;
    int vertices;
    char **room_names;
    int **adjacency_matrix;
    int **paths;
} lemin_t;

#endif /* !LEMIN_H_ */
