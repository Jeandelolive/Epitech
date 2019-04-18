##
## EPITECH PROJECT, 2019
## C++ Pool Rush 3
## File description:
## Makefile
##

SRC	=	./src/main.cpp	\
		./src/getKernelVersion.cpp	\
		./src/getHostName.cpp	\
		./src/getUserName.cpp	\
		./src/getOsName.cpp	\
		./src/textMode.cpp	\
		./src/DateTime.cpp	\
		./src/HostUserNames.cpp	\
		./src/KernelOS.cpp	\
		./src/cpu.cpp	\

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC) -I./include/ -lncurses

clean:
		rm -f ./*.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
