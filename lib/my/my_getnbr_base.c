/*
** EPITECH PROJECT, 2020
** MY_GETNBR_BASE
** File description:
** This file is my Task19 for the 6th day
*/

int my_compute_power_rec(int nb, int power);

int my_str_isprintable(char const *str);

int my_strlen(char const *str);

static int str_not_in_base(int nb, char const *str, char const *base)
{
    if (str[nb] == '-' || str[nb] == '+')
        return 0;
    for (int i = 0; base[i] != '\0'; i++) {
        if (str[nb] == base[i])
            return 0;
    }
    return 1;
}

static int get_pwr_str(char const *str)
{
    int pwr = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '-' && str[i] != '+')
            pwr++;
    }
    return pwr;
}

static int is_valid_base_str(char const *str, char const *base)
{
    if (!my_str_isprintable(str) || !my_str_isprintable(base)) {
        return 0;
    }
    if (my_strlen(str) == 0 || my_strlen(base) == 0)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str_not_in_base(i, str, base))
            return 0;
    }
    if (get_pwr_str(str) == -1)
        return 0;
    return 1;
}

static int add_to_nbr(char const *str, char const *base, int nb, int pwr)
{
    int value_in_base;
    int nbr_base = my_strlen(base);

    for (int j = 0; base[j] != '\0'; j++) {
        if (str[nb] == base[j]) {
            value_in_base = j;
        }
    }
    return (my_compute_power_rec(nbr_base, pwr) * value_in_base);
}

int my_getnbr_base(char const *str, char const *base)
{
    int pwr;
    long sign = 1;
    long long nbr = 0;

    if (!is_valid_base_str(str, base))
        return 0;
    pwr = get_pwr_str(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            sign *= -1;
        if (str[i] != '-' && str[i] != '+') {
            nbr += add_to_nbr(str, base, i, pwr);
            pwr--;
        }
        if (nbr * sign < -2147483648 || nbr * sign > 2147483647)
            return 0;
    }
    return nbr * sign;

}
