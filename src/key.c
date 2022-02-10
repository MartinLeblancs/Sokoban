/*
** EPITECH PROJECT, 2020
** key.c
** File description:
** key.c
*/

#include "../include/sokoban.h"

int end_or_not(char **tab, char *str, struct count *counter)
{
    int a = 0;
    int b = 0;
    int the_count = 0;

    while (a <= strnbline(str) - 1)
    {
        if (strlencharline(tab[a]) == b + 1)
        {
            a++;
            b = 0;
        }

        if (tab[a][b] == 'O')
            return (0);
        b++;
        the_count++;

    }
    if (counter->count == 1)
        return (0);
    return (84);

}

char **up(char **tab, int info_o, struct count *counter)
{
    int a = 0;
    int b = 0;

    while (tab[a][b] != 'P')
    {
        b++;
        if (strlencharline(tab[a]) == b + 1) {
            a++;
            b = 0;
        }
    }
    if (counter->count == 1)
    {
        if (tab[a - 1][b] == ' ') {
            tab[a][b] = 'O';
            tab[a - 1][b] = 'P';
            counter->count = 0;
        }
        if (tab[a - 1][b] == '#')
            return (tab);

        if (tab[a - 1][b] == 'O')
        {
            tab[a][b] = 'O';
            tab[a - 1][b] = 'P';
            counter->count = 1;
        }
        if (tab[a - 1][b] == 'X' && tab[a - 2][b] != '#')
        {
            tab[a][b] = 'O';
            tab[a - 1][b] = 'P';
            tab[a - 2][b] = 'X';
            counter->count = 0;
        }
    }
    if (counter->count2 == 2 && tab[a - 1][b] == 'X')
    {
        if (tab[a - 2][b] == '#')
            return (tab);
        if (tab[a - 2][b] == ' ') {
            tab[a][b] = ' ';
            tab[a - 1][b] = 'P';
            tab[a - 2][b] = 'X';
            counter->count = 1;
            counter->count2 = 0;
        }
        if (tab[a - 2][b] == 'O')
        {
            tab[a][b] = ' ';
            tab[a - 1][b] = 'P';
            tab[a - 2][b] = 'X';
            counter->count = 1;
            counter->count2 = 2;
        }
        if (tab[a - 2][b] == 'X')
            return (tab);
    }
    if (tab[a - 1][b] == ' ')
    {
        tab[a][b] = ' ';
        tab[a - 1][b] = 'P';
    }
    if (tab[a - 1][b] == '#')
        return (tab);
    if (tab[a - 1][b] == 'O')
    {
        tab[a][b] = ' ';
        tab[a - 1][b] = 'P';
        counter->count = 1;
    }
    if (tab[a - 1][b] == 'X')
    {
        if (tab[a - 2][b] == 'X')
            return (tab);
        if (tab[a - 2][b] == ' ') {
            tab[a][b] = ' ';
            tab[a - 1][b] = 'P';
            tab[a - 2][b] = 'X';
            if (tab[a - 2][b] == '#')
                return (tab);
        }
        if (tab[a - 2][b] == 'O')
        {
            tab[a][b] = ' ';
            tab[a - 1][b] = 'P';
            tab[a - 2][b] = 'X';
            counter->count2 = 2;
            counter->posx_o = b;
            counter->posy_o = a - 1;
        }
    }

    return (tab);
}

char **left(char **tab, int info_o, struct count *counter)
{
    int a = 0;
    int b = 0;

    while (tab[a][b] != 'P')
    {
        b++;
        if (strlencharline(tab[a]) == b + 1) {
            a++;
            b = 0;
        }
    }
    if (counter->count == 1)
    {
        if (tab[a][b - 1] == ' ') {
            tab[a][b] = 'O';
            tab[a][b - 1] = 'P';
            counter->count = 0;
        }
        if (tab[a][b - 1] == '#')
            return (tab);

        if (tab[a][b - 1] == 'O')
        {
            tab[a][b] = 'O';
            tab[a][b - 1] = 'P';
            counter->count = 1;
        }
        if (tab[a][b - 1] == 'X' && tab[a][b - 2] != '#')
        {
            tab[a][b] = 'O';
            tab[a][b - 1] = 'P';
            tab[a][b - 2] = 'X';
            counter->count = 0;
        }
    }
    if (counter->count2 == 3 && tab[a][b - 1] == 'X')
    {
        if (tab[a][b - 2] == '#')
            return (tab);
        if (tab[a][b - 2] == ' ') {
            tab[a][b] = ' ';
            tab[a][b - 1] = 'P';
            tab[a][b - 2] = 'X';
            counter->count = 1;
            counter->count2 = 0;
        }
        if (tab[a][b - 2] == 'O')
        {
            tab[a][b] = ' ';
            tab[a][b - 1] = 'P';
            tab[a][b - 2] = 'X';
            counter->count = 1;
            counter->count2 = 3;
        }
        if (tab[a][b - 2] == 'X')
            return (tab);
    }
    if (tab[a][b - 1] == ' ')
    {
        tab[a][b] = ' ';
        tab[a][b - 1] = 'P';
    }
    if (tab[a][b - 1] == '#')
        return (tab);
    if (tab[a][b - 1] == 'O')
    {
        tab[a][b] = ' ';
        tab[a][b - 1] = 'P';
        counter->count = 1;
    }
    if (tab[a][b - 1] == 'X')
    {
        if (tab[a][b - 2] == 'X')
            return (tab);
        if (tab[a][b - 2] == ' ') {
            tab[a][b] = ' ';
            tab[a][b - 1] = 'P';
            tab[a][b - 2] = 'X';
            if (tab[a][b - 2] == '#')
                return (tab);
        }
        if (tab[a][b - 2] == 'O')
        {
            tab[a][b] = ' ';
            tab[a][b - 1] = 'P';
            tab[a][b - 2] = 'X';
            counter->count2 = 3;
        }
    }

    return (tab);
}

