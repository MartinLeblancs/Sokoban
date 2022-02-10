/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "../../include/sokoban.h"
#include <stddef.h>
#include <stdlib.h>

char *my_realloc(char *buff, char *fullbuffer, int len, char *extend)
{
    //char *new = 0;
    int	i = 0;
    int	compteur = 0;

    extend = malloc(sizeof(char) * (my_strlen(fullbuffer) + len + 1));
    if (extend == NULL)
        exit (84);
    while (fullbuffer != NULL && fullbuffer[i] != '\0'){
        extend[i] = fullbuffer[i];
        i = i + 1 ;
    }
    free(fullbuffer);
    while (buff[compteur] != '\0'){
        extend[i] = buff[compteur];
        i = i + 1;
        compteur = compteur + 1;
    }
    extend[i] = '\0';

    return (extend);
}
