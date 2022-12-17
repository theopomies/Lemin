##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##
CC	=	gcc

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I.

%.o : %.c
	gcc $(CFLAGS) -c $<


NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp my.h ../../include/my.h
	cp $(NAME) ../$(NAME)

clean:
	rm -f $(wildcard *.o)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean all
