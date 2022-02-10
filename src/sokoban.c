/*
** EPITECH PROJECT, 2020
** sokoban.c
** File description:
** sokoban.c
*/

#define BUFF_SIZE (2000)

#include "../include/sokoban.h"

char **create_tab(char *string)
{

    int	i = 0;
    int a = 0;
    int b = 0;
    char **tab = NULL;
    int count = 0;

    tab = malloc(sizeof(char *) * (strnbline(string) + 1));
    while (i < strnbline(string) + 1)
    {
        tab[i] = malloc(sizeof(char) * (strlencharline(string) + 1));
        i = i + 1;
    }

    i = 0;
    test_char(string);
    while (string[i] != '\0')
    {
        count++;
        if (string[i] == '\n' || string[i] == '\0')
        {
            count = 0;
            tab[a][b] = '\0';
            a = a + 1;
            b = 0;
        }
        else
        {
            tab[a][b] = string[i];
            b = b + 1;
        }
        i = i + 1;
    }
    return (tab);
}

void free_tab(char **tab, char *extend)
{
    int y = 0;

    for (; y != strnbline(extend) + 1; y++)
        free(tab[y]);
}

int main(int ac, char **av)
{

    int file = 0;
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len = 0;
    char *extend = NULL;
    int i = 0;
    char **tab = NULL;

    if (ac != 2) {
        write (2, "Wrong number of arguments\n", 26);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE : \n\t ./my_sokoban map\n");
        my_putstr("\nmap\n \t file which contains the map, "
        " # : walls, P : player, X : boxes, "
        " O storage places, SPACES : void");
        exit(0);
    }
    else {
    file = open(av[1], O_RDONLY);
    if (file == -1) {
        write(2, "File only\n", 10);
        return (84);
    }

        while ((len = read(file, buff, BUFF_SIZE)) > 0) {
            buff[len] = 0;
            extend = malloc(1);
            extend = my_realloc(buff, extend, len, extend);

            while (i < BUFF_SIZE) {
                buff[i] = '\0';
                i = i + 1;
            }
        }
        buff[offset] = '\0';
        if (len < 0)
            return (84);

        tab = create_tab(extend);
        sokoban_start(extend, tab);

    }
    free_tab(tab, extend);
    free(extend);
    endwin();
    return (0);
}