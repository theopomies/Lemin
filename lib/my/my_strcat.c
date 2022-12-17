/*
** EPITECH PROJECT, 2020
** MY_STRCAT
** File description:
** This file is my Task01 for the 7th day
*/

#include <stddef.h>

char my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int d_len;

    if (dest == NULL || src == NULL)
        return NULL;
    d_len = my_strlen(dest);

    for (int i = 0; i <= my_strlen(src); i++)
        dest[d_len + i] = src[i];
    return dest;
}
