/*
** EPITECH PROJECT, 2020
** MY_STRNCMP
** File description:
** This file is my task07 for the 6th day
*/

static char *my_strncpy_with_zero(char *dest, char const *src, int n)
{
    int imax = 0;

    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            return dest;
        imax++;
    }
    dest[imax] = '\0';
    return dest;
}

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n)
{
    char my_s1[n];
    char my_s2[n];

    my_strncpy_with_zero(my_s1, s1, n);
    my_strncpy_with_zero(my_s2, s2, n);
    return my_strcmp(my_s1, my_s2);
}
