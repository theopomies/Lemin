/*
** EPITECH PROJECT, 2020
** MY_STRLEN
** File description:
** This file is my task03 for the 4th day
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != '\0')
        i++;
    return i;
}
