/*
** EPITECH PROJECT, 2020
** MY_COMPUTE_SQUARE_ROOT
** File description:
** This file is my task05 for the 5th day
*/

int my_compute_square_root(int nb)
{
    for (int i = 0; i * i <= nb; i++)
        if (i * i == nb)
            return i;
    return 0;
}
