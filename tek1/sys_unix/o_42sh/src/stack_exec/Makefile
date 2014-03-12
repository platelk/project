##
## Makefile for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Wed Apr 11 16:13:20 2012 ronan guiho
## Last update Thu Apr 19 10:48:34 2012 ronan guiho
##

NAME	=	libexec.a
NAMET	=	test

DEF_RM	=	rm -f

SRC	=	./src/exec_convert.c \
		./src/exec_count_child.c \
		./src/exec_command.c \
		./src/exec_create_tabenv_var.c \
		./src/exec_check_slash.c \
		./src/exec_write_fd.c \
		./src/exec_course_tree.c \
		./src/exec_course_branch.c \
		./src/pipe/exec_pipe.c \
		./src/pipe/exec_pipe_count.c \
		./src/pipe/exec_pipe_current.c \
		./src/redirection/exec_redirection.c \
		./src/redirection/exec_redirection_double_left.c \

OBJ	=	$(SRC:.c=.o)

SRCT	=	./unit_test/main.c \
		$(SRC) \
		../env/src/env.c \
		../env/src/search_env.c \
		../env/src/export_env.c \
		../parsing/tokenizer.c \
		../parsing/token_funct.c \
		../parsing/token_funct_mult.c \
	        ../parsing/reconstruct_token.c \
	        ../parsing/concat_token.c \
	        ../parsing/retoken_redir.c \
	        ../parsing/token_funct_word.c \
	        ../parsing/my_rev_list.c \
	        ../parsing/check_expression.c \
	        ../parsing/check_log.c \
	        ../parsing/check_grammar_exec.c \
	        ../parsing/check_pipe.c \
	        ../parsing/my_rev_node.c \
	        ../parsing/check_bloc_exec.c \
	        ../parsing/check_cmd.c \
	        ../parsing/add_child.c \
		../parsing/puterror.c \
		../parsing_func.c


OBJT	=	$(SRCT:.c=.o)

CFLAGS	=	-I ../../include
LDFLAGS	=	-L../../lib/ -lmy

all:		$(NAME)

%.o:		%.c
		$(CC) -g -c $^ -o $@ $(CFLAGS) $(LDFLAGS)

test:		$(OBJT)
		make -C ../my/
		gcc -g -o $(NAMET) $(OBJT) $(LDFLAGS)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
		$(DEF_RM) $(OBJ)
fclean:
		$(DEF_RM) $(NAME)

re:		clean all