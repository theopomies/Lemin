/*
** EPITECH PROJECT, 2020
** PRINTF_B
** File description:
** PRINTF_B
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int cpt_len(unsigned long long nbr, unsigned int base)
{
    int i = 0;

    while (nbr / ull_power(base, i) > 0)
        ++i;
    if (i == 0)
        ++i;
    return i;
}

static int ret_value(int zeros, int spaces)
{
    return (zeros > 0 ? zeros : 0) + (spaces > 0 ? spaces : 0);
}

int print_bin(va_list *bin_list, char const *format)
{
    unsigned long long bin = get_unbr_casted(bin_list, format[3]);
    int len = cpt_len(bin, 2);
    char flags[5];
    int spaces;
    int zeros;

    decode_flag(flags, format[0]);
    if (format[2])
        zeros = format[2] - len;
    else
        zeros = flags[3] * (format[1] - len);
    spaces = format[1] - len - (zeros > 0) * zeros;
    padd_spaces(!flags[0] * spaces);
    padd_zeros(zeros);
    my_put_unbr_base(bin, 2);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces);
}
