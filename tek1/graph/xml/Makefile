##
## Makefile for xml in /home/vink/projet/graph/xml
##
## Made by kevin platel
## Login   <vink@epitech.net>
##
## Started on  Thu May  3 18:09:37 2012 kevin platel
##

NAME		=	xml_parser

LINK		=	xml_src

LINK_LIB	=	xml_lib

INC		=	xml_inc

SRC		=	$(wildcard $(LINK)/src/*.c)

SRC		+=	$(wildcard $(LINK_LIB)/*.c)

SRC		+=	$(wildcard obj_src/*.c)

SRC		+=	main.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

CFLAGS		+=	-I $(INC)

all:	$(NAME)

%.o:	%.c
	$(CC) -c $^ -o $@ -g $(CFLAGS)

$(NAME):	$(OBJ)
	@echo -e "\033[34m-> Begin of compilation ... \n\033[37m"
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[32m\n-> Compilation Success ! \033[37m"

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all