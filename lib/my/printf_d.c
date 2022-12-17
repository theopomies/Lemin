/*
** EPITECH PROJECT, 2020
** MY_PRINT_F
** File description:
** MY_PRINT_F int uint
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void handle_sign(int sign, char flag1, char flag2)
{
    if (sign == -1)
        my_putchar('-');
    if (flag1 && sign == 1)
        my_putchar('+');
    else if (flag2 && sign == 1)
        my_putchar(' ');
}

int nbr_len(long long nbr, int sign)
{
    int i = 0;

    while (nbr / ll_power(10, i) * sign > 0)
        ++i;
    if (nbr == 0)
        i = 1;
    return i;
}

static int ret_value(int zeros, int spaces, int sign, char *flags)
{
    return (zeros > 0 ? zeros : 0) + (spaces > 0 ? spaces : 0) +
            (sign == -1 || flags[1] || flags[2]);
}

int print_int(va_list *nbr_list, char const *format)
{
    long long nbr = get_nbr_casted(nbr_list, format[3]);
    char flags[5];
    int sign = nbr < 0 ? -1 : 1;
    int len = nbr_len(nbr, sign);
    int zeros;
    int spaces;

    decode_flag(flags, format[0]);
    if (format[2])
        zeros = format[2] - len;
    else
        zeros =
            flags[3] * (format[1] - len) - (sign == -1 || flags[1] || flags[2]);
    spaces = format[1] - len - (sign == -1 || flags[1] || flags[2]) -
            (zeros > 0) * zeros;
    padd_spaces(!flags[0] * spaces);
    handle_sign(sign, flags[1], flags[2]);
    padd_zeros(zeros);
    my_put_nbr_base(nbr, 10);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces, sign, flags);
}
