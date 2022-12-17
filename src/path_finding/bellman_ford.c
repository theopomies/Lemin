/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** bellman_ford
*/

#include "my.h"
#include "path_finding.h"
#include <stdlib.h>

static int contains_negative_cycle(
    int vertices, int current_vertex, int edges[], bf_result_t *result)
{
    for (int e = 0; e < vertices; ++e)
        if (edges[e] && (result->distance[e] >
                            result->distance[current_vertex] + edges[e])) {
            return (1);
        }
    return (0);
}

static void relax_edges(
    int vertices, int current_vertex, int edges[], bf_result_t *result)
{
    for (int e = 0; e < vertices; ++e)
        if (edges[e] && (result->distance[e] >
                result->distance[current_vertex] + edges[e])) {
            result->distance[e] = result->distance[current_vertex] + edges[e];
            result->predecessor[e] = current_vertex;
        }
}

int bellman_ford(
    int vertices, int matrix[vertices][vertices], bf_result_t *result)
{
    for (int v = 0; v < vertices; ++v) {
        result->distance[v] = INF;
        result->predecessor[v] = NONE;
    }
    result->distance[0] = 0;
    for (int i = 0; i < vertices - 1; ++i)
        for (int v = 0; v < vertices; ++v)
            relax_edges(vertices, v, matrix[v], result);
    for (int v = 0; v < vertices; ++v)
        if (contains_negative_cycle(vertices, v, matrix[v], result))
            return (EXIT_FAILURE);

    return (EXIT_SUCCESS);
}

void destroy_result(bf_result_t *result)
{
    free(result->distance);
    free(result->predecessor);
}

int init_result(bf_result_t *result, int vertices)
{
    result->distance = malloc(sizeof(int) * vertices);
    result->predecessor =
        result->distance ? malloc(sizeof(int) * vertices) : NULL;
    if (!result->predecessor) {
        if (result->distance)
            free(result->distance);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
