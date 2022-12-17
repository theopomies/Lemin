/*
** EPITECH PROJECT, 2020
** MY_STRNCPY
** File description:
** This file is my 2nd task for the 6th day
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            return dest;
    }
    return dest;
}
