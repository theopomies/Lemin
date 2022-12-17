/*
** EPITECH PROJECT, 2020
** MY_STR_ISPRINTABLE
** File description:
** This file is my task16 for the 6th day
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            return 0;
    }
    return 1;
}
