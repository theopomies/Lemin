/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** path_finding
*/

#ifndef PATH_FINDING_H_
#define PATH_FINDING_H_

#define INF 99999
#define NONE -1
#include "lemin.h"
typedef struct bf_result_s
{
    int *distance;
    int *predecessor;
} bf_result_t;

int bellman_ford(
    int vertices, int matrix[vertices][vertices], bf_result_t *result);
void predecessor_to_path(int *predecessor, int *path, int steps);
int compute_path_len_from_predecessor(int *predecessor);
int compute_path_len(int *path);
int compute_turns(int ants, int **paths);
int ants_in_path(int ants, int **paths);
int **get_paths(lemin_t *lemin);
void destroy_result(bf_result_t *result);
int init_result(bf_result_t *result, int vertices);
void sort_paths(int **paths);
int count_paths(int **paths);
void clean_matrix(int v, int **matrix);
void dup_matrix(lemin_t *lemin, int matrix[lemin->vertices][lemin->vertices]);
void update_matrixes(lemin_t *lemin,
    int matrix[lemin->vertices][lemin->vertices], bf_result_t *result, int i);
int find_next(int v, int *vec);
int destroy_paths(int **paths);
int count_paths_from_matrix(lemin_t *lemin);
int compute_path_len_from_matrix(lemin_t *lemin, int i);
#endif /* PATH_FINDING_H_ */
