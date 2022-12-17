/*
** EPITECH PROJECT, 2020
** PRINTF_P
** File description:
** PRINTF_P
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int cpt_len(unsigned long nbr)
{
    int i = 0;

    while (nbr / ull_power(16, i) > 0)
        ++i;
    if (i == 0)
        ++i;
    return i;
}

static int ret_value(int zeros, int spaces)
{
    return (zeros > 0 ? zeros : 0) + (spaces > 0 ? spaces : 0) + 2;
}

int print_pointer(va_list *ptr_list, char const *format)
{
    unsigned long ptr = va_arg(*ptr_list, unsigned long);
    int len = cpt_len(ptr);
    char flags[5];
    int spaces;
    int zeros;

    decode_flag(flags, format[0]);
    if (format[2])
        zeros = format[2] - len;
    else
        zeros = flags[3] * (format[1] - (len + 2));
    spaces = format[1] - len - 2 - (zeros > 0) * zeros;
    padd_spaces(!flags[0] * spaces);
    my_putstr("0x");
    padd_zeros(zeros);
    my_put_unbr_base(ptr, 16);
    padd_spaces(flags[0] * spaces);
    return len + ret_value(zeros, spaces);
}
