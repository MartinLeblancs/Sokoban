/*
** EPITECH PROJECT, 2020
** sokoban_start.c
** File description:
** sokoban_start.c
*/

#include "../include/sokoban.h"

void print_center(char **tab, char *str)
{
    int n;
    int i = 0;

    while (i != strnbline(str) + 1)
    {
        for (n = 0; n < (166 - my_strlen(str)) / 2; n++) {
            printw(" ");
        }
        printw("%s", tab[i]);
        printw("\n");
        i++;
    }
}

int check_o_x(char **tab)
{
    int a = 0;
    int b = 0;

    while (tab[a][b] != 'P') {
        b++;
        if (strlencharline(tab[a]) == b + 1) {
            a++;
            b = 0;
        }
    }
    if (tab[a - 1][b] == 'X' && tab[a - 2][b] == 'O')
        return (1);
    if (tab[a + 1][b] == 'X' && tab[a + 2][b] == 'O')
        return (2);
    if (tab[a][b - 1] == 'X' && tab[a][b - 2] == 'O')
        return (3);
    if (tab[a][b + 1] == 'X' && tab[a][b + 2] == 'O')
        return (4);

    return (0);
}

int sokoban_start(char *extend, char **tab)
{
    int a = 0;
    int b = 0;
    int c;
    int info_o = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();

    print_center(tab, extend);
    struct count *counter = malloc(sizeof(struct count));
    while ((c = getch()) != 'y')
    {
        clear();

        if (c == KEY_LEFT)
            tab = left(tab, info_o, counter);
        if (c == KEY_RIGHT)
            tab = right(tab, info_o, counter);
        if (c == KEY_UP)
            tab = up(tab, info_o, counter);
        if (c == KEY_DOWN)
            tab = down(tab, info_o, counter);
        check_o_x(tab);
        print_center(tab, extend);

        if (end_or_not(tab, extend, counter) == 84) {
            {
                clear();
                free(counter);
                return (0);
            }
        }
    }
}