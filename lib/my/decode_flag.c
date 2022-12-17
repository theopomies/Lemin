/*
** EPITECH PROJECT, 2020
** DEOCDE_FLAG
** File description:
** DECODE_FLAG
*/

void decode_flag(char *res, char flag)
{
    res[0] = !!(flag & 1);
    res[1] = !!(flag & 2);
    res[2] = !!(flag & 4);
    res[3] = !!(flag & 8);
    res[4] = !!(flag & 16);
}