char **right(char **tab, int info_o, struct count *counter)
{
    int a = 0;
    int b = 0;

    while (tab[a][b] != 'P')
    {
        b++;
        if (strlencharline(tab[a]) == b + 1) {
            a++;
            b = 0;
        }
    }
    if (counter->count == 1)
    {
        if (tab[a][b + 1] == ' ') {
            tab[a][b] = 'O';
            tab[a][b + 1] = 'P';
            counter->count = 0;
        }
        if (tab[a][b + 1] == '#')
            return (tab);

        if (tab[a][b + 1] == 'O')
        {
            tab[a][b] = 'O';
            tab[a][b + 1] = 'P';
            counter->count = 1;
        }
        if (tab[a][b + 1] == 'X' && tab[a][b + 2] != '#')
        {
            tab[a][b] = 'O';
            tab[a][b + 1] = 'P';
            tab[a][b + 2] = 'X';
            counter->count = 0;
        }
    }
    if (counter->count2 == 4 && tab[a][b + 1] == 'X')
    {
        if (tab[a][b + 2] == '#')
            return (tab);
        if (tab[a][b + 2] == ' ') {
            tab[a][b] = ' ';
            tab[a][b + 1] = 'P';
            tab[a][b + 2] = 'X';
            counter->count = 1;
            counter->count2 = 0;
        }
        if (tab[a][b + 2] == 'O')
        {
            tab[a][b] = ' ';
            tab[a][b + 1] = 'P';
            tab[a][b + 2] = 'X';
            counter->count = 1;
            counter->count2 = 4;
        }
        if (tab[a][b + 2] == 'X')
            return (tab);
    }
    if (tab[a][b + 1] == ' ')
    {
        tab[a][b] = ' ';
        tab[a][b + 1] = 'P';
    }
    if (tab[a][b + 1] == '#')
        return (tab);
    if (tab[a][b + 1] == 'O')
    {
        tab[a][b] = ' ';
        tab[a][b + 1] = 'P';
        counter->count = 1;
    }
    if (tab[a][b + 1] == 'X')
    {
        if (tab[a][b + 2] == 'X')
            return (tab);
        if (tab[a][b + 2] == ' ') {
            tab[a][b] = ' ';
            tab[a][b + 1] = 'P';
            tab[a][b + 2] = 'X';
            if (tab[a][b + 2] == '#')
                return (tab);
        }
        if (tab[a][b + 2] == 'O')
        {
            tab[a][b] = ' ';
            tab[a][b + 1] = 'P';
            tab[a][b + 2] = 'X';
            counter->count2 = 4;
        }
    }


    return (tab);
}

char **down(char **tab, int info_o, struct count *counter)
{

    int a = 0;
    int b = 0;

    while (tab[a][b] != 'P')
    {
        b++;
        if (strlencharline(tab[a]) == b + 1) {
            a++;
            b = 0;
        }
    }
    if (counter->count == 1)
    {
        if (tab[a + 1][b] == ' ') {
            tab[a][b] = 'O';
            tab[a + 1][b] = 'P';
            counter->count = 0;
        }
        if (tab[a + 1][b] == '#')
            return (tab);

        if (tab[a + 1][b] == 'O')
        {
            tab[a][b] = 'O';
            tab[a + 1][b] = 'P';
            counter->count = 1;
        }
        if (tab[a + 1][b] == 'X' && tab[a + 2][b] != '#')
        {
            tab[a][b] = 'O';
            tab[a + 1][b] = 'P';
            tab[a + 2][b] = 'X';
            counter->count = 0;
        }
    }
    if (counter->count2 == 5 && tab[a + 1][b] == 'X')
    {
        if (tab[a + 2][b] == '#')
            return (tab);
        if (tab[a + 2][b] == ' ') {
            tab[a][b] = ' ';
            tab[a + 1][b] = 'P';
            tab[a + 2][b] = 'X';
            counter->count = 1;
            counter->count2 = 0;
        }
        if (tab[a + 2][b] == 'O')
        {
            tab[a][b] = ' ';
            tab[a + 1][b] = 'P';
            tab[a + 2][b] = 'X';
            counter->count = 1;
            counter->count2 = 5;
        }
        if (tab[a + 2][b] == 'X')
            return (tab);
    }
    if (tab[a + 1][b] == ' ')
    {
        tab[a][b] = ' ';
        tab[a + 1][b] = 'P';
    }
    if (tab[a + 1][b] == '#')
        return (tab);
    if (tab[a + 1][b] == 'O')
    {
        tab[a][b] = ' ';
        tab[a + 1][b] = 'P';
        counter->count = 1;
    }
    if (tab[a + 1][b] == 'X')
    {
        if (tab[a + 2][b] == 'X')
            return (tab);
        if (tab[a + 2][b] == ' ') {
            tab[a][b] = ' ';
            tab[a + 1][b] = 'P';
            tab[a + 2][b] = 'X';
            if (tab[a + 2][b] == '#')
                return (tab);
        }
        if (tab[a + 2][b] == 'O')
        {
            tab[a][b] = ' ';
            tab[a + 1][b] = 'P';
            tab[a + 2][b] = 'X';
            counter->count2 = 5;
        }
    }


    return (tab);
}


