##
## Makefile for Makefile in /home/mouton_p//colle3
## 
## Made by pierre mouton
## Login   <mouton_p@epitech.net>
## 
## Started on  Sat Oct 29 23:29:16 2011 pierre mouton
## Last update Sun Mar 25 20:46:21 2012 ronan guiho
##

NAME=	libcolle.a

CC= cc

RM= rm

SRC=	my_putchar.c \
	my_isneg.c \
	my_put_nbr.c \
	my_swap.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	my_sort_int_tab.c \
	my_power_rec.c \
	my_square_root.c \
	my_is_prime.c \
	my_find_prime_sup.c \
	my_strcpy.c \
	my_strncpy.c \
	my_revstr.c \
	my_strstr.c \
	my_strcmp.c \
	my_strncmp.c \
	my_strupcase.c \
	my_strlowcase.c \
	my_strcapitalize.c \
	my_str_isalpha.c \
	my_str_isnum.c \
	my_str_islower.c \
	my_str_isupper.c \
	my_str_isprintable.c \
	my_strcat.c \
	my_strncat.c \
	my_strlcat.c \
	my_printf.c \
        find_intab.c \
        opt_d.c \
        opt_s.c \
        opt_c.c \
        opt_x.c \
        opt_X.c \
	opt_o.c \
        opt_b.c \
	opt_S.c \
        opt_u.c \
        opt_less.c \
        opt_mod.c \
        opt_p.c \
        my_putnbrul_base.c \
        init_tab_fun.c \
	my_free_tab.c \
	add_char_to_begin.c


OBJ= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		$(RM) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:		clean all