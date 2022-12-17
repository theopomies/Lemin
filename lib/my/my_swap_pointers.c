/*
** EPITECH PROJECT, 2020
** MY_SWAP_POINTER
** File description:
** This function swaps pointers
*/

#include <stdlib.h>

void my_swap_pointers(char **p1, char **p2)
{
    char *p3;

    p3 = *p1;
    *p1 = *p2;
    *p2 = p3;
}
