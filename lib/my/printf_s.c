/*
** EPITECH PROJECT, 2020
** PRINTF_S
** File description:
** PRINTF_S
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

int print_str(va_list *str_list, char const *format)
{
    int i = 0;
    char *str = va_arg(*str_list, char *);
    int len = my_strlen(str);
    char flags[5];
    int min = len < format[2] || format[2] <= 0 ? len : format[2];

    decode_flag(flags, format[0]);
    if (!flags[0] && format[1])
        for (int j = min; j < format[1]; j++)
            my_putchar(' ');
    for (; i < min; i++)
        my_putchar(str[i]);
    if (flags[0] && format[1])
        for (int j = min; j < format[1]; j++)
            my_putchar(' ');
    return min > format[1] ? min : format[1];
}
