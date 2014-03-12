/*
** exec_count_child.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 09:58:05 2012 ronan guiho
** Last update Mon Apr 23 17:42:33 2012 harold ozouf
*/

#include <stdlib.h>
#include "tree.h"

int		exec_count_child(t_child *child_node)
{
  int		i;
  t_child	*child_tmp;

  i = 0;
  child_tmp = child_node;
  while (child_tmp)
    {
      i++;
      child_tmp = child_tmp->next;
    }
  return (i);
}
