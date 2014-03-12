/*
** free_child.c for free_child in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May 12 14:52:06 2012 harold ozouf
** Last update Wed May 16 17:52:12 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"tree.h"

void	free_node(t_node *nd)
{
  t_child	*tmp;

  if (nd)
    {
      if (nd->content)
	free(nd->content);
      while (nd->child)
	{
	  tmp = nd->child;
	  if (tmp->nd)
	    free_node(tmp->nd);
	  nd->child = nd->child->next;
	  if (tmp)
	    free(tmp);
	}
      free(nd);
      nd = NULL;
    }
}

void	free_token(t_token *t)
{
  t_token *tmp;

  while (t)
    {
      tmp = t;
      if (t->content)
	free(t->content);
      t = t->next;
      free(tmp);
    }
}
