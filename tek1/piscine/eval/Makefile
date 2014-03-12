##
## Makefile for cat in /home/platel_k//projet/piscine/Jour_13/cat
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Oct 26 11:06:21 2011 kevin platel
## Last update Fri Oct 28 15:51:43 2011 kevin platel
##

NAME	= eval

SRC	= del_one_in_list.c \
	evalexpr.c \
	function.c \
	my_show_list.c \
	add_in_list.c \
	init_list.c \
	my_is_num.c \
	take_nb.c \
	calc.c

CFLAGS	= -g -Wall -Wextra -Werror -ansi -pedantic

all:	$(NAME)

$(NAME):	
	cc  $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re:	fclean $(NAME)