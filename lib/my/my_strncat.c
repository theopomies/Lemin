/*
** EPITECH PROJECT, 2020
** MY_STRNCAT
** File description:
** This file is my Task03 for the 7th day
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int d_len = my_strlen(dest);
    int i = 0;

    while (i < nb && i < my_strlen(src)) {
        dest[d_len + i] = src[i];
        i++;
    }
    dest[d_len + i] = '\0';
    return dest;
}
