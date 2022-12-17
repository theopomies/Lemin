/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** matrix
*/

#include "path_finding.h"

void clean_matrix(int v, int **matrix)
{
    for (int i = 0; i < v; ++i)
        for (int j = 0; j < i; ++j) {
            int min = matrix[i][j] < matrix[j][i] ? matrix[i][j] : matrix[j][i];

            matrix[i][j] -= min;
            matrix[j][i] -= min;
        }
}

void dup_matrix(lemin_t *lemin, int matrix[lemin->vertices][lemin->vertices])
{
    for (int i = 0; i < lemin->vertices; ++i)
        for (int j = 0; j < lemin->vertices; ++j) {
            matrix[i][j] = lemin->adjacency_matrix[i][j];
            lemin->adjacency_matrix[i][j] = 0;
        }
}

void update_matrixes(lemin_t *lemin,
    int matrix[lemin->vertices][lemin->vertices], bf_result_t *result, int i)
{
    lemin->adjacency_matrix[result->predecessor[i]][i] += 1;
    matrix[i][result->predecessor[i]] *= -1;
    matrix[result->predecessor[i]][i] = 0;
    clean_matrix(lemin->vertices, lemin->adjacency_matrix);
}
