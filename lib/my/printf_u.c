/*
** EPITECH PROJECT, 2020
** PRINTF_U
** File description:
** PRINTF_U
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int unbr_len(unsigned long long nbr)
{
    int i = 0;

    while (nbr / ull_power(10, i) > 0)
        ++i;
    if (nbr == 0)
        i = 1;
    return i;
}

static int ret_value(int zeros, int spaces)
{
    return (zeros > 0 ? zeros : 0) + (spaces > 0 ? spaces : 0);
}

int print_uint(va_list *nbr_list, char const *format)
{
    unsigned long long nbr = get_unbr_casted(nbr_list, format[3]);
    int len = unbr_len(nbr);
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
    my_put_unbr_base(nbr, 10);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces);
}
