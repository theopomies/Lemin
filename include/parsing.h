/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** parsing
*/

#ifndef PARSING_H_
#define PARSING_H_

typedef struct input_s
{
    char *line;
    int type;
    struct input_s *next;
} input_t;

enum type
{
    ANTS,
    ROOMS,
    PIPES
};
#include "lemin.h"
int get_input(input_t **beg);
void destroy_input(input_t *input);
int valid(char *buff, int *type, int read);
void remove_comments(input_t **input);
void fill_types(input_t *input);
int fill_lemin(lemin_t *lemin, input_t *input);
int is_valid_room(char *buff);
int fill_rooms(char **room_names, input_t *input, int size);
void destroy_room_names(char **room_names, int size);
int count_rooms(input_t *input);
int fill_matrix(lemin_t *lemin, input_t *input);
void destroy_matrix(int **matrix, int size);
#endif /* PARSING_H_ */
