##
## Makefile for Makefile in /home/platel_k/projet/my_printf
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 10:22:25 2011 kevin platel
## Last update Tue Nov 15 14:53:21 2011 kevin platel
##

NAME	= my_printf

SRC	= source/my_printf.c \
	source/main.c \
	source/find_intab.c \
	source/opt_d.c \
	source/opt_s.c \
	source/opt_c.c \
	source/opt_x.c \
	source/opt_X.c \
	source/opt_o.c \
	source/opt_b.c \
	source/opt_S.c \
	source/opt_u.c \
	source/opt_less.c \
	source/opt_mod.c \
	source/opt_p.c \
	source/my_putnbrul_base.c\
	source/init_tab_fun.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -I ~/projet/my_printf

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) -L . -lmy

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)