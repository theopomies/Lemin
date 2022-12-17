/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** my_itoa
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static void fill_nbr(char *nbr, int sign, int i, int size)
{
    for (int j = size - 1; j >= 0; j--) {
        if (j == 0 && sign == -1)
            nbr[j] = '-';
        else
            nbr[j] = (i % 10) * sign + '0';
        i = i / 10;
    }
}

char *my_itoa(int i)
{
    char *nbr = i == 0 ? my_strdup("0") : NULL;
    int size = i < 0 ? 1 : 0;
    int cp_i = i < 0 ? -1 * i : i;
    int sign = i < 0 ? -1 : 1;

    if (i == 0)
        return nbr;
    free(nbr);
    while (cp_i != 0) {
        cp_i = cp_i / 10;
        ++size;
    }
    if ((nbr = malloc(sizeof(char) * (size + 1))) == NULL)
        return NULL;
    nbr[size] = '\0';
    fill_nbr(nbr, sign, i, size);
    return nbr;
}
