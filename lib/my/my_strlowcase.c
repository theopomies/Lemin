/*
** EPITECH PROJECT, 2020
** MY_STRLOWCASE
** File description:
** This file is my task09 for the 6th day
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}
