/*
** exec_course_tree.c for exec_stack in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr 18 13:49:22 2012 ronan guiho
** Last update Wed May  2 11:46:51 2012 kevin platel
*/

#include <stdlib.h>

#include "sh.h"
#include "env.h"
#include "tree.h"
#include "execute.h"

int		exec_course_tree(t_node *node, t_env *env, t_global *global)
{
  t_child	*tmp;
  int		status;

  tmp = node->child;
  status = EXIT_SUCCESS;
  while (tmp)
    {
      if ((status = exec_course_branch(tmp->nd, env, global)) == EXIT_CHILD)
	return (EXIT_CHILD);
      tmp = tmp->next;
    }
  return (status);
}
