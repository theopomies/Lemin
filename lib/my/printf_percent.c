/*
** EPITECH PROJECT, 2020
** MY_PRINTF
** File description:
** My_printf funcs
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>

int print_percent(va_list *useless, char const *format)
{
    my_putchar('%');
    return 1;
}
