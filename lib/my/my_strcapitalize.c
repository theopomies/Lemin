/*
** EPITECH PROJECT, 2020
** MY_STRCAPITALIZE
** File description:
** This file is my task10 for the 6th day
*/

static void lower_char_if_needed(char *str, int i, int previous_is_letter)
{
    if (i == 0)
        return;
    if (previous_is_letter)
        str[i] += 32;
    else if (str[i - 1] < 58 && str[i - 1] > 47)
        str[i] += 32;
}

static void up_char_if_needed(char *str, int i, int previous_is_letter)
{
    if (i == 0) {
        str[i] -= 32;
        return;
    }
    if (previous_is_letter)
        return;
    if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == ' ')
        str[i] -= 32;
}

char *my_strcapitalize(char *str)
{
    int previous_is_letter = 0;
    int done = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            up_char_if_needed(str, i, previous_is_letter);
            previous_is_letter++;
            done++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && !done) {
            lower_char_if_needed(str, i, previous_is_letter);
            previous_is_letter++;
            done++;
        }
        if (!done) {
            previous_is_letter = 0;
        }
        done = 0;
    }
    return str;
}
