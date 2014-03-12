/*
** execute.h for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/unit_test
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Apr 14 22:32:53 2012 ronan guiho
** Last update Sat Apr 28 16:14:42 2012 ronan guiho
*/

#ifndef	__EXECUTE_H__
#define __EXECUTE_H__

#include "my.h"
#include "tree.h"
#include "token.h"
#include "global.h"

int		exec_pipe(t_node *master_node, t_global *global);
int		exec_course_tree(t_node *node, t_env *env, t_global *global);
int		exec_pipe_count(t_node *master_node);
int		exec_check_slash(char *cmd);
char		**exec_convert(t_node *master_node);
int		exec_count_child(t_child *child_node);
int		exec_command(t_node *master_node, t_env *env);
int		exec_redirection(t_node *master_node, t_global *global,
				 enum e_token flag);
int		exec_course_branch(t_node *root, t_env *env, t_global *global);
int		exec_write_fd(char *buffer, int fd);
char		**exec_create_tabvar_env(t_env *env, char *var,
					 char *delim);
t_node		*exec_pipe_current(t_node *master_node, int current_pipe,
				   int flag);
int		exec_redirection_double_left(t_node  *master_node, t_env *env);
int	exec_builtin(t_node *node, t_global *global);
int	exec_signal(int signal);
int	exec_select_execution(t_node *node, t_global *global);

#endif
