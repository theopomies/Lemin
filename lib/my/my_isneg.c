/*
** EPITECH PROJECT, 2020
** MY_ISNEG
** File description:
** This file is my task04 for the 3rd day
*/

void my_putchar(char c);

int my_isneg(int n)
{
    int sign = n < 0 ? 78 : 80;
    my_putchar(sign);
    my_putchar(10);
    return (0);
}
