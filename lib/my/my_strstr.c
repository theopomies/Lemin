/*
** EPITECH PROJECT, 2020
** MY_STRSTR
** File description:
** This file is my task05 for the 6th day
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n);

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int len_to_find = my_strlen(to_find);
    int len_str = my_strlen(str);

    if (len_to_find == 0)
        return &str[0];
    if (len_to_find > len_str)
        return NULL;
    for (int i = 0; i < len_str; i++) {
        if (my_strncmp(&str[i], to_find, len_to_find) == 0)
            return &str[i];
    }
    return NULL;
}
