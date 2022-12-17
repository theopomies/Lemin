/*
** EPITECH PROJECT, 2020
** MY_IS_PRIME
** File description:
** This file is my task06 for the 5th day
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    if (nb < 4)
        return 1;
    for (long i = 2; i * i <= nb; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
