/*
** exec_course_branch_other.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 18 12:50:39 2012 ronan guiho
** Last update Fri May 18 12:59:24 2012 ronan guiho
*/

#include <stdlib.h>

#include "sh.h"
#include "builtin.h"
#include "globing.h"
#include "env.h"
#include "global.h"
#include "tree.h"
#include "token.h"
#include "execute.h"

int		exec_course_branch_other_dolar(t_node *root, t_env *env,
					       t_global *global)
{
  t_node	*tmp;
  int		status;

  if ((tmp = parsing_func(root->content, global, 1)) == NULL)
    return (EXIT_FAILURE);
  if (my_strcmp(root->content, globing_env(root->content, env, \
					   global, G_E_WITH_DOL | 16)) != 0)
    if ((status = exec_course_tree(tmp, env, global)) >= EXIT_FAILURE)
      return (status);
  return (EXIT_SUCCESS);
}
