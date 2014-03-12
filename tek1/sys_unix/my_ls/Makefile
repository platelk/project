##
## Makefile for Makefile in /home/platel_k/projet/my_printf
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 10:22:25 2011 kevin platel
##

NAME	= my_ls

LINK	= source/

SRC	= $(LINK)main.c \
	  $(LINK)get_opt.c \
	  $(LINK)get_link.c \
	  $(LINK)my_sort_list.c \
	  $(LINK)my_sort_by_alpha.c \
	  $(LINK)show_dir.c \
	  $(LINK)list.c \
	  $(LINK)time_cmp.c \
	  $(LINK)rev_list.c \
	  $(LINK)is_dir.c \
	  $(LINK)size_tot.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wextra -ansi -Wall -I include

all:		$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -g -I include -L lib/ -lmy

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) -L lib/ -lmy -g

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
