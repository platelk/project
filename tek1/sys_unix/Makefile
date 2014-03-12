##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##

NAME		=	42sh

CC		=	gcc

LINK		=	src
LINK_LIB	=	src/my/

ENV		=	yes
PARS		=	yes
GLOB		=	yes
HIST		=	yes
EXEC		=	yes
BUILT		=	yes

DEBUG		=	yes

LIB		=	-L $(LINK_LIB) -lmy

SRC		=	$(LINK)/env/$(LINK)/env.c \
			$(LINK)/env/$(LINK)/search_env.c \
			$(LINK)/env/$(LINK)/export_env.c \

SRC		+=	src/parsing/token_funct.c \
			src/parsing/retoken_redir.c \
			src/parsing/concat_token.c \
			src/parsing/check_cmd.c \
			src/parsing/check_pipe.c \
			src/parsing/my_rev_node.c \
			src/parsing/tokenizer.c \
			src/parsing/token_funct_mult.c \
			src/parsing/check_log.c \
			src/parsing/check_bloc_exec.c \
			src/parsing/token_funct_word.c \
			src/parsing/reconstruct_token.c \
			src/parsing/puterror.c \
			src/parsing/check_grammar_exec.c \
			src/parsing/add_child.c \
			src/parsing/my_rev_list.c \
			src/parsing/check_expression.c \

SRC		+=	$(LINK)/globing/globing/globing.c \
			$(LINK)/globing/globing/glob_list.c \
			$(LINK)/globing/globing/utils.c \
			$(LINK)/globing/glob_env/globing_env.c \

SRC		+=	$(LINK)/stack_exec/src/exec_convert.c \
			$(LINK)/stack_exec/src/exec_count_child.c \
			$(LINK)/stack_exec/src/exec_command.c \
	                $(LINK)/stack_exec/src/exec_create_tabenv_var.c \
	                $(LINK)/stack_exec/src/exec_check_slash.c \
	                $(LINK)/stack_exec/src/exec_write_fd.c \
	                $(LINK)/stack_exec/src/exec_course_tree.c \
	                $(LINK)/stack_exec/src/exec_course_branch.c \
	                $(LINK)/stack_exec/src/pipe/exec_pipe.c \
	                $(LINK)/stack_exec/src/pipe/exec_pipe_count.c \
	                $(LINK)/stack_exec/src/pipe/exec_pipe_current.c \
	                $(LINK)/stack_exec/src/redirection/exec_redirection.c \
		        $(LINK)/stack_exec/src/redirection/exec_redirection_double_left.c \

SRC		+=	$(LINK)/builtin/$(LINK)/is_builtin.c \
			$(LINK)/builtin/$(LINK)/builtin_ptr_func.c \
			$(LINK)/builtin/$(LINK)/cd/cd.c \
			$(LINK)/builtin/$(LINK)/echo/echo.c \
			$(LINK)/builtin/$(LINK)/setenv/builtin_setenv.c \
			$(LINK)/builtin/$(LINK)/unsetenv/builtin_unsetenv.c \

SRC		+=	$(LINK)/edit/$(LINK)/edit_prompt.c \
			$(LINK)/edit/$(LINK)/edit_cmd.c \

SRC		+=	$(LINK)/config/$(LINK)/config_alias.c \
			$(LINK)/config/$(LINK)/config_func.c \
			$(LINK)/config/$(LINK)/config_env.c \
			$(LINK)/config/$(LINK)/config_globing.c \
			$(LINK)/config/$(LINK)/config_keyword.c \
			$(LINK)/config/$(LINK)/config_parser.c \
			$(LINK)/config/$(LINK)/config_prompt.c \
			$(LINK)/config/$(LINK)/config_history.c \

SRC		+=	$(LINK)/main.c \

SRC		+=	$(LINK)/history/$(LINK)/history_create_ptr_func.c \
			$(LINK)/history/$(LINK)/history_putlist.c \
			$(LINK)/history/$(LINK)/history_subs_func.c \
			$(LINK)/history/$(LINK)/history_substitution.c \

SRC		+=	$(LINK)/history/test_unit/history_showlist.c

SRC		+=	$(LINK)/parsing_func.c \

INCLUDE		=	-I include/

CFLAGS		+=	-Wall -Wextra $(INCLUDE)

ifeq ($(DEBUG),yes)
	CFLAGS += -g
endif

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS) $(LIB) $(INCLUDE)

$(NAME):	$(OBJ)
	make -C src/my
	gcc -o $(NAME) $(OBJ) $(INCLUDE) $(CFLAGS) $(LIB) 

clean:
	make clean -C src/my
	rm -f $(OBJ)

fclean: 	clean
	make fclean -C src/my
	rm -f $(NAME)

re:	fclean all
	make re -C src/my
