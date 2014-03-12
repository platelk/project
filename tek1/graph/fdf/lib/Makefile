##
## Makefile for Makefile in /home/platel_k//projet/piscine/Jour_11
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Mon Oct 24 08:56:33 2011 kevin platel
## Last update Sun Feb  5 14:24:18 2012 kevin platel
##

LINK=	c/

SRC	= $(LINK)convert_base.c \
	  $(LINK)my_factorielle_rec.c \
	  $(LINK)my_find_prime_sup.c \
	  $(LINK)my_getnbr.c \
	  $(LINK)my_is_prime.c \
	  $(LINK)my_power_rec.c \
	  $(LINK)my_putchar.c \
	  $(LINK)my_putnbr_base.c \
	  $(LINK)my_put_nbr.c \
	  $(LINK)my_putstr.c \
	  $(LINK)my_revstr.c \
	  $(LINK)my_show_wordtab.c \
	  $(LINK)my_sort_int_tab.c \
	  $(LINK)my_sort_params.c \
	  $(LINK)my_square_root.c \
	  $(LINK)my_strcapitalize.c \
	  $(LINK)my_strcat.c \
	  $(LINK)my_strcmp.c \
	  $(LINK)my_strcpy.c \
	  $(LINK)my_strdup.c \
	  $(LINK)my_str_isalpha.c \
	  $(LINK)my_str_islower.c \
	  $(LINK)my_str_isnum.c \
	  $(LINK)my_str_isprintable.c \
	  $(LINK)my_str_isupper.c \
	  $(LINK)my_strlcat.c \
	  $(LINK)my_strlen.c \
	  $(LINK)my_strlowcase.c \
	  $(LINK)my_strncat.c \
	  $(LINK)my_strncmp.c \
	  $(LINK)my_strncpy.c \
	  $(LINK)my_strstr.c \
	  $(LINK)my_str_to_wordtab.c \
	  $(LINK)my_strupcase.c \
	  $(LINK)my_swap.c \
	  $(LINK)my_printf.c \
          $(LINK)find_intab.c \
	  $(LINK)opt_d.c \
          $(LINK)opt_s.c \
	  $(LINK)opt_c.c \
          $(LINK)opt_x.c \
	  $(LINK)opt_X.c \
          $(LINK)opt_o.c \
          $(LINK)opt_b.c \
          $(LINK)opt_S.c \
	  $(LINK)opt_u.c \
	  $(LINK)opt_less.c \
          $(LINK)opt_mod.c \
          $(LINK)opt_p.c \
	  $(LINK)my_putnbrul_base.c \
	  $(LINK)init_tab_fun.c \
	  $(LINK)isnum.c \
	  $(LINK)isalpha.c \
	  $(LINK)my_strtok.c \
	  $(LINK)my_strmcat.c

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

RM	= rm -f

HEAD	= my.h

CFLAGS	= -W -Wall -Wextra -ansi

all:	$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -I include -W -Wall -Wextra -g

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all