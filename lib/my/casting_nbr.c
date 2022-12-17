/*
** EPITECH PROJECT, 2020
** CASTING_NBRS
** File description:
** CASTING_NBRS
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

long long get_nbr_casted(va_list *list, char type)
{
    switch (type) {
        case 'H':
            return va_arg(*list, int);
        case 'h':
            return va_arg(*list, int);
        case 'l':
            return va_arg(*list, long);
        case 'L':
            return va_arg(*list, long long);
        case 'j':
            return va_arg(*list, intmax_t);
        case 't':
            return va_arg(*list, ptrdiff_t);
        default:
            return va_arg(*list, int);
    }
}

unsigned long long get_unbr_casted(va_list *list, char type)
{
    switch (type) {
        case 'H':
            return va_arg(*list, unsigned int);
        case 'h':
            return va_arg(*list, unsigned int);
        case 'l':
            return va_arg(*list, unsigned long);
        case 'L':
            return va_arg(*list, unsigned long long);
        case 'z':
            return va_arg(*list, size_t);
        default:
            return va_arg(*list, unsigned int);
    }
}
