/*
** node.c for node in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Feb 14 10:50:15 2012 harold ozouf
** Last update Tue May  1 09:15:18 2012 kevin platel
*/

#include	<stdlib.h>
#include	"str.h"
#include	"xfnt.h"
#include	"node.h"

void	add_node(t_node **root, char *name, char *content)
{
  t_child	*new;

  new = xmalloc(sizeof(*new));
  new->child = xmalloc(sizeof(*(new->child)));
  new->child->prev = xmalloc(sizeof(*(new->child->prev)));
  new->child->content = my_strdup(content);
  new->child->name = my_strdup(name);
  new->child->prev = *root;
  new->child->elm = NULL;
  if (*root == NULL)
    (*root) = new->child;
  else
    {
      if ((*root)->elm == NULL)
	(*root)->elm = new;
      else
	{
	  new->next = (*root)->elm;
	  (*root)->elm = new;
	}
    }
}
