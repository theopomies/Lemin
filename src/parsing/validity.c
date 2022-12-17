/*
** EPITECH PROJECT, 2020
** B-CPE-300-BDX-3-1-lemin-dayana.chetouane
** File description:
** validity
*/

#include "my.h"
#include "parsing.h"

static int is_valid_ant(char *buff, int *type)
{
    if (buff[0] == '#')
        return (1);
    ++(*type);
    if (number(&buff) < 1)
        return (0);
    while (*buff == ' ')
        ++buff;
    if ((*buff && *buff != '#') ||
        (!*buff && *(buff - 1) == ' '))
        return (0);
    return (1);
}

static int invalid_coordinates(char *buff)
{
    char *buff_cp = buff;

    number(&buff);
    if (buff == buff_cp || *buff != ' ')
        return (1);
    ++buff;
    buff_cp = buff;
    number(&buff);
    if (buff == buff_cp)
        return (1);
    while (*buff == ' ')
        ++buff;
    if (*buff != '#' && !*buff && *(buff - 1) == ' ')
        return (1);
    return (0);
}

int is_valid_room(char *buff)
{
    if (buff[0] == '#')
        return (1);
    if (*buff == ' ')
        return (0);
    while (*buff && *buff != ' ')
        ++buff;
    if (!*buff)
        return (0);
    ++buff;
    if (invalid_coordinates(buff))
        return (0);
    return (1);
}

static int is_valid_pipe(char *buff)
{
    if (buff[0] == '#')
        return (1);
    if (*buff == ' ')
        return (0);
    while (*buff && *buff != '-' && *buff != ' ')
        ++buff;
    if (!*buff || *buff == ' ')
        return (0);
    ++buff;
    while (*buff && *buff != ' ')
        ++buff;
    while (*buff == ' ')
        ++buff;
    if (*buff != '#' && !*buff && *(buff - 1) == ' ')
        return (0);
    return (1);
}

int valid(char *buff, int *type, int read)
{
    *(buff + read - 1) = '\0';
    if (*type == ANTS)
        return (is_valid_ant(buff, type));
    if (*type == ROOMS) {
        if (is_valid_room(buff))
            return (1);
        else {
            ++(*type);
            return (is_valid_pipe(buff));
        }
    }
    if (*type == PIPES)
        return (is_valid_pipe(buff));
    return (0);
}
