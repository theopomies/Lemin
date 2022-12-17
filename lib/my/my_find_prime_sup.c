/*
** EPITECH PROJECT, 2020
** MY_FIND_PRIME_SUP
** File description:
** This file is my task07 for the 5th day
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    long long_nb = nb;

    if (nb < 3)
        return 2;
    for (long i = long_nb; i < long_nb * 2; i++) {
        if (my_is_prime(i))
            return i;
    }
    return 0;
}
