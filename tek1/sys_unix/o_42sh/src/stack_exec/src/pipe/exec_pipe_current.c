/*
** exec_pipe_current.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr 16 09:36:48 2012 ronan guiho
** Last update Mon Apr 23 11:04:47 2012 kevin platel
*/

#include <stdio.h>
#include <stdlib.h>

#include "pipe.h"
#include "execute.h"

t_node		*exec_pipe_current(t_node *master_node, int current_pipe,
				   int flag)
{
  int		i;
  t_node	*tmp;

  i = 0;
  tmp = master_node;
  while (i < current_pipe)
    {
      tmp = tmp->child->next->nd;
      i++;
    }
  if (flag == INIT)
    return (tmp->child->next->nd);
  return (tmp->child->nd);
}
