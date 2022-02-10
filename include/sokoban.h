/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** navy.h
*/

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

struct count {
    int count;
    int count2;
    int posx_o;
    int posy_o;
};

int my_putchar(char c);
char my_putstr(char *str);
int  my_strlen(char *str);
int test_char(char *string);
int	strnbline(char *str);
int	strlencharline(char *str);
int sokoban_start(char *extend, char **tab);
char **down(char **tab, int, struct count *);
char **right(char **tab, int, struct count *);
char **left(char **tab, int, struct count *);
char **up(char **tab, int, struct count *);
int end_or_not(char **tab, char *str, struct count *);
char *my_realloc(char *buff, char *fullbuffer, int len, char *extend);