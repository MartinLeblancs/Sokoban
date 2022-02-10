/*
** EPITECH PROJECT, 2020
** char.c
** File description:
** char.c
*/

#include "../include/sokoban.h"


int	strlencharline(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    return (count);
}

int	strnbline(char *str)
{
    int	i = 0;
    int count = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            count = count + 1;
        i = i + 1;
    }
    if (str[i - 1] == '\n')
        count = count - 1;
    return (count);
}

int test_char(char *string)
{
    int i = 0;

    while (string[i] != '\0')
    {
        if (string[i] != '\n' && string[i] != '#'
            && string[i] != 'X' && string[i] != 'O'
            && string[i] != 'P' && string[i] != ' ')
        {
            write(2, "Error in file\n", 15);
            exit (84);
        }
        i++;
    }
}
