##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

SRC	=	./src/my_ls.c	\
		./src/flag_management/flag_management.c	\
		./src/flag_management/flag_a.c	\
		./src/flag_management/flag_d.c	\
		./src/flag_management/flag_l.c	\
		./src/flag_management/get_information.c	\
		./src/flag_management/print_info.c	\
		./src/flag_management/flag_recursive.c	\
		./src/flag_management/flag_o.c	\
		./src/error.c	\
		./src/usage.c

OBJ	=	$(SRC:.c=.o)

LIBRARY	=	./lib/my/

LIB	=	libmy.a

FLAG	=	-Wall -g -o

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBRARY)
		gcc $(FLAG) $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all
