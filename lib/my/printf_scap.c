/*
** EPITECH PROJECT, 2020
** MY_PRINTF
** File description:
** MY_PRINTF funcs4
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static void show_oct(char const c, int k, int min)
{
    int i = 0;

    while ((c / ull_power(8, i)) > 0)
        ++i;
    if (c == 0)
        i = 1;
    if (k < min) {
        my_putchar('\\');
        ++k;
    }
    if (min - k >= 1)
        my_put_unbr_base(c / 64, 8);
    if (min - k >= 2)
        my_put_unbr_base(c % 64 / 8, 8);
    if (min - k >= 3)
        my_put_unbr_base(c % 64 % 8, 8);
}

static void put_str_oct(char const *str, int min)
{
    int i = 0;
    int printed = 0;

    while (printed < min) {
        if (str[i] >= 32 && str[i] < 127) {
            my_putchar(str[i]);
            ++printed;
        } else {
            show_oct(str[i], printed, min);
            printed += 4;
        }
        ++i;
    }
}

int show_str_oct(va_list *str_list, char const *format)
{
    int i = 0;
    char *str = va_arg(*str_list, char *);
    char flags[5];
    int min;

    decode_flag(flags, format[0]);
    for (int j = 0; str[j]; j++) {
        if (str[j] >= 32 && str[j] < 127)
            ++i;
        else
            i += 4;
    }
    min = i < format[2] || format[2] <= 0 ? i : format[2];
    if (!flags[0] && format[1])
        for (int j = min; j < format[1]; j++)
            my_putchar(' ');
    put_str_oct(str, min);
    if (flags[0] && format[1])
        for (int j = min; j < format[1]; j++)
            my_putchar(' ');
    return min > format[1] ? min : format[1];
}
