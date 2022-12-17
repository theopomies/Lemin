/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** predecessor_to_path
*/

#include "path_finding.h"
#include "my.h"

int compute_path_len_from_predecessor(int *predecessor)
{
    int len = 1;
    int p = predecessor[1];

    while (p != -1) {
        ++len;
        p = predecessor[p];
    }
    return (len);
}

void predecessor_to_path(int *predecessor, int *path, int steps)
{
    int p = 1;

    for (int i = steps - 1; i >= 0; --i) {
        path[i] = p;
        p = predecessor[p];
    }
}
