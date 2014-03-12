/*
** exec_convert.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr 11 18:28:44 2012 ronan guiho
** Last update Fri May 18 12:45:29 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "sh.h"
#include "tree.h"
#include "globing.h"
#include "execute.h"

#define MASTER_NODE	1

int		exec_convert_fill(t_global *global, t_child *child_node, \
				  char **tab, int i)
{
  if ((child_node->nd->content) != NULL)
    {
      if (child_node->nd->content[0] != '$')
	{
	  if ((tab[i++] = my_strdup(child_node->nd->content)) == NULL)
	    return (-1);
	}
      else
	if ((tab[i++] = get_cmd_in_list(creat_list_token(child_node->nd->\
							 content, \
							 global, 1))) == NULL)
	  return (-1);
    }
  return (i);
}

char		**exec_convert(t_node *master_node, t_global *global)
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
      if ((i = exec_convert_fill(global, child_node, tab, i)) == -1)
	return (NULL);
      child_node = child_node->next;
    }
  tab[i] = NULL;
  return (tab);
}
