/*
** EPITECH PROJECT, 2020
** MY_PRINT_F
** File description:
** MY_PRINT_F int uint
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>

void my_put_unbr_base(unsigned long long nb, unsigned int base)
{
    int units;
    char offset = 'a';

    if (base == 160) {
        offset = 'A';
        base = 16;
    }
    if (nb < base && nb < 10)
        my_putchar(nb + '0');
    if (nb < base && nb > 9)
        my_putchar(nb - 10 + offset);
    if (nb >= base) {
        units = nb % base;
        my_put_unbr_base(nb / base, base * (offset == 'A' ? 10 : 1));
        if (base == 16)
            my_putchar(units + (units < 10 ? '0' : offset - 10));
        else
            my_putchar(units + '0');
    }
}

void my_put_nbr_base(long long nb, int base)
{
    int units;
    char offset = 'a';
    int sign = nb < 0 ? -1 : 1;

    if (base == 160) {
        offset = 'A';
        base = 16;
    }
    if (nb > -1 * base && nb > -10 && nb < base && nb < 10)
        my_putchar(nb * sign + '0');
    if (nb < base && nb > -1 * base && (nb > 9 || nb < -9))
        my_putchar(nb * sign - 10 + offset);
    if (nb >= base || nb <= -1 * base) {
        units = (nb % base) * sign;
        my_put_nbr_base((nb / base) * sign, base * (offset == 'A' ? 10 : 1));
        if (base == 16)
            my_putchar(units + (units < 10 ? '0' : offset - 10));
        else
            my_putchar(units + '0');
    }
}

unsigned long long ull_power(unsigned long nb, int pwr)
{
    if (pwr < 0)
        return 0;
    if (pwr == 0)
        return 1;
    return (nb * ull_power(nb, pwr - 1));
}

long long ll_power(int nb, int pwr)
{
    if (pwr < 0)
        return 0;
    if (pwr == 0)
        return 1;
    return (nb * ll_power(nb, pwr - 1));
}
