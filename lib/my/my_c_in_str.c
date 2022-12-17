/*
** EPITECH PROJECT, 2020
** MY_C_IN_STR
** File description:
** MY_C_IN_STR returns 0 if c isnt in str or index + 1 of c in str
*/

int my_c_in_str(char c, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i + 1;
    return 0;
}