/*
** EPITECH PROJECT, 2020
** CONVERT_BASE
** File description:
** This file is my task05
*/

#include <stdlib.h>

int my_getnbr_base(char const *str, char const *base);

int my_compute_power_rec(int nb, int power);

int my_strlen(char const *str);

static int compute_size(long nbr, int nbase)
{
    int size = 1;
    int power = 1;
    int sign = 1;

    if (nbr < 0) {
        sign = -1;
        size++;
    }
    while (my_compute_power_rec(nbase, power++) <= nbr * sign)
        size++;
    return size;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    long nbr_in_dec = my_getnbr_base(nbr, base_from);
    int nbase = my_strlen(base_to);
    int pwr = compute_size(nbr_in_dec, nbase);
    char *converted = malloc(sizeof(char) * (1 + pwr--));
    long current;
    int n = 0;

    if (nbr_in_dec < 0) {
        *(converted + n++) = '-';
        nbr_in_dec *= -1;
        pwr--;
    }
    for (; pwr >= 0; pwr--) {
        current = (nbr_in_dec / my_compute_power_rec(nbase, pwr));
        nbr_in_dec -= (current * my_compute_power_rec(nbase, pwr));
        *(converted + n++) = base_to[current];
    }
    *(converted + n) = '\0';
    return converted;
}
