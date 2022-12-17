/*
** EPITECH PROJECT, 2020
** MY_PUTSTR
** File description:
** This file is my task02 for the 4th day
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
