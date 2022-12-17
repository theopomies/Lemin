/*
** EPITECH PROJECT, 2020
** PADDING_FUNCS
** File description:
** PADDING_FUNCS
*/

#include "my.h"

void padd_spaces(int nbr)
{
    for (int i = 0; i < nbr; i++)
        my_putchar(' ');
}

void padd_zeros(int nbr)
{
    for (int i = 0; i < nbr; i++)
        my_putchar('0');
}
