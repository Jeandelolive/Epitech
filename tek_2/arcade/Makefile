##
## EPITECH PROJECT, 2019
## C++ Pool Rush 3
## File description:
## Makefile
##

SRC	=	*.cpp	\

SRC_N = ./lib/*cpp	\

OBJ_N	=	$(SRC_N:.c=.o)

NAME	=	arcade

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) -Wall -Wextra -Werror -pedantic
	g++ -c -fpic $(SRC_N)
	g++ -shared -o libmy_ncurse.so $(OBJ_N)

clean:
	rm -f ./*.o

fclean:		clean
	rm -f $(NAME)

re:		fclean all
