/*
** EPITECH PROJECT, 2020
** MY_PRINTF
** File description:
** MY_PRINTF
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H
#include <stdarg.h>
void padd_zeros(int);

void padd_spaces(int);

void handle_sign(int, char, char);

int nbr_len(long long, int);

int unbr_len(unsigned long long);

long long get_unbr_casted(va_list *, char);

long long get_nbr_casted(va_list *, char);

unsigned long long ull_power(unsigned long, int);

long long ll_power(int, int);

void decode_flag(char *, char);

char handle_length(int *, char const **);

char handle_precision(int *, char const **);

char handle_flags(int *, char const **);

int handle_width(int *, char const **);

int handle_type(int *, char const *, va_list *, char const *);

int number(char const **);

int my_printf(char const *, ...);

int print_int(va_list *, char const *);

int print_octal(va_list *, char const *);

int print_char(va_list *, char const *);

int print_hex(va_list *, char const *);

int print_hex_cap(va_list *, char const *);

int print_uint(va_list *, char const *);

int print_str(va_list *, char const *);

int show_str_oct(va_list *, char const *);

int print_bin(va_list *, char const *);

int print_pointer(va_list *, char const *);

int print_percent(va_list *, char const *);

unsigned long u_my_compute_power_rec(unsigned int, int);

long long l_my_compute_power_rec(int, int);

void my_put_unbr_base(unsigned long long, unsigned int);

void my_put_nbr_base(long long, int);

#endif
