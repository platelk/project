/*
** obj_create_sun_nn.c for obj_create_sun_nn in /home/jordan/Projets/debug_rt/rt/src/obj
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 11:25:01 2012 jordan vanwalleghem
** Last update Sat Jun  2 15:02:00 2012 jordan vanwalleghem
*/

#include        <stdlib.h>

#include        "object.h"
#include        "obj_create.h"
#include        "xml_tree.h"
#include        "xml_chr.h"
#include        "my.h"

void    *obj_create_cyl(t_xtree *tree)
{
  t_cylindre    *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius", 0);
  if (tmp)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  return (new);
}

void    *obj_create_sph(t_xtree *tree)
{
  t_sphere      *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius", 0);
  if (tmp)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  return (new);
}

void    *obj_create_paraboloide(t_xtree *tree)
{
  t_paraboloide *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius", 0);
  if (tmp)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  return (new);
}

void    *obj_create_hyperboloide(t_xtree *tree)
{
  t_hyperboloide        *new;
  t_xtree       *tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "constante", 0);
  if (tmp)
    {
      new->a = my_getdouble(xml_find_attr(tmp->attr, "A"));
      new->b = my_getdouble(xml_find_attr(tmp->attr, "B"));
      new->c = my_getdouble(xml_find_attr(tmp->attr, "C"));
    }
  else
    {
      new->a = 0.0F;
      new->b = 0.0F;
      new->c = 0.0F;
    }
  return (new);
}
