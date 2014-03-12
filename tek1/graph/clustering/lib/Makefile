##
## Makefile for Makefile in /home/guiho_r//workhome/piscine/Makefile
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Mon Oct 24 09:24:56 2011 ronan guiho
## Last update Sun May  6 17:03:40 2012 ronan guiho
##

NAME	=	libmy.a

SRC	=	my_malloc.c \
		is_number.c \
		my_putchar.c \
		my_revstr.c \
		my_put_nbr.c \
		my_getnbr.c \
		my_putstr.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		concat.c \
		my_strcat.c \
		my_strtok.c \
		check_base.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

all:		$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

re:	fclean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)