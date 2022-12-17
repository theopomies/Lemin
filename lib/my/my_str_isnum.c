/*
** EPITECH PROJECT, 2020
** MY_STR_ISNUM
** File description:
** This file is my task13 for the 6th day
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
