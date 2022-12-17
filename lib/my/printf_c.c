/*
** EPITECH PROJECT, 2020
** MY_PRINTF C
** File description:
** MY_PRINTF C
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int print_char(va_list *c, char const *format)
{
    char flag[5];

    decode_flag(flag, format[0]);
    if (!flag[0] && format[1])
        for (int i = 1; i < format[1]; i++)
            my_putchar(' ');
    my_putchar(va_arg(*c, int));
    if (flag[0] && format[1])
        for (int i = 1; i < format[1]; i++)
            my_putchar(' ');
    return (format[1] == 0 ? 1 : format[1]);
}
