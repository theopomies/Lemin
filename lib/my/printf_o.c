/*
** EPITECH PROJECT, 2020
** PRINTF_O
** File description:
** PRINTF_O
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int cpt_len(unsigned long long nbr)
{
    int i = 0;

    while (nbr / ull_power(8, i) > 0)
        ++i;
    if (i == 0)
        ++i;
    return i;
}

static int ret_value(int zeros, int spaces, char *flags, int nbr)
{
    return (zeros > 0 ? zeros : 0) + (spaces > 0 ? spaces : 0) +
        (flags[4] && nbr && zeros < 1);
}

int print_octal(va_list *oct_list, char const *format)
{
    unsigned long long oct = get_unbr_casted(oct_list, format[3]);
    int len = cpt_len(oct);
    char flags[5];
    int spaces;
    int zeros;

    decode_flag(flags, format[0]);
    if (format[2])
        zeros = format[2] - len;
    else
        zeros = flags[3] * (format[1] - len) - (flags[4] && oct);
    spaces =
        format[1] - len - (zeros > 0) * zeros - (flags[4] && oct && zeros < 1);
    padd_spaces(!flags[0] * spaces);
    if (flags[4] && oct != 0 && zeros < 1)
        my_putchar('0');
    padd_zeros(zeros);
    my_put_unbr_base(oct, 8);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces, flags, oct);
}
