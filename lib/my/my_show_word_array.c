/*
** EPITECH PROJECT, 2020
** MY_SHOW_WORD_ARRAY
** File description:
** This file is my task03 for the 8th day
*/

#include <stddef.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; *(tab + i) != NULL; i++) {
        my_putstr(*(tab + i));
        my_putchar('\n');
    }
    return 0;
}
