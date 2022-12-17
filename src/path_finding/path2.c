/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** path2
*/

#include "path_finding.h"
#include <stdlib.h>

int find_next(int v, int *vec)
{
    for (int i = 0; i < v; ++i)
        if (vec[i])
            return (i);
    return (NONE);
}

int destroy_paths(int **paths)
{
    if (!paths)
        return (1);
    for (int i = 0; paths[i]; ++i)
        free(paths[i]);
    free(paths);
    return (1);
}

int count_paths_from_matrix(lemin_t *lemin)
{
    int count = 0;

    for (int i = 0; i < lemin->vertices; ++i)
        if (lemin->adjacency_matrix[0][i])
            ++count;
    return (count);
}

int compute_path_len_from_matrix(lemin_t *lemin, int i)
{
    int len = 1;
    int **m = lemin->adjacency_matrix;
    int v = lemin->vertices;
    int n = find_next(v, m[i]);

    while (i != 1 && n != -1) {
        ++len;
        i = n;
        n = find_next(v, m[i]);
    }
    return (len);
}

