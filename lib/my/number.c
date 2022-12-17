/*
** EPITECH PROJECT, 2020
** NUMBER
** File description:
** number
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int number(char const **str_ptr)
{
    long long nbr = 0;
    int got_nbr = 0;

    for (; **str_ptr >= '0' && **str_ptr <= '9'; (*str_ptr)++) {
        got_nbr++;
        nbr = nbr * 10 + **str_ptr - '0';
    }
    if (nbr > 2147483647 || nbr < -2147483648 || got_nbr > 10)
        return 0;
    return nbr;
}
