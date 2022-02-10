##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	*.c

OBJ	=	*.o

NAME	=	libmy.a

MY	=	my.h

all:		build clean

build:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(MY) ../../include/

clean:
	rm -f $(OBJ)
