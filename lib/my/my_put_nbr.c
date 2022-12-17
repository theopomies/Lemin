/*
** EPITECH PROJECT, 2020
** MY_PUT_NBR
** File description:
** This file is my task07 for the 3rd day
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int units;
    int sign = 1;

    if (nb < 0 && sign == 1) {
        my_putchar(45);
        sign = -1;
    }
    if (nb > -10 && nb < 10)
        my_putchar(nb * sign + 48);
    else {
        units = nb % 10;
        my_put_nbr(nb / 10 * sign);
        my_putchar(sign * units + 48);
    }
    return 0;
}