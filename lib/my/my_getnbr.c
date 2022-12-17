/*
** EPITECH PROJECT, 2020
** MY_GETNBR
** File description:
** This file is my task05 for the 4th day
*/

int my_strlen(char const *str);

static void handle_sign(char c, int *sign)
{
    if (c == '-') {
        *sign *= -1;
    }
    else if (c != '+' && (c < 48 || c > 57)) {
        *sign = 1;
    }
}

int my_getnbr(char const *str)
{
    int done = 0;
    long long nbr = 0;
    int sign = 1;
    int got_nbr = 0;

    for (int i = 0; i < my_strlen(str) && done == 0; i++) {
        if (str[i] >= 48 && str[i] < 58) {
            nbr = nbr * 10 + str[i] - 48;
            got_nbr++;
        } else if (got_nbr)
            done = 1;
        if (!done)
            handle_sign(str[i], &sign);
    }
    nbr *= sign;
    if (nbr > 2147483647 || nbr < -2147483648 || got_nbr > 10)
        return 0;
    return nbr;
}
