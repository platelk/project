##
## Makefile for 42sh in /home/leprov_a//depot/42sh/src/config
## 
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
## 
## Started on  Sun Apr 15 20:02:07 2012 alexis leprovost
##

NAME=	libedit.a

CFLAGS=	-Werror -Wall -Wextra -I$(INC) -g

SRC=	$(wildcard ./src/*.c)

OBJ=	$(SRC:.c=.o)

INC=	../../include/.

RM=	rm -f

LINK=	./../

TEST=	$(wildcard ../env/src/*.c \
		   ../config/src/*.c \
		   ../my/src/*.c \
		   ../history/src/*.c \
		   ../globing/globing/globing.c \
		   ../globing/globing/utils.c)


TEST+=	main.c

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@cp $(NAME) $(LINK)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
	$(RM) test

test:
	gcc -o test $(TEST) -L./ -ledit -lcurses $(CFLAGS)

clear:	re test
	@clear
