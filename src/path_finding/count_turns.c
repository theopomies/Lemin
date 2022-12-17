/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** count_turns
*/

#include "my.h"
#include "path_finding.h"
#include <stdlib.h>

int count_paths(int **paths)
{
    int count = 0;

    while (paths[count] != NULL)
        ++count;
    return (count);
}

int ants_in_path(int ants, int **paths)
{
    int path_count = count_paths(paths);
    int first_path_len = compute_path_len(paths[0]);
    int sum_of_other_paths = 0;

    if (ants < 1)
        return (0);
    for (int i = 1; i < path_count; ++i)
        sum_of_other_paths += compute_path_len(paths[i]);
    if (!sum_of_other_paths ||
        ants + first_path_len - 1 <= compute_path_len(paths[1]))
        return (ants);
    return ((sum_of_other_paths + ants - (path_count - 1) * first_path_len) /
            path_count + !!((sum_of_other_paths + ants - (path_count - 1) *
            first_path_len) % path_count));
}

int compute_path_len(int *path)
{
    int len = 0;

    while (path[len] != 1)
        ++len;
    return (len + 1);
}

static void swap(int **p1, int **p2)
{
    int len1 = compute_path_len(*p1);
    int len2 = compute_path_len(*p2);
    int *ptr = NULL;

    if (len1 > len2) {
        ptr = *p2;
        *p2 = *p1;
        *p1 = ptr;
    }
}

void sort_paths(int **paths)
{
    int len = count_paths(paths) - 1;

    for (int i = len; i > 0; --i)
        for (int j = 0; j < i; ++j)
            swap(paths + j, paths + j + 1);
}
