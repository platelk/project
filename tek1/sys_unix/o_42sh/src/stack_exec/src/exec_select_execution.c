/*
** exec_select_execution.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 19 13:25:49 2012 ronan guiho
** Last update Sat Apr 28 16:16:03 2012 ronan guiho
*/

#include <stdlib.h>

#include "sh.h"
#include "tree.h"
#include "execute.h"
#include "builtin.h"

int	exec_select_execution(t_node *node, t_global *global)
{
  int	status;

  if (is_builtin(node->content) != -1)
    {
      if ((exec_builtin(node, global)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_CHILD);
    }
  if (node->id == CMD)
    {
      if ((status = exec_command(node, global->env)) >= EXIT_FAILURE)
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
