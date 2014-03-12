/*
** obj_create_limit.c for limit in /home/vink/projet/graph/rt/inc
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Fri May 11 15:58:00 2012 kevin platel
** Last update Mon May 14 13:12:20 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"xml_attr.h"
#include	"xml_chr.h"
#include	"xml_tree.h"
#include	"global.h"
#include	"my.h"
#include	"limit.h"

t_limit	*obj_limit_x(t_limit *new, t_xtree *tree)
{
  char		*attr;
  t_xtree	*tmp;

  tmp = xml_find_in_tree(tree, "x");
  if (tmp != NULL)
    {
      attr = xml_find_attr(tmp->attr, "MIN");
      if (attr != NULL && (new->flag |= MIN_X))
	new->x[MIN] = my_getdouble(attr);
      attr = xml_find_attr(tmp->attr, "MAX");
      if (attr != NULL && (new->flag |= (MAX_X)))
	new->x[MAX] = my_getdouble(attr);
    }
  return (new);
}

t_limit	*obj_limit_y(t_limit *new, t_xtree *tree)
{
  char		*attr;
  t_xtree	*tmp;

  tmp = xml_find_in_tree(tree, "y");
  if (tmp != NULL)
    {
      attr = xml_find_attr(tmp->attr, "MIN");
      if (attr != NULL && (new->flag |= MIN_Y))
	new->y[0] = my_getdouble(attr);
      attr = xml_find_attr(tmp->attr, "MAX");
      if (attr != NULL && (new->flag |= (MAX_Y)))
	new->y[1] = my_getdouble(attr);
    }
  return (new);
}

t_limit	*obj_limit_z(t_limit *new, t_xtree *tree)
{
  char		*attr;
  t_xtree	*tmp;

  tmp = xml_find_in_tree(tree, "z");
  if (tmp != NULL)
    {
      attr = xml_find_attr(tmp->attr, "MIN");
      if (attr != NULL && (new->flag |= MIN_Z))
	new->z[MIN] = my_getdouble(attr);
      attr = xml_find_attr(tmp->attr, "MAX");
      if (attr != NULL && (new->flag |= (MAX_Z)))
	new->z[MAX] = my_getdouble(attr);
    }
  return (new);
}

t_limit	*obj_create_limit(t_xtree *tree)
{
  t_limit	*new;

  tree = xml_find_in_tree(tree, "limit");
  if (tree == NULL)
    return (NULL);
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  new = obj_limit_x(new, tree);
  new = obj_limit_y(new, tree);
  new = obj_limit_z(new, tree);
  return (new);
}
