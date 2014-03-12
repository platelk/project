##
## Makefile for maker in /home/ozouf_h//projet/rtv1/srcs
## 
## Made by harold ozouf
## Login   <ozouf_h@epitech.net>
## 
## Started on  Thu Feb  2 12:18:08 2012 harold ozouf
## Last update Tue May  8 19:45:37 2012 harold ozouf
##

NAME	= libpars.a
NAME_T	= test

SRCS 	= tokenizer.c \
          token_funct.c \
          token_funct_mult.c \
          multired.c \
          retoken_redir_par.c \
          reconstruct_token.c \
          concat_token.c \
          retoken_redir.c \
          token_funct_word.c \
          my_rev_list.c \
          my_rev_node.c \
          check_expression.c \
          check_log.c \
          check_bloc_exec.c \
          check_grammar_exec.c \
          check_pipe.c \
          check_cmd.c \
          add_child.c \
          aff_tree.c \
	  puterror.c

OBJ	= $(SRCS:.c=.o)

DEBUG	= no

CFLAGS 	= -Wall -Wextra -I./../../include/

ifeq ($(DEBUG),yes)
	CFLAGS	+= -g
endif

all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

test:	all
	gcc -I./../../include -o $(NAME_T) main.c -L./ -lpars $(CFLAGS)