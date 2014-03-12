/*
** add_child.c for add_child in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 21:37:13 2012 harold ozouf
** Last update Fri May 18 15:28:19 2012 harold ozouf
*/

#include	<string.h>
#include	<stdlib.h>
#include	"tree.h"

int	add_child(t_node **root)
{
  t_child	*new;

  if (*root != NULL)
    {
      if ((new = malloc(sizeof(*new))) == NULL)
	return (EXIT_FAILURE);
      new->nd = NULL;
      new->next = (*root)->child;
      (*root)->child = new;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	add_node(t_node **new, t_t_list id, char *content)
{
  *new = NULL;
  if ((*new = malloc(sizeof(**new))) == NULL)
    return (EXIT_FAILURE);
  (*new)->id = id;
  if (content)
    (*new)->content = strdup(content);
  else
    (*new)->content = NULL;
  (*new)->child = NULL;
  return (EXIT_SUCCESS);
}
