##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib/my
##

SRC	=	./my_putchar.c	\
		./my_strncpy.c	\
		./my_strlen.c	\
		./my_str_to_word_array.c	\
		./my_put_nbr.c	\
		./my_putstr.c	\
		./my_getnbr_modified.c	\
		./my_strcmp.c	\
		./my_strcat.c	\
		./my_duoputstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)
	rm ./*.o

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ./../../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
