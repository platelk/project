/*
** add_child.c for add_child in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 21:37:13 2012 harold ozouf
** Last update Sat Apr 14 23:16:10 2012 harold ozouf
*/

#include	<string.h>
#include	<stdlib.h>
#include	"tree.h"

void	add_child(t_node **root)
{
  t_child	*new;

  new = malloc(sizeof(*new));
  new->nd = NULL;
  new->next = (*root)->child;
  (*root)->child = new;
}

void	add_node(t_node **new, t_t_list id, char *content)
{
  *new = malloc(sizeof(**new));
  (*new)->id = id;
  if (content)
    (*new)->content = strdup(content);
  (*new)->child = NULL;
}
