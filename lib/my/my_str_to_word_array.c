/*
** EPITECH PROJECT, 2020
** MY_STR_TO_WORD_ARRAY
** File description:
** This file is my task04 for the 8th day
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_strlen(char const *str);

static int count_words(char const *str)
{
    int count = 0;
    char c[] = " ";
    int len = my_strlen(str);

    for (int i = 0; i < len;) {
        *c = *(str + i);
        while (!(my_str_isalpha(c) || my_str_isnum(c)) && i < len)
            *c = *(str + i++);
        if (i < len)
            ++count;
        while ((my_str_isalpha(c) || my_str_isnum(c)) && i < len)
            *c = *(str + i++);
    }
    return count;
}

static int word_len(const char *str)
{
    int len = 0;
    char c[] = " ";

    *c = *str;
    while ((my_str_isalpha(c) || my_str_isnum(c)) && *c != '\0')
        *c = *(str + (++len));
    return len;
}

char **my_str_to_word_array(char const *str)
{
    int nword = count_words(str);
    char **arr = malloc(sizeof(char *) * (nword + 1));
    char c[] = " ";
    int j = 0;
    int wordlen;

    *c = *str;
    for (int i = 0; i < nword; i++) {
        *c = *(str + j);
        while (!(my_str_isalpha(c) || my_str_isnum(c)))
            *c = *(str + (++j));
        wordlen = word_len(str + j);
        *(arr + i) = malloc(sizeof(char) * (wordlen + 1));
        for (int k = 0; k < wordlen; k++, j++) {
            *(*(arr + i) + k) = *(str + j);
        }
        *(*(arr + i) + wordlen) = '\0';
    }
    *(arr + nword) = NULL;
    return arr;
}
