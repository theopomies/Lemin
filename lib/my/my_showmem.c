/*
** EPITECH PROJECT, 2020
** MY_SHOWMEM
** File description:
** MEMEMEMEMMEMEEMEMEM
*/

void my_putchar(char c);

int my_compute_power_rec(int n, int p);

int my_putnbr_base(int nbr, char const *base);

int my_str_isprintable(char const *str);

static void put_adress(int nb)
{
    int pwr = 0;

    while (nb >= my_compute_power_rec(16, pwr)) {
        pwr++;
    }
    for (int i = 0; i < 8 - pwr; i++) {
        if ((nb != 0 && i != 0) || (nb == 0 && i != 0))
            my_putchar('0');
    }
    my_putnbr_base(nb * 16, "0123456789abcdef");
    my_putchar(':');
    my_putchar(' ');
}

static void put_values(int nb, char const *str, int size)
{
    int i = 0;

    while (i < 16 && nb + i < size) {
        if (str[i + nb] < 16)
            my_putchar('0');
        my_putnbr_base(str[i + nb], "0123456789abcdef");
        if (i % 2 == 1)
            my_putchar(' ');
        i++;
    }
    while (i < 16) {
        my_putchar(' ');
        my_putchar(' ');
        if (i % 2 == 1)
            my_putchar(' ');
        i++;
    }
}

static void put_str(int nb, char const *str, int size)
{
    char c[] = " ";

    for (int i = 0; i < 16 && nb + i < size; i++) {
        c[0] = str[i + nb];
        if (my_str_isprintable(c) && c[0] != '\0') {
            my_putchar(str[i + nb]);
        } else {
            my_putchar('.');
        }
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i <= size / 16; i++) {
        put_adress(i);
        put_values(i * 16, str, size);
        put_str(i * 16, str, size);
    }
    return 0;
}
