/*
** EPITECH PROJECT, 2020
** MY_SORT_INT_ARRAY
** File description:
** This file is my task06 for the 4th day
*/

int my_strlen(char const *str);

void my_swap(int *a, int *b);

static void check_min(int num1, int num2, int *tab, int *min)
{
    if (tab[num1] < tab[num2])
        *min = num1;
}

void my_sort_int_array(int *tab, int size)
{
    int min;

    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            check_min(j, min, tab, &min);
        }
        if (min != i)
            my_swap(&tab[min], &tab[i]);
    }
}
