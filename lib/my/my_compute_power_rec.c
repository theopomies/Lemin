/*
** EPITECH PROJECT, 2020
** MY_COMPUTE_POWER_REC
** File description:
** This file is my task04 for the 5th day
*/

int my_compute_power_rec(int nb, int power)
{
    long long res;
    long long longnb = nb;

    if (power < 0)
        return 0;
    if (power == 0)
        return 1;
    res = my_compute_power_rec(nb, power - 1) * longnb;
    if (res > 2147483647 || res < -2147483648)
        return 0;
    return res;
}
