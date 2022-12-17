/*
** EPITECH PROJECT, 2020
** MY_H
** File description:
** my_h
*/

#ifndef MY_H_
#define MY_H_

int number(char const **);

void my_free_word_array(char **word_array);

int my_printf(char const *, ...);

int my_c_in_str(char, char const *);

char *my_itoa(int);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr_base(char const *str, char const *base);

int str_not_in_base(int nb, char const *str, char const *base);

int my_getnbr(char const *str);

int my_isneg(int n);

int my_is_prime(int nb);

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *base);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *tab, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

char *convert_base(char const *nbr, char const *base_from, char const *base_to);

int my_show_word_array(char * const *tab);

char **my_str_to_word_array(char const *str);

char *my_strdup(char const *src);

int my_getnbr_ex(char const *str);

void my_swap_pointers(char **p1, char **p2);

#endif /* MY_H_ */
