##
## Makefile for my in /home/leprov_a//depot/42sh/src/config/lib
## 
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
## 
## Started on  Sun Apr 15 21:18:57 2012 alexis leprovost
##

NAME	=	libmy.a

CFLAGS	=	-Wextra -Werror -I$(INC)

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

INC	=	../includes/

RM	=	rm -f

all:	$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all