##
## makefile for tp1
##
## Made by matthieu przybylski
## Login   <przyby_m@epitech.net>
##
## Started on  Wed Nov  9 12:52:45 2011 matthieu przybylski
## Last update Thu Nov 10 09:16:21 2011 matthieu przybylski
##

CC      = gcc

RM      = rm -f

NAME    = ./calc

LINK	= ./source/

OBJ	= $(SRC:.c=.o)

SRC   	= $(LINK)add_before_list.c \
	  $(LINK)add_in_list.c \
	  $(LINK)add_one_in_list.c \
	  $(LINK)calc_sub.c \
	  $(LINK)check_op.c \
	  $(LINK)check_par.c \
	  $(LINK)decrypt.c \
	  $(LINK)del_in_list.c \
	  $(LINK)del_one_in_list.c \
	  $(LINK)del_par.c \
	  $(LINK)del_useless_par.c \
	  $(LINK)eval_expr.c \
	  $(LINK)function.c \
	  $(LINK)init_list.c \
	  $(LINK)int_to_list.c \
	  $(LINK)is_empty.c \
	  $(LINK)isnum.c \
	  $(LINK)isop.c \
	  $(LINK)list_cmp.c \
	  $(LINK)list_cpy.c \
	  $(LINK)list_to_int.c \
	  $(LINK)my_char_base.c \
	  $(LINK)my_list_size.c \
	  $(LINK)my_show_list.c \
	  $(LINK)remaining_op.c \
	  $(LINK)replace.c \
	  $(LINK)signe_mult.c \
	  $(LINK)tab_to_list.c \
	  $(LINK)take_nb.c \
	  $(LINK)val_expr.c \
	  $(LINK)get_calc.c \
	  $(LINK)list_to_tab.c \
	  $(LINK)main.c \
	  $(LINK)concat.c \
	  $(LINK)del_us_zero.c \
	  $(LINK)go_to_end.c \
	  $(LINK)calc_mult.c \
	  $(LINK)calc_divi.c \
	  $(LINK)define_r.c \
	  $(LINK)no_double.c

LIB     = -L./lib/ -lmy

CFLAGS = -I ./include -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	 @$(CC) -o $(NAME) $(OBJ) $(LIB)
	 @echo "Make : succes"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
