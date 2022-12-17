/*
** EPITECH PROJECT, 2020
** MY_PUTNBR_BASE
** File description:
** This file is my task18 for the 6th day
*/

#include <unistd.h>

void my_putchar(char c);

int my_str_isprintable(char const *str);

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int power);

static void print_nbr_base(int pwr, int nbr, char const *base, int sign)
{
    long long current;
    int nbr_base = my_strlen(base);

    for (; pwr >= 0; pwr--) {
        current = (nbr / my_compute_power_rec(nbr_base, pwr)) * sign;
        nbr -= (current * my_compute_power_rec(nbr_base, pwr) * sign);
        my_putchar(base[current]);
    }
}

int my_putnbr_base(int nbr, char const *base)
{
    long sign = 1;
    int nbr_base = my_strlen(base);
    int pwr = 0;
    long nb = nbr;

    if (!my_str_isprintable(base) || nbr_base == 0)
        return 1;
    if (nb < 0) {
        my_putchar('-');
        sign = -1;
    }
    while (my_compute_power_rec(nbr_base, pwr) <= nb * sign) {
        pwr++;
    }
    if (pwr > 0)
        pwr--;
    print_nbr_base(pwr, nbr, base, sign);
    return 0;
}
