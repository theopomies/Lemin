/*
** EPITECH PROJECT, 2020
** MY_REVSTR
** File description:
** This file is my 3rd task for the 6th day
*/

char *my_revstr(char *str)
{
    char stock;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    for (int i = 0; i < len / 2; i++) {
        stock = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = stock;
    }
    return str;
}
