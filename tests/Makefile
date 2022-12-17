##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for criterion tests
##

include ./../mk/source.mk

RM				=	rm -f

CFLAGS			=	-W -Wall -Wextra --coverage ##-Werror
CPPFLAGS		=	-I ../include
LDFLAGS			=	-lcriterion --coverage

SRC_TEST		=	addition.c						\

DIR_SRC			=	./../src/
DIR_LIB			=	./../lib/

OBJ_SRC			=	$(addprefix $(DIR_SRC), $(SRC:.c=.o))
OBJ_LIB			=	$(addprefix $(DIR_LIB), $(LIB:.c=.o))
OBJ_SRC_TEST	=	$(SRC_TEST:.c=.o)

# DIR_GCOVR		=

DIR_BINARY_TEST	=	..
BINARY_TEST		=	$(DIR_BINARY_TEST)/unit_tests

$(BINARY_TEST):	$(OBJ_SRC) $(OBJ_LIB) $(OBJ_SRC_TEST)
	$(CC) $^ -o $@ $(LDFLAGS)
	./$(BINARY_TEST)

clean:
	$(RM) $(OBJ_SRC:.o=.gcda) $(OBJ_SRC:.o=.gcno) $(OBJ_LIB:.o=.gcda) $(OBJ_LIB:.o=.gcno) $(OBJ_SRC_TEST) *.gc*

fclean:	clean
	$(RM) $(BINARY_TEST)

#	gcovr:	$(BINARY_TEST)