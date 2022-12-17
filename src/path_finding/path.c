/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** paths
*/

#include "my.h"
#include "path_finding.h"
#include <stdlib.h>

static int fill_path(int **path, lemin_t *lemin, int v)
{
    int len = compute_path_len_from_matrix(lemin, v);
    int idx = 0;
    int next = find_next(lemin->vertices, lemin->adjacency_matrix[v]);

    if (!(*path = malloc(sizeof(int) * (len + 1))))
        return (EXIT_FAILURE);
    while (v != 1) {
        (*path)[idx] = v;
        v = next;
        next = find_next(lemin->vertices, lemin->adjacency_matrix[v]);
        ++idx;
    }
    (*path)[idx] = 1;
    return (EXIT_SUCCESS);
}

static int fill_paths(int **paths, lemin_t *lemin)
{
    for (int v = 0, i = 0; v < lemin->vertices; ++v) {
        if (lemin->adjacency_matrix[0][v] && fill_path(&paths[i], lemin, v))
            return (EXIT_FAILURE);
        if (lemin->adjacency_matrix[0][v])
            ++i;
    }
    return (EXIT_SUCCESS);
}

static int update_paths(int ***paths, lemin_t *lemin)
{
    int path_count = count_paths_from_matrix(lemin);
    int **new_paths = malloc(sizeof(int *) * (path_count + 1));

    if (!new_paths)
        return (EXIT_FAILURE);
    new_paths[path_count] = NULL;
    if (fill_paths(new_paths, lemin) && destroy_paths(new_paths))
        return (EXIT_FAILURE);
    sort_paths(new_paths);
    if (!*paths ||
        ants_in_path(lemin->ants, *paths) + compute_path_len((*paths)[0]) >
            ants_in_path(lemin->ants, new_paths) +
                compute_path_len(new_paths[0])) {
        destroy_paths(*paths);
        *paths = new_paths;
    } else {
        destroy_paths(new_paths);
        return (1);
    }
    return (0);
}

int **get_paths(lemin_t *lemin)
{
    int matrix[lemin->vertices][lemin->vertices];
    bf_result_t result;
    int **paths = NULL;

    dup_matrix(lemin, matrix);
    if (init_result(&result, lemin->vertices))
        return (NULL);
    bellman_ford(lemin->vertices, matrix, &result);
    while (result.predecessor[1] != NONE) {
        for (int i = 1; i && i != NONE; i = result.predecessor[i])
            update_matrixes(lemin, matrix, &result, i);
        if (update_paths(&paths, lemin)) {
            destroy_result(&result);
            return (paths);
        }
        bellman_ford(lemin->vertices, matrix, &result);
    }
    destroy_result(&result);
    return (paths);
}
