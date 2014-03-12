/*
** execute.h for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/unit_test
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Apr 14 22:32:53 2012 ronan guiho
** Last update Sat May 19 19:37:34 2012 kevin platel
*/

#ifndef	__EXECUTE_H__
#define __EXECUTE_H__

#include "my.h"
#include "tree.h"
#include "token.h"
#include "global.h"

void		start_signal();
int		exec_course_father(t_global *, int);
int		exec_course_branch_select(t_node *, t_global *);
char		*exec_command_pathvar_none(char **);
int		exec_course_son(t_node *, t_global *, int);
int		exec_pipe_cascada_fath(t_node *, t_global *,
				       int **, int);
int		exec_course_branch_other_dolar(t_node *, t_env *,
					       t_global *);
int		exec_pipe_mono(t_node *, t_global *);
int		exec_pipe(t_node *, t_global *);
int		exec_course_tree(t_node *, t_env *, t_global *);
int		exec_pipe_count(t_node *);
int		exec_check_slash(char *);
char		**exec_convert(t_node *, t_global *);
int		exec_count_child(t_child *);
int		exec_command(t_node *, t_env *, t_global *);
int		exec_redirection(t_node *, t_global *,
				 enum e_token);
int		exec_course_branch(t_node *, t_env *, t_global *);
int		exec_write_fd(char *, int);
char		**exec_create_tabvar_env(t_env *, char *,
					 char *);
t_node		*exec_pipe_current(t_node *, int,
				   int);
int		exec_redirection_double_left(t_node  *, \
					     t_global *, int);
int		exec_builtin(t_node *, t_global *);
int		exec_signal(int);
int		exec_select_execution(t_node *, t_global *);

#endif
