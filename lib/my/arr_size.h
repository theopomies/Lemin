/*
** EPITECH PROJECT, 2020
** ARR_SIZE
** File description:
** ARR_SIZE
*/

#ifndef ARR_SIZE_H_
#define ARR_SIZE_H_
#include <stdarg.h>
#include "my_printf.h"

char FLAGS_ARR[] = "-+ 0#";

#define FLAGS_ARR_SIZE 5

typedef struct type
{
    char const *type;
    int (*fptr)(va_list *, char const *);
} type_t;

type_t TYPES_ARR[] =
{
    {"di", &print_int},
    {"o", &print_octal},
    {"x", &print_hex},
    {"X", &print_hex_cap},
    {"u", &print_uint},
    {"c", &print_char},
    {"s", &print_str},
    {"%", &print_percent},
    {"S", &show_str_oct},
    {"b", &print_bin},
    {"p", &print_pointer}
};

#define TYPES_ARR_SIZE (sizeof(TYPES_ARR) / sizeof(type_t))

#endif /* ARR_SIZE_H_ */
