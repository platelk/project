/*
** obj_create_sun_n.c for obj_create_sun_n in /home/jordan/Projets/debug_rt/rt/src/obj
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 11:23:44 2012 jordan vanwalleghem
** Last update Sat Jun  2 15:01:22 2012 jordan vanwalleghem
*/

#include        <stdlib.h>

#include        "object.h"
#include        "obj_create.h"
#include        "xml_tree.h"
#include        "xml_chr.h"
#include        "my.h"

void            *obj_create_pla(t_xtree *tree)
{
  t_plan        *new;

  tree = tree;
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  return (new);
}

void            *obj_create_cube(t_xtree *tree)
{
  t_xtree       *tmp;
  t_cube        *new;

  tree = tree;
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "size", 0);
  if (tmp != NULL)
    new->size = my_getdouble(tmp->content);
  else
    new->size = 0.0F;
  return (new);
}

void            *obj_create_tore(t_xtree *tree)
{
  t_tore        *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius", 0);
  if (tmp != NULL)
    {
      new->radius[0] = my_getdouble(xml_find_attr(tmp->attr, "MIN"));
      new->radius[1] = my_getdouble(xml_find_attr(tmp->attr, "MAX"));
    }
  else
    {
      new->radius[0] = 0.0F;
      new->radius[1] = 0.0F;
    }
  return (new);
}

void            *obj_create_cubetroue(t_xtree *tree)
{
  t_cubetroue   *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius", 0);
  if (tmp != NULL)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  tmp = xml_find_in_tree(tree, "size", 0);
  if (tmp != NULL)
    new->size = my_getdouble(tmp->content);
  else
    new->size = 0.0F;
  return (new);
}

void            *obj_create_con(t_xtree *tree)
{
  t_cone        *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius", 0);
  if (tmp)
    new->angle = my_getdouble(tmp->content);
  else
    new->angle = 0.0F;
  return (new);
}
