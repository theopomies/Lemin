/*
** EPITECH PROJECT, 2020
** PRINTF_FORMAT_HANDLER
** File description:
** PRINTF_FORMAT_HANDLER
*/
#include "arr_size.h"
#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>

char handle_flags(int *idx, char const **fmt)
{
    char res = 0;

    while (my_c_in_str(**fmt, FLAGS_ARR)) {
        res += my_compute_power_rec(2, my_c_in_str(**fmt, FLAGS_ARR) - 1);
        ++(*idx);
        ++(*fmt);
    }
    return res;
}

int handle_width(int *idx, char const **fmt)
{
    char const *beg = *fmt;
    int n = number(fmt);

    if (beg == *fmt)
        return 0;
    *idx += *fmt - beg;
    return n;
}

char handle_precision(int *idx, char const **fmt)
{
    char const *beg = *fmt + 1;
    int n;

    if (**fmt != '.')
        return 0;
    ++(*fmt);
    ++(*idx);
    n = number(fmt);
    if (beg == *fmt)
        return 0;
    *idx += *fmt - beg;
    return n;
}

char handle_length(int *idx, char const **fmt)
{
    if (my_c_in_str(**fmt, "hlzjt")) {
        ++(*idx);
        ++(*fmt);
    } else
        return -1;
    if ((**fmt == 'h' && *(*fmt - 1) == 'h') ||
        (**fmt == 'l' && *(*fmt - 1) == 'l')) {
        ++(*idx);
        ++(*fmt);
        return *(*fmt - 1) - 32;
    }
    return *(*fmt - 1);
}

int handle_type(int *idx, char const *fmt, va_list *args, char const *format)
{
    for (unsigned int i = 0; i < TYPES_ARR_SIZE; i++) {
        if (my_c_in_str(*fmt, TYPES_ARR[i].type)) {
            ++(*idx);
            return TYPES_ARR[i].fptr(args, format);
        }
    }
    return -1;
}
