/*
** EPITECH PROJECT, 2020
** MY_STR_ISUPPER
** File description:
** This file is my task14 for the 6th day
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
    return 1;
}
