/*
** exec_select_execution.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 19 13:25:49 2012 ronan guiho
** Last update Sat May 19 19:18:02 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "sh.h"
#include "tree.h"
#include "execute.h"
#include "builtin.h"

int	exec_select_execution_other(t_node *node, t_global *global)
{
  int	status;
  t_node *tmp;

  if (is_builtin(node->content) != -1)
    {
      if ((exec_builtin(node, global)) == EXIT_FAILURE)
	{
	  global->exit = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
      return (EXIT_CHILD);
    }
  else if (my_strsearch(node->content, '$') == 1)
    {
      if ((tmp = parsing_func(node->content, global, 1)) == NULL)
	return (EXIT_CHILD);
      if ((status = exec_course_tree(tmp, global->env, \
				     global)) >= EXIT_FAILURE)
	return (status);
      return (EXIT_CHILD);
    }
  return (EXIT_SUCCESS);
}
int	exec_select_execution(t_node *node, t_global *global)
{
  int	status;

  if ((status = exec_select_execution_other(node, global)) >= EXIT_FAILURE)
    return (status);
  if (node->id == CMD)
    {
      if ((status = exec_command(node, global->env, global)) >= EXIT_FAILURE)
	return (status);
    }
  else if (node->id == S_RED_RIGHT || node->id == D_RED_RIGHT || \
	   node->id == S_RED_LEFT || node->id == D_RED_LEFT || \
	   node->id == S_RED_RIGHT_ERR || node->id == D_RED_RIGHT_ERR)
    {
      if ((status = exec_redirection(node, global, node->id)) >= EXIT_FAILURE)
	return (status);
    }
  return (EXIT_SUCCESS);
}
