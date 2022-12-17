/*
** EPITECH PROJECT, 2020
** MY_STRUPCASE
** File description:
** This file is my task08 for the 6th day
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}
