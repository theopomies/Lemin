/*
** EPITECH PROJECT, 2020
** MY_PRINTF
** File description:
** MY_PRINTF
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int cpt_len(unsigned long long nbr)
{
    int i = 0;

    while (nbr / ull_power(16, i) > 0)
        ++i;
    if (i == 0)
        ++i;
    return i;
}

static int ret_value(int zeros, int spaces, char *flags, int nbr)
{
    return (zeros > 0 ? zeros : 0) + (spaces > 0 ? spaces : 0) +
        2 * (flags[4] && nbr);
}

int print_hex(va_list *hex_list, char const *format)
{
    unsigned long long hex = get_unbr_casted(hex_list, format[3]);
    int len = cpt_len(hex);
    char flags[5];
    int spaces;
    int zeros;

    decode_flag(flags, format[0]);
    if (format[2])
        zeros = format[2] - len;
    else
        zeros = flags[3] * (format[1] - len) - 2 * (flags[4] && hex);
    spaces = format[1] - len - (zeros > 0) * zeros - 2 * (flags[4] && hex);
    padd_spaces(!flags[0] * spaces);
    if (flags[4] && hex != 0)
        my_putstr("0x");
    padd_zeros(zeros);
    my_put_unbr_base(hex, 16);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces, flags, hex);
}

int print_hex_cap(va_list *hex_list, char const *format)
{
    unsigned long long hex = get_unbr_casted(hex_list, format[3]);
    int len = cpt_len(hex);
    char flags[5];
    int spaces;
    int zeros;

    decode_flag(flags, format[0]);
    if (format[2])
        zeros = format[2] - len;
    else
        zeros = flags[3] * (format[1] - len) - 2 * (flags[4] && hex);
    spaces = format[1] - len - (zeros > 0) * zeros - 2 * (flags[4] && hex);
    padd_spaces(!flags[0] * spaces);
    if (flags[4] && hex != 0)
        my_putstr("0X");
    padd_zeros(zeros);
    my_put_unbr_base(hex, 160);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces, flags, hex);
}
