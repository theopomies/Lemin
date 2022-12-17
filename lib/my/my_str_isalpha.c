/*
** EPITECH PROJECT, 2020
** MY_STR_ISALPHA
** File description:
** This file is my task12 for the 6th day
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return 0;
    }
    return 1;
}
