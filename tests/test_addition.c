/*
** EPITECH PROJECT, 2020
** Xavier DAVID
** File description:
** test_addition_criterion
*/

#include <criterion/criterion.h>
int addition_function(int nb1, int nb2);

Test(test_simple_addition_1, simple_addition_test)
{
    int nb1 = 1;
    int nb2 = 2;

    cr_assert_eq(addition_function(nb1, nb2), 3);
}