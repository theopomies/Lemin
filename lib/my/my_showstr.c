/*
** EPITECH PROJECT, 2020
** MY_SHOWSTR
** File description:
** This file is my task20 for the 6th day
*/

#include <unistd.h>

int my_str_isprintable(char const *str);

int my_putnbr_base(int nbr, char const *base);

int my_strlen(char const *str);

void my_putchar(char c);

static void handle_under_nine(char c)
{
    if (c < 16)
        my_putchar('0');
}

int my_showstr(char const *str)
{
    char my_char[] = " ";

    for (int i = 0; str[i] != '\0'; i++) {
        my_char[0] = str[i];
        if (my_str_isprintable(my_char))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            handle_under_nine(str[i]);
            my_putnbr_base(str[i], "0123456789abcdef");
        }
    }
    return 0;
}
