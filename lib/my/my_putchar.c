/*
** EPITECH PROJECT, 2020
** MY_PUTCHAR
** File description:
** This file contains my_putchar function
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
