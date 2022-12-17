/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** my_free_word_array
*/

#include <stdlib.h>

void my_free_word_array(char **word_array)
{
    for (int i = 0 ; word_array[i] != NULL ; i++)
        free(word_array[i]);
    free(word_array);
}
