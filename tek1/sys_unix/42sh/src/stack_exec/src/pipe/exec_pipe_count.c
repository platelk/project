/*
** exec_pipe_count.c for exec_stack in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 17:34:59 2012 ronan guiho
** Last update Thu Apr 19 10:37:49 2012 ronan guiho
*/

#include <stdlib.h>

#include "execute.h"

int		exec_pipe_count(t_node *master_node)
{
  t_child	*tmp_child;
  int		i;

  i = 1;
  tmp_child = master_node->child->next;
  while (tmp_child->nd->id == PIPE)
    {
      tmp_child = tmp_child->nd->child->next;
      i++;
    }
  return (i);
}
