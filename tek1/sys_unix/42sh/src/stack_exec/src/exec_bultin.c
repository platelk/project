/*
** exec_bultin.c for exec_stack in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr 23 10:44:44 2012 ronan guiho
** Last update Wed May 16 19:58:08 2012 ronan guiho
*/

#include <stdlib.h>

#include "builtin.h"
#include "global.h"
#include "tree.h"
#include "execute.h"

int	exec_builtin(t_node *node, t_global *global)
{
  char	**tab_command;

  if ((tab_command = exec_convert(node, global)) == NULL)
    return (EXIT_FAILURE);
  if ((builtin_ptr_func(tab_command, global)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_free_tab(tab_command);
  return (EXIT_SUCCESS);
}
