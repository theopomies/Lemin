/*
** EPITECH PROJECT, 2020
** MY_STRDUP
** File description:
** This file is my task01 for the 8th day
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(len + 1);

    for (int i = 0; i < len; i++)
        *(dest + i) = *(src + i);
    dest[len] = '\0';
    return dest;
}
