/*
** EPITECH PROJECT, 2020
** MY_PRINTF
** File description:
** MY_PRINTF
*/

#include "my_printf.h"
#include "my.h"
#include <stdarg.h>
#include <stdio.h>

static int handle_format(int *idx, char const *fmt, va_list *args)
{
    char format[4] = {-1, -1, -1, -1};

    format[0] = handle_flags(idx, &fmt);
    format[1] = handle_width(idx, &fmt);
    format[2] = handle_precision(idx, &fmt);
    format[3] = handle_length(idx, &fmt);
    return handle_type(idx, fmt, args, format);
}

int my_printf(char const *restrict format, ...)
{
    va_list args;
    int printed = 0;
    va_start(args, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
            printed += handle_format(&i, format + i + 1, &args);
        } else {
            my_putchar(format[i]);
            ++printed;
        }
    }
    va_end(args);
    return printed;
}
