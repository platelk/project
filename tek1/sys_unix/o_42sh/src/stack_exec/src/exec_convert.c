/*
** exec_convert.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr 11 18:28:44 2012 ronan guiho
** Last update Mon Apr 23 17:42:26 2012 harold ozouf
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "execute.h"

#define MASTER_NODE	1

char		**exec_convert(t_node *master_node)
{
  int		i;
  char		**tab;
  t_child	*child_node;
  int		count_child;

  i = 0;
  child_node = master_node->child;
  count_child = exec_count_child(master_node->child);
  if ((tab = malloc(sizeof(char *) * (count_child + MASTER_NODE + 1))) == NULL)
    return (NULL);
  if ((tab[i++] = my_strdup(master_node->content)) == NULL)
    return (NULL);
  while (child_node)
    {
      if ((tab[i++] = my_strdup(child_node->nd->content)) == NULL)
	return (NULL);
      child_node = child_node->next;
    }
  tab[i] = NULL;
  return (tab);
}
